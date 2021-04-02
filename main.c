// 
// Copyright 2017 Robson Couto
// Copyright 2021 Erich Heinzle
//
// Licence GPL v2 
//

#define F_CPU 8000000UL
#define MAX_OBSTACLES 3

#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "logo.h"
#include "obstacle_sprites.h"
#include "runner_sprites.h"
#include "hardware.h"
#include "ST7565-T3/c/stlcd.h"
#include "ST7565-T3/c/glcd.h"

//This is the buffer used to transfer data to the LCD
uint8_t buffer[128*64/8];

typedef struct {
  uint8_t is_jumping;
  uint8_t x;
  uint8_t y;
  uint8_t w;
  uint8_t h;
  const uint8_t* sprite;
  uint8_t steps;
  uint8_t has_changed;
} runner_t;

typedef struct {
  uint8_t x;
  uint8_t y;
  uint8_t w;
  uint8_t h;
  const uint8_t* sprite;
  uint8_t alive;
} obstacle_t;

struct ground {
  uint8_t x;
  int8_t y;
  uint8_t w;
  uint8_t h;
  const uint8_t* sprite;
};

//Points used for the runner jump
const char points[]={38,31,28,25,23,22,20,19,18,17,16,15,14,14,13,12,12,11,11,10,10,10,9,9,9,8,8,8,8,8,8};

void draw_ground(void) {
  static uint16_t i=0; // and then the one byte variable said... roll over... roll over...
  int ground_width = 512;
  if (i < (ground_width - 128)) {
    drawbitmap(buffer, 0, 56, gnd + i, 128, 8, 1);
  } else {
    drawbitmap(buffer, 0, 56, gnd+i, ground_width-i, 8, 1);
    drawbitmap(buffer, ground_width-i, 56, gnd, 128-(ground_width-i), 8, 1);
  }
  i++;
  if (i==ground_width) i=0;
}

void update_ground(void) {
    draw_ground();//draw ground to buffer
    write_part(buffer,0,56,128,8);//draw gnd from buffer to LCD
}

uint8_t draw_obstacle(obstacle_t* obstacle, uint8_t color) {
  return drawbitmap2(buffer, obstacle->x, obstacle->y, obstacle->sprite, obstacle->w, obstacle->h, color);
}

uint8_t draw_runner(runner_t* runner, uint8_t color) {
  return drawbitmap2(buffer, runner->x, runner->y, runner->sprite, 20, 24, color);
}

void runner_to_screen(runner_t* runner, uint8_t color) {
  draw_runner(runner,color);
  write_part(buffer,runner->x,runner->y,runner->w,runner->h);
}

void update_jump(runner_t* runner){
  static uint8_t index=0;
  if (runner->is_jumping){
    if (runner->is_jumping>31){
      if (points[index]!=runner->y){
        runner->has_changed=1;
        runner_to_screen(runner, 0);
      }
      runner->y=points[index];
      runner->is_jumping--;
      index++;
    } else {
      index--;
      if (points[index]!=runner->y){
        runner->has_changed=1;
        runner_to_screen(runner, 0);
      }
      runner->y=points[index];
      runner->is_jumping--;
      if (runner->is_jumping==0) {
	runner->y=40;
	runner->has_changed=1;
	runner->steps=0xFF; // trigger sprite change on subsequent update_walk
      }
    }
  } else {
    runner->y=40;
  }
}

void update_walk(runner_t* runner) {
  if (!(runner->is_jumping)) {
    runner->steps++;
    if (!((runner->steps)%4)) {
      if (runner->sprite==runner1) {
	runner->sprite=runner2;
        runner->has_changed=1;
        runner_to_screen(runner, 0);
      } else if (runner->sprite==runner2) {
        runner->sprite=runner3;
        runner->has_changed=1;
        runner_to_screen(runner, 0); 
      } else {
	runner->sprite=runner1;
        runner->has_changed=1;
        runner_to_screen(runner, 0);
      }
    }
  }
}

void create_obstacle(obstacle_t* obstacle, const uint8_t **obstacles_small, const uint8_t **obstacles_big) {
  obstacle->x=127;// Fixed (It cant be more than 127)
  obstacle->alive=0xFF;
  if (get_rand(2)%2==0) {//gets the type of the obstacle(big or small)
    obstacle->y=48;
    obstacle->w=8;
    obstacle->h=16;
    obstacle->sprite=obstacles_small[get_rand(5)];
  } else {
    obstacle->y=40;
    obstacle->w=12;
    obstacle->h=24;
    obstacle->sprite=obstacles_big[get_rand(5)];
  }
}

void create_runner(runner_t *runner) {
  runner->x = 20;
  runner->y = 40;
  runner->w = 20;
  runner->h = 24;
  runner->sprite=runner1;
  runner->is_jumping=0;
  runner->steps=0;
  runner->has_changed=1;
}

void update_runner(runner_t *runner) {
  if (runner->has_changed) {
    write_part(buffer,runner->x,runner->y,runner->w,runner->h);
    runner->has_changed = 0;
  }
}

void draw_score(uint16_t score) {
  char s[5];
  itoa(score,s,10);
  int offset;
  int char_width = 6;
  if (score < 10) { // could use log_10
    offset = 0;
  } else if (score < 100) {
    offset = 1;
  } else if (score < 1000) {
    offset = 2;
  } else {
    offset = 3;
  }
  drawstring(buffer, 118 - offset*char_width, 0, s);
  write_part(buffer, 118 - offset*char_width, 0, 22, 8);
}

void init_highscore(uint16_t *highscore) {
  *highscore=get_score();
  if (*highscore == 0xFFFF) {
    *highscore = 0;
  }
}

void draw_highscore(uint16_t high) {
  char s[5];
  itoa(high,s,10);
  drawstring(buffer, 86, 0,s);
  write_part(buffer,86,0,22,8);
}

void draw_flash_screen(void) {
  clear_screen();
  clear_buffer(buffer);
  drawstring(buffer,10,2,"LOBETHAL");
  drawstring(buffer,10,3,"LUTHERAN");
  drawstring(buffer,10,4," SCHOOL ");
  drawstring(buffer,2,6,"RUNNER GAME");
  drawbitmap(buffer, 64, 0, logo, 64, 64, 1);
  write_part(buffer,1,0,128,64);
  _delay_ms(700);
  clear_screen();
  clear_buffer(buffer);
}

void reset_obstacle(obstacle_t *obstacle) {
  obstacle->alive=0;
}

void reset_obstacles(obstacle_t *obstacles) {
  for (int j=0;j<MAX_OBSTACLES;j++) {
    reset_obstacle(&obstacles[j]);
  }
}

void erase_obstacles(obstacle_t *obstacles) { //Erase obstacles from LCD screen
  for (int j=0; j<MAX_OBSTACLES; j++) {
    if (obstacles[j].alive) {
      draw_obstacle(&obstacles[j],0);
      write_part(buffer,obstacles[j].x,obstacles[j].y,obstacles[j].w,obstacles[j].h);
    }
  }
}

void init_obstacle_sprites(const uint8_t **small, const uint8_t **big) {
  //Initialise the arrays that keep the sprite addresses
  //One of these values is randomly chosen at obstacle creation
  small[0]=cacts1;
  small[1]=cacts2;
  small[2]=cacts3;
  small[3]=cacts4;
  small[4]=cacts5;
  small[5]=cacts6;

  big[0]=cactusb1;
  big[1]=cactusb2;
  big[2]=cactusb3;
  big[3]=cactusb4;
  big[4]=cactusb5;
  big[5]=cactusb6;
}

int collision_detection_and_draw(obstacle_t *obstacles, uint16_t *score, uint8_t *n_of_obstacles) {
    //Draw obstacle to the buffer, check collision, and write to LCD
    int bump = 0;
    for (int j=0;j<MAX_OBSTACLES;j++) {
      if (obstacles[j].alive) {
        if (obstacles[j].x<1) {
          reset_obstacle(&obstacles[j]);
          (*score)++;
          (*n_of_obstacles)--;
          draw_obstacle(&obstacles[j],0);
          draw_score(*score);//The score is only drawn to the LCD when changed
        } else {
          obstacles[j].x--;
          bump|=draw_obstacle(&obstacles[j],1);//draw obstacle to buffer and detect possible collision
        }
        write_part(buffer,obstacles[j].x,obstacles[j].y,obstacles[j].w,obstacles[j].h);//draw obstacle to LCD
      }
    }
    return bump;
}

void spawn_obstacle_routine(obstacle_t *obstacles, const uint8_t **obstacles_small,
                 const uint8_t **obstacles_big, uint8_t *tail, uint8_t *n_of_obstacles,
                 uint8_t *frames_to_next_obstacle) {
  if ((!obstacles[*tail].alive)&(*frames_to_next_obstacle==0)) {
    if (get_rand(16)==0) {//"1 in 16 chance" No, I know
      //If the previous conditions are met, create a new obstacle and delay creation of new obstacle
      create_obstacle(&obstacles[*tail], obstacles_small, obstacles_big);
      (*tail)++;
      (*n_of_obstacles)++;
      *frames_to_next_obstacle=60;//can be changed
    }
  }
  if (*tail==MAX_OBSTACLES) {
    *tail=0;
  }
}

void finish_game(uint16_t score, uint16_t highscore) {
  drawstring(buffer,16,2,"G A M E  O V E R");
  write_part(buffer,16,16,100,8);
  if (score>highscore) update_score(score); //writes new score to EEPROM`
  while (1) {
    if (button_pressed()) {
      reset();//see hardware.c for implementation
    }
  }
}

int main(void) {

  const uint8_t* obstacles_small[6];
  const uint8_t* obstacles_big[6];
  int button_sense = 0;
  uint8_t n_of_obstacles = 0; //current number of obstacles on screen
  uint8_t tail = 0;//the position of the new obstacle on the ring
  uint8_t frames_to_next_obstacle = 0; //frames until next obstacle created = delay/space for runner to land
  uint16_t highscore = 0;
  uint16_t score = 0;
  uint8_t bump = 0; //collision between runner and obstacle kept here

  runner_t runner;
  obstacle_t obstacles[MAX_OBSTACLES];
  create_runner(&runner);
  reset_obstacles(obstacles);
  init_obstacle_sprites(obstacles_small, obstacles_big);
  init_hardware(); //low level atmega stuff (PORTS, ADC, etc)
  init_highscore(&highscore);

  draw_flash_screen();
  draw_highscore(highscore);//only time this is written to the screen
  draw_score(score);

  while (1) {
    bump = 0;
    button_sense = button_pressed();
    _delay_us(500);
    button_sense |= button_pressed();
    _delay_us(500); // simple attempt to debounce
    clear_buffer(buffer);//The memory is cleared, but not the LCD
    if ((button_sense || button_pressed()) && !(runner.is_jumping)) {
      runner.is_jumping=2*sizeof(points);//The array points has the positions for the jump (2x because is back an forth )
    }
    update_walk(&runner); //Updates runner sprite (which leg touches the ground)
    update_jump(&runner); //Update the runner position
    draw_runner(&runner,1);

    if (n_of_obstacles <= MAX_OBSTACLES) { //Checks if there are MAX_OBSTACLES obstacles on screen already
      spawn_obstacle_routine(obstacles, obstacles_small, obstacles_big, &tail, &n_of_obstacles, &frames_to_next_obstacle);
    }

    update_runner(&runner);

    bump = collision_detection_and_draw(obstacles, &score, &n_of_obstacles);

    update_ground();

    _delay_ms(2); //was 3 FIXME needs a interrupt/timer scheme to keep fixed fps

    if (bump) finish_game(score, highscore);
    if (frames_to_next_obstacle) frames_to_next_obstacle--;//Each frame decreases delay for new obstacle
    erase_obstacles(obstacles);
  }
}
