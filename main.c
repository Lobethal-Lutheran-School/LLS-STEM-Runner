// 
// Copyright 2017 Robson Couto
// Copyright 2021 Erich Heinzle
//
// Licence GPL v2 
//

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
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

typedef struct  {
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


void draw_ground(void){
  static uint16_t i=0; // and then the one byte variable said... roll over... roll over...
  int ground_width = 512;
  if (i < (ground_width - 128)) {
    drawbitmap(buffer, 0, 56, gnd + i, 128, 8, 1);
  } else {
    drawbitmap(buffer, 0, 56, gnd+i, ground_width-i, 8, 1);
    drawbitmap(buffer, ground_width-i, 56, gnd, 128-(ground_width-i), 8, 1);
  }
  i++;
  if(i==ground_width)i=0;
}

uint8_t draw_obstacle(obstacle_t* obstacle,uint8_t color){
  return drawbitmap2(buffer, obstacle->x, obstacle->y, obstacle->sprite, obstacle->w, obstacle->h, color);
}

uint8_t draw_runner(runner_t* runner, uint8_t color){ // use pointers
  return drawbitmap2(buffer, runner->x, runner->y, runner->sprite, 20, 24, color);
}
void runner_to_screen(runner_t* runner, uint8_t color){
  draw_runner(runner,color);
  write_part(buffer,runner->x,runner->y,runner->w,runner->h);
}

void update_jump(runner_t* runner){
  static uint8_t index=0;
  if(runner->is_jumping){
    if(runner->is_jumping>31){
      if(points[index]!=runner->y){
        runner->has_changed=1;
        runner_to_screen(runner, 0);
      }
      runner->y=points[index];
      runner->is_jumping--;
      index++;
    }else{
      index--;
      if(points[index]!=runner->y){
        runner->has_changed=1;
        runner_to_screen(runner, 0);
      }
      runner->y=points[index];
      runner->is_jumping--;
      if(runner->is_jumping==0) {
	runner->y=40;
	runner->has_changed=1;
      }
    }
  }else{
    runner->y=40;
  }
}

void update_walk(runner_t* runner){
  if(!(runner->is_jumping)){
    runner->steps++;
    if(!runner->steps%8){
      //    if (rex->sprite==dino3) {
      if (runner->sprite==runner1) {
	runner->sprite=runner2;
        //rex->sprite=dino4;
        runner->has_changed=1;
        runner_to_screen(runner, 0);
      } else if (runner->sprite==runner2) {
        runner->sprite=runner3;
        //rex->sprite=dino4;
        runner->has_changed=1;
        runner_to_screen(runner, 0); 
      } else {
	runner->sprite=runner1;
        //rex->sprite=dino3;
        runner->has_changed=1;
        runner_to_screen(runner, 0);
      }
      //rex->steps=0;
    }
  }
}

const uint8_t* obstacles_small[6];
const uint8_t* obstacles_big[6];


void create_obstacle(obstacle_t* obstacle){
  obstacle->x=127;// Fixed (It cant be more than 127)
  obstacle->alive=0xFF;
  if(get_rand(2)%2==0){//gets the type of the obstacle(big or small)
    obstacle->y=48;
    obstacle->w=8;
    obstacle->h=16;
    obstacle->sprite=obstacles_small[get_rand(5)];
  }else{
    obstacle->y=40;
    obstacle->w=12;
    obstacle->h=24;
    obstacle->sprite=obstacles_big[get_rand(5)];
  }
}

void kill_obstacle(obstacle_t* obstacle){
  obstacle->alive=0;
}

void create_runner(runner_t* runner){
  runner->x = 20;
  runner->y = 40;
  runner->w = 20;
  runner->h = 24;
  runner->sprite=runner1;
  runner->is_jumping=0;
  runner->steps=0;
  runner->has_changed=1;
}

void draw_score(uint16_t score){
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

void draw_highscore(uint16_t high){
  char s[5];
  itoa(high,s,10);
  drawstring(buffer, 86, 0,s);
  write_part(buffer,86,0,22,8);
}


#define MAX_OBSTACLES 3

void create_obstacle(obstacle_t* obstacle);
int main(void){


  //Initise the arrays that keep the sprite addresses
  //One of these values in gotten randomly at cacti creation
  obstacles_small[0]=cacts1;
  obstacles_small[1]=cacts2;
  obstacles_small[2]=cacts3;
  obstacles_small[3]=cacts4;
  obstacles_small[4]=cacts5;
  obstacles_small[5]=cacts6;


  obstacles_big[0]=cactusb1;
  obstacles_big[1]=cactusb2;
  obstacles_big[2]=cactusb3;
  obstacles_big[3]=cactusb4;
  obstacles_big[4]=cactusb5;
  obstacles_big[5]=cactusb6;

  runner_t runner;
  create_runner(&runner);
  int button_sense = 0;

  obstacle_t obstacles[MAX_OBSTACLES];
  uint8_t n_of_obstacles=0; //current number of cacti on screen
  uint8_t tail=0;//the position of the new obstacle on the ring
  uint8_t frames_to_next_obstacle=0; //frames to next obstacle. This is a delay to the creation of
                           //the next obstacle. So the runner has some space to land
  uint16_t highscore=0,score=0;

  init_hardware(); //low level atmega stuff (PORTS, ACD, etc)
  highscore=get_score();
  if (highscore == 0xFFFF) {
    highscore = 0;
  } 

  uint8_t bump=0; //collision between runner and catus kept here
  clear_screen();
  clear_buffer(buffer);

  for(int j=0;j<MAX_OBSTACLES;j++){
    kill_obstacle(&obstacles[j]);
  }
  draw_highscore(highscore);//only time this is written to the screen
  draw_score(score);

  while(1){
    bump=0;
    button_sense = button_pressed();
    _delay_us(500);
    button_sense |= button_pressed();
    _delay_us(500);
    button_sense |= button_pressed();
    _delay_us(500);
    button_sense |= button_pressed();
    _delay_us(500);
    button_sense |= button_pressed();
    _delay_us(500);
    button_sense |= button_pressed();
    _delay_us(500); // simple attempt to debounce
    clear_buffer(buffer);//The memory is cleared, but not the LCD
    if(button_sense || button_pressed()){
      if(!(runner.is_jumping)){
	runner.is_jumping=2*sizeof(points);//The array points has the positions for the jump (2x because is back an forth )
      }
    }
    update_walk(&runner); //Updates runner sprite (which leg touches the ground)
    update_jump(&runner); //Update the runner position
    draw_runner(&runner,1);

    if(n_of_obstacles<=MAX_OBSTACLES){ //Checks if there are MAX_OBSTACLES cacti on screen already
      if((!obstacles[tail].alive)&(frames_to_next_obstacle==0)){
        if(get_rand(16)==0){//"1 in 16 chance" No, I know
          //If the previous conditions are met, create a new obstacle and delay creation of new cacti
          create_obstacle(&obstacles[tail]);
          tail++;
          n_of_obstacles++;
          frames_to_next_obstacle=60;//can be changed
        }
      }
      if (tail==MAX_OBSTACLES){
        tail=0;
      }
    }

    //Only writes the runner to the LCD when it has changed position or sprite
    if(runner.has_changed){
      write_part(buffer,runner.x,runner.y,runner.w,runner.h);
      runner.has_changed=0;
    }

    //Draw cacti to the buffer, checks collision, and write them to the LCD
    for(int j=0;j<MAX_OBSTACLES;j++){
      if(obstacles[j].alive){
        if(obstacles[j].x<1){
          kill_obstacle(&obstacles[j]);
          score++;
          n_of_obstacles--;
          draw_obstacle(&obstacles[j],0);
          draw_score(score);//The score is also drawn to the LCD only when changed
        }else{
          obstacles[j].x--;
          bump|=draw_obstacle(&obstacles[j],1);//draw the cati to the buffer and gets a possible collision
        }
        write_part(buffer,obstacles[j].x,obstacles[j].y,obstacles[j].w,obstacles[j].h);//draw the cati to the LCD
      }
    }

    draw_ground();//draw ground to buffer
    write_part(buffer,0,56,128,8);//draw gnd from buffer to LCD

    //_delay_ms(1);//was 3 FIXME needs a interrupt/timer scheme to keep fixed fps
    if (bump) {
      drawstring(buffer,16,2,"G A M E  O V E R");
      write_part(buffer,16,16,100,8);
      if(score>highscore)update_score(score); //writes new score to EEPROM`
      while (1) {
	if(button_pressed()){
	  reset();//see hardware.c for implementation
	}
      }
    }

    if(frames_to_next_obstacle)frames_to_next_obstacle--;//Each frame decreases delay for new catcus

    //Erase cacti from LCD screen
    for(int j=0;j<MAX_OBSTACLES;j++){
      if(obstacles[j].alive){
        draw_obstacle(&obstacles[j],0);
        write_part(buffer,obstacles[j].x,obstacles[j].y,obstacles[j].w,obstacles[j].h);
      }
    }
  }
}
