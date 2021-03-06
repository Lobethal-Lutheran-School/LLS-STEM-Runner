// 
// Copyright 2017 Robson Couto
// Copyright 2021 Erich Heinzle
//
// Licence GPL v2.1
//

#ifndef RUNNER_H
#define RUNNER_H

/* traditional T-rex runner */

/*

#define DINO1_GLCD_HEIGHT 24
#define DINO1_GLCD_WIDTH  20
const static uint8_t __attribute__ ((progmem)) dino1[]={
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfe, 0xff, 0xfd, 0xff, 0x7f, 0x5f,
0x5f, 0x5f, 0x1f, 0x1e,
0x1f, 0x3e, 0x7c, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x02, 0x06,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0x17, 0x03, 0x01, 0x03, 0x1f, 0x10, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
#define DINO2_GLCD_HEIGHT 24
#define DINO2_GLCD_WIDTH  20
const static uint8_t __attribute__ ((progmem)) dino2[]={
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x5f,
0x5f, 0x5f, 0x1f, 0x1e,
0x1f, 0x3e, 0x7c, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x02, 0x06,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0x17, 0x03, 0x01, 0x03, 0x1f, 0x10, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
#define DINO3_GLCD_HEIGHT 24
#define DINO3_GLCD_WIDTH  20
const static uint8_t __attribute__ ((progmem)) dino3[]={
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfe, 0xff, 0xfd, 0xff, 0x7f, 0x5f,
0x5f, 0x5f, 0x1f, 0x1e,
0x1f, 0x3e, 0x7c, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x02, 0x06,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0x17, 0x03, 0x01, 0x01, 0x03, 0x02, 0x02, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
#define DINO4_GLCD_HEIGHT 24
#define DINO4_GLCD_WIDTH  20
const static uint8_t __attribute__ ((progmem)) dino4[]={
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfe, 0xff, 0xfd, 0xff, 0x7f, 0x5f,
0x5f, 0x5f, 0x1f, 0x1e,
0x1f, 0x3e, 0x7c, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x02, 0x06,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x05, 0x01, 0x03, 0x1f, 0x10, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
#define DINO5_GLCD_HEIGHT 24
#define DINO5_GLCD_WIDTH  20
const static uint8_t __attribute__ ((progmem)) dino5[]={
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfe, 0xff, 0xf9, 0xf9, 0x7f, 0x7f,
0x7f, 0x7f, 0x3f, 0x3e,
0x1f, 0x3e, 0x7c, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x02, 0x06,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0x17, 0x03, 0x01, 0x03, 0x1f, 0x10, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
*/

/* experimental puppy dog runner */

#define RUNNER1_GLCD_HEIGHT 24
#define RUNNER1_GLCD_WIDTH 20
const static uint8_t __attribute__ ((progmem)) runner1[]={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x3e, 0xf0, 0xc0, 0xe0,
0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
0xf8, 0xfe, 0xff, 0xff, 0xfd, 0x1e, 0x1e, 0x0c,
0x00, 0x00, 0x01, 0xff, 0xff, 0x9f, 0x0f, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xff,
0xff, 0x80, 0x00, 0x00
};
#define RUNNER1_GLCD_HEIGHT 24
#define RUNNER1_GLCD_WIDTH 20
const static uint8_t __attribute__ ((progmem)) runner2[]={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x30, 0xfc, 0xc6, 0xe0,
0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
0xf8, 0xfe, 0xff, 0xff, 0xfd, 0x1e, 0x1e, 0x0c,
0x00, 0xc0, 0xf1, 0xff, 0xff, 0x9f, 0x0f, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0xc7, 0xf7, 0xff,
0xff, 0x80, 0x00, 0x00
};
#define RUNNER1_GLCD_HEIGHT 24
#define RUNNER1_GLCD_WIDTH 20
const static uint8_t __attribute__ ((progmem)) runner3[]={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x38, 0xfe, 0xc0, 0xe0,
0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
0xf8, 0xfe, 0xff, 0xff, 0xfd, 0x1e, 0x1e, 0x0c,
0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0x8f, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xff,
0xff, 0xe0, 0x80, 0x00
};
#endif

