// 
// Copyright 2017 Robson Couto
// Copyright 2021,2022 Erich Heinzle
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

typedef struct {
  const uint8_t *obstacles_small[6];
  const uint8_t *obstacles_big[6];
  uint8_t tail;
  uint8_t n_of_obstacles;
  uint8_t frames_to_next_obstacle;
  uint16_t score;
} obstacle_ctx_t;

typedef struct {
  uint8_t x;
  int8_t y;
  uint16_t w;
  uint8_t h;
  const uint8_t* sprite;
} ground_sprite_t;

void draw_ground(ground_sprite_t *ground, uint8_t *buffer) {
  static uint16_t i = 0; // and then the one byte variable said... roll over... roll over...
  if (i < (ground->w - LCDWIDTH)) {
    drawbitmap(buffer, ground->x, ground->y, GND_SPRITE + i, LCDWIDTH, ground->h, 1);
  } else {
    drawbitmap(buffer, ground->x, ground->y, GND_SPRITE+i, ground->w-i, ground->h, 1);
    drawbitmap(buffer, ground->w-i, ground->y, GND_SPRITE, LCDWIDTH-(ground->w-i), ground->h, 1);
  }
  i++;
  if (i == ground->w) i=0;
}

void update_ground(ground_sprite_t *ground, uint8_t *buffer) {
    draw_ground(ground, buffer);//draw ground to buffer
    write_part(buffer, ground->x, ground->y,LCDWIDTH, ground->h);//draw gnd from buffer to LCD
}

void init_gnd(ground_sprite_t *ground) {
  ground->x = 0;
  ground->y = LCDHEIGHT - GND_GLCD_HEIGHT;
  ground->w = GND_GLCD_WIDTH;
  ground->h = GND_GLCD_HEIGHT;
  ground->sprite = GND_SPRITE;
}

uint8_t draw_obstacle(obstacle_t* obstacle, uint8_t color, uint8_t *buffer) {
  return drawbitmap2(buffer, obstacle->x, obstacle->y, obstacle->sprite, obstacle->w, obstacle->h, color);
}

uint8_t draw_runner(runner_t* runner, uint8_t color, uint8_t *buffer) {
  return drawbitmap2(buffer, runner->x, runner->y, runner->sprite, RUNNER1_GLCD_WIDTH, RUNNER1_GLCD_HEIGHT, color);
}

void runner_to_screen(runner_t* runner, uint8_t color, uint8_t *buffer) {
  draw_runner(runner, color, buffer);
  write_part(buffer,runner->x,runner->y,runner->w,runner->h);
}

void update_jump(runner_t* runner, const char *points, uint8_t *buffer){
  static uint8_t index=0;
  if (runner->is_jumping){
    if (runner->is_jumping>31){
      if (points[index]!=runner->y){
        runner->has_changed=1;
        runner_to_screen(runner, 0, buffer);
      }
      runner->y=points[index];
      runner->is_jumping--;
      index++;
    } else {
      index--;
      if (points[index]!=runner->y){
        runner->has_changed=1;
        runner_to_screen(runner, 0, buffer);
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

void update_walk(runner_t* runner, uint8_t *buffer) {
  if (!(runner->is_jumping)) {
    runner->steps++;
    if (!((runner->steps)%4)) {
      if (runner->sprite==RUNNER1) {
	runner->sprite=RUNNER2;
        runner->has_changed=1;
        runner_to_screen(runner, 0, buffer);
      } else if (runner->sprite==RUNNER2) {
        runner->sprite=RUNNER3;
        runner->has_changed=1;
        runner_to_screen(runner, 0, buffer); 
      } else {
	runner->sprite=RUNNER1;
        runner->has_changed=1;
        runner_to_screen(runner, 0, buffer);
      }
    }
  }
}

void create_obstacle(obstacle_t *obstacle, obstacle_ctx_t *obstacle_ctx) {
  obstacle->x=LCDWIDTH-1;// Fixed (It cant be more than 127)
  obstacle->alive=0xFF;
  if ((get_rand(16)+obstacle_ctx->score)%2==0) { //gets the type of the obstacle(big or small)
    obstacle->y=48;
    obstacle->w=OBSSM_GLCD_WIDTH;
    obstacle->h=OBSSM_GLCD_HEIGHT;
    obstacle->sprite=obstacle_ctx->obstacles_small[(get_rand(5)+obstacle_ctx->score)%5]; // improve "randomness"
  } else {
    obstacle->y=40;
    obstacle->w=OBSBIG_GLCD_WIDTH;
    obstacle->h=OBSBIG_GLCD_HEIGHT;
    obstacle->sprite=obstacle_ctx->obstacles_big[(get_rand(5)+obstacle_ctx->score)%5]; // improve "randomness"
  }
}

void create_runner(runner_t *runner) {
  runner->x = 20;
  runner->y = 40;
  runner->w = RUNNER1_GLCD_WIDTH;
  runner->h = RUNNER1_GLCD_HEIGHT;
  runner->sprite=RUNNER1;
  runner->is_jumping=0;
  runner->steps=0;
  runner->has_changed=1;
}

void update_runner(runner_t *runner, uint8_t *buffer) {
  if (runner->has_changed) {
    write_part(buffer,runner->x,runner->y,runner->w,runner->h);
    runner->has_changed = 0;
  }
}

void draw_score(uint16_t score, uint8_t *buffer) {
  static char s[5];
  itoa(score,s,10);
  static int offset;
  static int char_width = 6;
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
  *highscore = get_score();
  if (*highscore == 0xFFFF) {
    *highscore = 0;
  }
}

void draw_highscore(uint16_t high, uint8_t *buffer) {
  char s[5];
  itoa(high,s,10);
  drawstring(buffer, 86, 0,s);
  write_part(buffer,86,0,22,8);
}

void draw_flash_screen(uint8_t *buffer) {
  clear_screen();
  clear_buffer(buffer);
  drawstring(buffer,10,2,"LOBETHAL");
  drawstring(buffer,10,3,"LUTHERAN");
  drawstring(buffer,10,4," SCHOOL ");
  drawstring(buffer,2,6,"RUNNER GAME");
  drawbitmap(buffer, LCDWIDTH-LOGO_WIDTH, 0, LOGO, LOGO_WIDTH, LOGO_HEIGHT, 1);
  write_part(buffer,1,0,LCDWIDTH,LCDHEIGHT);
  _delay_ms(700);
  clear_screen();
  clear_buffer(buffer);
}

void reset_obstacle(obstacle_t *obstacle) {
  obstacle->alive=0;
}

void reset_obstacles(obstacle_t *obstacles) {
  static int j;
  for (j=0;j<MAX_OBSTACLES;j++) {
    reset_obstacle(&obstacles[j]);
  }
}

void erase_obstacles(obstacle_t *obstacles, uint8_t *buffer) { //Erase obstacles from LCD screen
  static int j;
  for (j=0; j<MAX_OBSTACLES; j++) {
    if (obstacles[j].alive) {
      draw_obstacle(&obstacles[j], 0, buffer);
      write_part(buffer,obstacles[j].x,obstacles[j].y,obstacles[j].w,obstacles[j].h);
    }
  }
}

void init_obstacle_sprites(obstacle_ctx_t *obstacle_ctx) {
  //Initialise the arrays that keep the sprite addresses
  //One of these values is randomly chosen at obstacle creation
  obstacle_ctx->obstacles_small[0]=OBS1SM;
  obstacle_ctx->obstacles_small[1]=OBS2SM;
  obstacle_ctx->obstacles_small[2]=OBS3SM;
  obstacle_ctx->obstacles_small[3]=OBS4SM;
  obstacle_ctx->obstacles_small[4]=OBS5SM;
  obstacle_ctx->obstacles_small[5]=OBS6SM;

  obstacle_ctx->obstacles_big[0]=OBS1BIG;
  obstacle_ctx->obstacles_big[1]=OBS2BIG;
  obstacle_ctx->obstacles_big[2]=OBS3BIG;
  obstacle_ctx->obstacles_big[3]=OBS4BIG;
  obstacle_ctx->obstacles_big[4]=OBS5BIG;
  obstacle_ctx->obstacles_big[5]=OBS6BIG;
}

int collision_detection_and_draw(obstacle_t *obstacles, obstacle_ctx_t *obstacle_ctx, uint8_t *buffer) {
    //Draw obstacle to the buffer, check collision, and write to LCD
    static int bump = 0;
    static int j;
    for (j=0;j<MAX_OBSTACLES;j++) {
      if (obstacles[j].alive) {
        if (obstacles[j].x<1) {
          reset_obstacle(&obstacles[j]);
          (obstacle_ctx->score)++;
          (obstacle_ctx->n_of_obstacles)--;
          draw_obstacle(&obstacles[j], 0, buffer);
          draw_score(obstacle_ctx->score, buffer);//The score is only drawn to the LCD when changed
        } else {
          obstacles[j].x--;
          bump|=draw_obstacle(&obstacles[j], 1, buffer);//draw obstacle to buffer and detect possible collision
        }
        write_part(buffer,obstacles[j].x,obstacles[j].y,obstacles[j].w,obstacles[j].h);//draw obstacle to LCD
      }
    }
    return bump;
}

void spawn_obstacle_routine(obstacle_t *obstacles, obstacle_ctx_t *obstacle_ctx) {
  if ((!obstacles[obstacle_ctx->tail].alive)&(obstacle_ctx->frames_to_next_obstacle==0)) {
    if (get_rand(16) == 0) {//"1 in 16 chance" No, I know
      //If the previous conditions are met, create a new obstacle and delay creation of new obstacle
      create_obstacle(&obstacles[obstacle_ctx->tail], obstacle_ctx);
      (obstacle_ctx->tail)++;
      (obstacle_ctx->n_of_obstacles)++;
      obstacle_ctx->frames_to_next_obstacle = 60;//can be changed
    }
  }
  if (obstacle_ctx->tail == MAX_OBSTACLES) {
    obstacle_ctx->tail = 0;
  }
}

void init_obstacle_ctx(obstacle_ctx_t *obstacle_ctx) {
  init_obstacle_sprites(obstacle_ctx);
  obstacle_ctx->tail = 0;
  obstacle_ctx->n_of_obstacles = 0;
  obstacle_ctx->frames_to_next_obstacle = 0;
  obstacle_ctx->score = 0;
}

void finish_game(uint16_t score, uint16_t highscore, uint8_t *buffer) {
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

  //This is the buffer used to transfer data to the LCD
  uint8_t buffer[LCDWIDTH*LCDHEIGHT/8];
  //Points used for the runner jump y positions
  const char points[]={38,31,28,25,23,22,20,19,18,17,16,15,14,14,13,12,12,11,11,10,10,10,9,9,9,8,8,8,8,8,8};
  uint8_t button_sense = 0;
  uint16_t highscore = 0;
  uint8_t bump = 0; //collision between runner and obstacle kept here

  ground_sprite_t ground;
  runner_t runner;
  obstacle_t obstacles[MAX_OBSTACLES];
  obstacle_ctx_t obstacle_ctx;
  init_gnd(&ground);
  init_obstacle_ctx(&obstacle_ctx);
  create_runner(&runner);
  reset_obstacles(obstacles);
  init_hardware(); //low level atmega stuff (PORTS, ADC, etc)
  init_highscore(&highscore);

  draw_flash_screen(buffer);
  draw_highscore(highscore, buffer);//only time this is written to the screen
  draw_score(obstacle_ctx.score, buffer);

  while (1) {
    bump = 0;
    button_sense = button_pressed();
    _delay_us(100); // was 500
    button_sense |= button_pressed();
    _delay_us(100); // simple attempt to debounce
    clear_buffer(buffer);//The memory is cleared, but not the LCD
    if ((button_sense || button_pressed()) && !(runner.is_jumping)) {
      runner.is_jumping=2*sizeof(points);//The array points has the positions for the jump (2x because is back an forth )
    }
    update_walk(&runner, buffer); //Updates runner sprite (which leg touches the ground)
    update_jump(&runner, points, buffer); //Update the runner position
    draw_runner(&runner, 1, buffer);
	erase_obstacles(obstacles, buffer); // this prolongs the time on screen
    if (obstacle_ctx.n_of_obstacles <= MAX_OBSTACLES) { //Checks if MAX_OBSTACLES obstacles on screen already
      spawn_obstacle_routine(obstacles, &obstacle_ctx);
    }
    update_runner(&runner, buffer);
    bump = collision_detection_and_draw(obstacles, &obstacle_ctx, buffer);
    update_ground(&ground, buffer);
    _delay_ms(5); //was 3 FIXME needs a interrupt/timer scheme to keep fixed fps
    if (bump) finish_game(obstacle_ctx.score, highscore, buffer);
    if (obstacle_ctx.frames_to_next_obstacle) obstacle_ctx.frames_to_next_obstacle--;//Each frame decreases delay for new obstacle
//    erase_obstacles(obstacles, buffer); // to keep them on for longer, we now erase just prior to redraw
  }
}
