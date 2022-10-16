// 
// Copyright 2017 Robson Couto
// Copyright 2021,2022 Erich Heinzle
// Copyright 2022 Tonia Nielsen and Oscar Heinzle
//
// Licence GPL v2 
//

#ifndef SPRITES_H
#define SPRITES_H

/*for debug
const static uint8_t __attribute__ ((progmem)) zeros[]={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const static uint8_t __attribute__ ((progmem)) ones[]={
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
const static uint8_t __attribute__ ((progmem)) chess[]={
0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA,
0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA
};
const static uint8_t __attribute__ ((progmem)) sqr[]={
0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFF
};
*/

// small cactus obstacle sprites
#define CACTS1_GLCD_HEIGHT 16
#define CACTS1_GLCD_WIDTH  8
const static uint8_t __attribute__ ((progmem)) cacts1[]={
0xe0, 0xe0, 0x00, 0xff, 0xff, 0x00, 0xf8, 0xf8,
0x03, 0x07, 0x04, 0xff, 0xff, 0x01, 0x01, 0x00
};
#define CACTS2_GLCD_HEIGHT 16
#define CACTS2_GLCD_WIDTH  8
const static uint8_t __attribute__ ((progmem)) cacts2[]={
0xf0, 0x00, 0xfe, 0xff, 0xfe, 0x00, 0xfc, 0x00,
0x07, 0x04, 0xff, 0xff, 0xff, 0x01, 0x01, 0x00
};
#define CACTS3_GLCD_HEIGHT 16
#define CACTS3_GLCD_WIDTH  8
const static uint8_t __attribute__ ((progmem)) cacts3[]={
0x78, 0xfc, 0xc0, 0xff, 0xff, 0x00, 0xf8, 0xf8,
0x00, 0x00, 0x00, 0xff, 0xff, 0x02, 0x03, 0x01
};

#define CACTS4_GLCD_HEIGHT 16
#define CACTS4_GLCD_WIDTH  8
const static uint8_t __attribute__ ((progmem)) cacts4[]={
0xf0, 0x00, 0xfe, 0xff, 0xfe, 0x00, 0xfc, 0x00,
0x07, 0x04, 0xff, 0xff, 0xff, 0x01, 0x01, 0x00
};
#define CACTS5_GLCD_HEIGHT 16
#define CACTS5_GLCD_WIDTH  8
const static uint8_t __attribute__ ((progmem)) cacts5[]={
0xfc, 0xfc, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xf0,
0x03, 0x07, 0x0c, 0xff, 0xff, 0x18, 0x1f, 0x0f
};
#define CACTS6_GLCD_HEIGHT 16
#define CACTS6_GLCD_WIDTH  8
const static uint8_t __attribute__ ((progmem)) cacts6[]={
0xfc, 0x00, 0xfe, 0xff, 0xfe, 0x00, 0xfc, 0x00,
0x01, 0x01, 0xff, 0xff, 0xff, 0x02, 0x03, 0x00
};

// large cactus obstacle sprites
#define CACTUSB1_GLCD_HEIGHT 24
#define CACTUSB1_GLCD_WIDTH  12
const static uint8_t __attribute__ ((progmem)) cactusb1[]={
0x80, 0xc0, 0x80, 0x00, 0xfe, 0xff, 0xff, 0xfe, 0x00, 0xc0, 0xe0, 0xc0,
0x3f, 0x7f, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x60, 0x7f, 0x3f, 0x1f,
0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x40, 0x00, 0x00
};
#define CACTUSB2_GLCD_HEIGHT 24
#define CACTUSB2_GLCD_WIDTH  11
const static uint8_t __attribute__ ((progmem)) cactusb2[]={
0xc0, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0xe0, 0xc0,0x00,
0x7f, 0xff, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0x60, 0x60, 0x3f, 0x1f,0x00,
0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00,0x00
};
#define CACTUSB3_GLCD_HEIGHT 24
#define CACTUSB3_GLCD_WIDTH  12
const static uint8_t __attribute__ ((progmem)) cactusb3[]={
0xf8, 0xf8, 0xf8, 0x00, 0xfe, 0xff, 0xff, 0xfe, 0x00, 0xc0, 0xe0, 0xc0,
0x07, 0x0f, 0x1f, 0x1c, 0xff, 0xff, 0xff, 0xff, 0x60, 0x7f, 0x3f, 0x1f,
0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x40, 0x00, 0x00
};
#define CACTUSB4_GLCD_HEIGHT 24
#define CACTUSB4_GLCD_WIDTH  12
const static uint8_t __attribute__ ((progmem)) cactusb4[]={
0xc0, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0xc0, 0xc0, 0x00,
0x7f, 0xff, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0x40, 0x40, 0x7f, 0x3f, 0x00,
0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x80
};
#define CACTUSB5_GLCD_HEIGHT 24
#define CACTUSB5_GLCD_WIDTH  12
const static uint8_t __attribute__ ((progmem)) cactusb5[]={
0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00,
0xff, 0xfe, 0x80, 0xff, 0xff, 0x02, 0xe2, 0x03, 0xf8, 0xf8, 0x00, 0xf0,
0x00, 0x01, 0x01, 0xff, 0xff, 0x00, 0x07, 0x04, 0xff, 0xff, 0x02, 0x03
};
#define CACTUSB6_GLCD_HEIGHT 24
#define CACTUSB6_GLCD_WIDTH  12
const static uint8_t __attribute__ ((progmem)) cactusb6[]={
0x00, 0xf8, 0xf8, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0xc0, 0xc0,
0x00, 0x0f, 0x1f, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0x40, 0x40, 0x7f, 0x3f,
0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00
};

// Hand, Bat, Gravestone sprites by Oscar Heinzle & Tonia Nielsen 2022
// hand
#define HANDSM_GLCD_HEIGHT 16
#define HANDSM_GLCD_WIDTH 8
const static uint8_t __attribute__ ((progmem)) handsm[]={
0x00, 0x30, 0xc4, 0x88, 0xf2, 0xe4, 0xf8, 0x00,
0x40, 0x20, 0x80, 0xff, 0xff, 0xff, 0xa0, 0x50
};
// bat 1
#define BAT1SM_GLCD_HEIGHT 16
#define BAT1SM_GLCD_WIDTH 8
const static uint8_t __attribute__ ((progmem)) bat1sm[]={
0x7e, 0x1c, 0x3f, 0x0e, 0x3f, 0x1c, 0x7e, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// bat 2
#define BAT2SM_GLCD_HEIGHT 16
#define BAT2SM_GLCD_WIDTH 8
const static uint8_t __attribute__ ((progmem)) bat2sm[]={
0x00, 0xf0, 0xe0, 0xf8, 0x70, 0xf8, 0xe0, 0xf0,
0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03
};
// bat 3
#define BAT3SM_GLCD_HEIGHT 16
#define BAT3SM_GLCD_WIDTH 8
const static uint8_t __attribute__ ((progmem)) bat3sm[]={
0x00, 0xfc, 0x38, 0x7e, 0x1c, 0x7e, 0x38, 0xfc,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// gravestone 1
#define GRAVE1BIG_GLCD_HEIGHT 24
#define GRAVE1BIG_GLCD_WIDTH 12
const static uint8_t __attribute__ ((progmem)) grave1big[]={
0xf0, 0xfe, 0xfe, 0xff, 0x01, 0x01, 0xcd, 0x21,
0x21, 0xfe, 0xfe, 0xf0, 0xff, 0xff, 0xff, 0xff,
0xbd, 0x81, 0x81, 0x81, 0xbd, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0x86, 0xf0,
0xf0, 0xff, 0xff, 0xff
};
// gravestone 2
#define GRAVE2BIG_GLCD_HEIGHT 24
#define GRAVE2BIG_GLCD_WIDTH 12
const static uint8_t __attribute__ ((progmem)) grave2big[]={
0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xf0, 0xf0, 0xf0, 0x03, 0x03, 0x03, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x03,
0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0x00, 0x00, 0x00
};
// gravestone 3
#define GRAVE3BIG_GLCD_HEIGHT 24
#define GRAVE3BIG_GLCD_WIDTH 12
const static uint8_t __attribute__ ((progmem)) grave3big[]={
0x00, 0x00, 0x00, 0x18, 0x98, 0xfe, 0xfe, 0x98,
0x18, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0x00,
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0x00
};
// gravestone 4
#define GRAVE4BIG_GLCD_HEIGHT 24
#define GRAVE4BIG_GLCD_WIDTH 12
const static uint8_t __attribute__ ((progmem)) grave4big[]={
0xf8, 0xfe, 0xfe, 0x7f, 0x7f, 0x1f, 0x1f, 0x7f,
0x7f, 0xfe, 0xfe, 0xf8, 0xff, 0xff, 0xff, 0xfe,
0xfe, 0x00, 0x00, 0xfe, 0xfe, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff,
0xff, 0xff, 0xff, 0xff
};
// bat 4
#define BAT4BIG_GLCD_HEIGHT 24
#define BAT4BIG_GLCD_WIDTH 12
const static uint8_t __attribute__ ((progmem)) bat4big[]={
0x00, 0xfc, 0xf8, 0xf0, 0xf8, 0xfe, 0xfc, 0xfe,
0xf8, 0xf0, 0xf8, 0xfc, 0x00, 0x07, 0x03, 0x01,
0x00, 0x03, 0x01, 0x03, 0x00, 0x01, 0x03, 0x07,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
// bat 5
#define BAT5BIG_GLCD_HEIGHT 24
#define BAT5BIG_GLCD_WIDTH 12
const static uint8_t __attribute__ ((progmem)) bat5big[]={
0xc0, 0x80, 0x00, 0x80, 0xe0, 0xc0, 0xe0, 0x80,
0x00, 0x80, 0xc0, 0x00, 0x7f, 0x3f, 0x1f, 0x0f,
0x3f, 0x1f, 0x3f, 0x0f, 0x1f, 0x3f, 0x7f, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
// bat 6
#define BAT6BIG_GLCD_HEIGHT 24
#define BAT6BIG_GLCD_WIDTH 12
const static uint8_t __attribute__ ((progmem)) bat6big[]={
0x00, 0xf8, 0xf0, 0xe0, 0xf0, 0xfc, 0xf8, 0xfc,
0xf0, 0xe0, 0xf0, 0xf8, 0x00, 0x0f, 0x07, 0x03,
0x01, 0x07, 0x03, 0x07, 0x01, 0x03, 0x07, 0x0f,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};

#define ORIG_GND_GLCD_HEIGHT 8
#define ORIG_GND_GLCD_WIDTH  512
const static uint8_t __attribute__ ((progmem)) origgnd[]={
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x42, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x12, 0x12, 0x12, 0x12, 0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x22, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x42, 0x42, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x82, 0x82, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x42, 0x02,
0x02, 0x02, 0x02, 0x02, 0x22, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x42, 0x42, 0x42, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x22, 0x02, 0x02, 0x02, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x22, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x82,
0x02, 0x02, 0x12, 0x12, 0x12, 0x12, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x22, 0x22, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x82, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x12, 0x12, 0x12, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x82, 0x82, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x22, 0x02, 0x02, 0x02, 0x02, 0x82, 0x82, 0x82, 0x82, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0x03, 0x81, 0x81, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,
0x02, 0x02, 0x12, 0x12, 0x12, 0x12, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06, 0x0c, 0x08, 0x08,
0x08, 0x08, 0x08, 0x08, 0x08, 0x0c, 0x06, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x82, 0x02, 0x02,
0x02, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x82, 0x82, 0x82, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02
};

// Lobethal Lutheran School ground sprite
#define LLS_GND_GLCD_HEIGHT 8
#define LLS_GND_GLCD_WIDTH  512
const static uint8_t __attribute__ ((progmem)) llsgnd[]={
0x01, 0x01, 0x7d, 0x41, 0x41, 0x01, 0x39, 0x45,
0x45, 0x39, 0x01, 0x7d, 0x55, 0x55, 0x29, 0x01,
0x7d, 0x55, 0x45, 0x01, 0x05, 0x7d, 0x05, 0x01,
0x7d, 0x11, 0x11, 0x7d, 0x01, 0x79, 0x15, 0x15,
0x79, 0x01, 0x7d, 0x41, 0x41, 0x01, 0x01, 0x01,
0x01, 0x01, 0x7d, 0x41, 0x41, 0x01, 0x3d, 0x41,
0x41, 0x3d, 0x01, 0x05, 0x7d, 0x05, 0x01, 0x7d,
0x11, 0x11, 0x7d, 0x01, 0x7d, 0x55, 0x45, 0x01,
0x7d, 0x15, 0x35, 0x59, 0x01, 0x79, 0x15, 0x15,
0x79, 0x01, 0x7d, 0x19, 0x31, 0x7d, 0x01, 0x01,
0x01, 0x01, 0x01, 0x49, 0x55, 0x55, 0x25, 0x01,
0x39, 0x45, 0x45, 0x01, 0x7d, 0x11, 0x11, 0x7d,
0x01, 0x39, 0x45, 0x45, 0x39, 0x01, 0x39, 0x45,
0x45, 0x39, 0x01, 0x7d, 0x41, 0x41, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x7d, 0x11, 0x11, 0x7d, 0x01, 0x7d, 0x01,
0x49, 0x55, 0x55, 0x25, 0x01, 0x05, 0x7d, 0x05,
0x01, 0x39, 0x45, 0x45, 0x39, 0x01, 0x7d, 0x15,
0x35, 0x59, 0x01, 0x7d, 0x01, 0x39, 0x45, 0x45,
0x01, 0x79, 0x15, 0x15, 0x79, 0x01, 0x7d, 0x41,
0x41, 0x01, 0x7d, 0x41, 0x41, 0x0d, 0x11, 0x61,
0x11, 0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x39,
0x45, 0x55, 0x75, 0x01, 0x7d, 0x15, 0x35, 0x59,
0x01, 0x39, 0x45, 0x45, 0x39, 0x01, 0x3d, 0x41,
0x41, 0x3d, 0x01, 0x7d, 0x19, 0x31, 0x7d, 0x01,
0x7d, 0x45, 0x45, 0x39, 0x01, 0x7d, 0x55, 0x45,
0x01, 0x7d, 0x45, 0x45, 0x39, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x7d, 0x41, 0x41, 0x01, 0x39, 0x45, 0x45, 0x39,
0x01, 0x7d, 0x55, 0x55, 0x29, 0x01, 0x7d, 0x55,
0x45, 0x01, 0x05, 0x7d, 0x05, 0x01, 0x7d, 0x11,
0x11, 0x7d, 0x01, 0x79, 0x15, 0x15, 0x79, 0x01,
0x7d, 0x41, 0x41, 0x01, 0x01, 0x01, 0x01, 0x01,
0x7d, 0x41, 0x41, 0x01, 0x3d, 0x41, 0x41, 0x3d,
0x01, 0x05, 0x7d, 0x05, 0x01, 0x7d, 0x11, 0x11,
0x7d, 0x01, 0x7d, 0x55, 0x45, 0x01, 0x7d, 0x15,
0x35, 0x59, 0x01, 0x79, 0x15, 0x15, 0x79, 0x01,
0x7d, 0x19, 0x31, 0x7d, 0x01, 0x01, 0x01, 0x01,
0x01, 0x49, 0x55, 0x55, 0x25, 0x01, 0x39, 0x45,
0x45, 0x01, 0x7d, 0x11, 0x11, 0x7d, 0x01, 0x39,
0x45, 0x45, 0x39, 0x01, 0x39, 0x45, 0x45, 0x39,
0x01, 0x7d, 0x41, 0x41, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x7d, 0x15, 0x05, 0x01, 0x3d, 0x41,
0x41, 0x3d, 0x01, 0x05, 0x7d, 0x05, 0x01, 0x3d,
0x41, 0x41, 0x3d, 0x01, 0x7d, 0x15, 0x35, 0x59,
0x01, 0x7d, 0x55, 0x45, 0x01, 0x01, 0x01, 0x01,
0x01, 0x7d, 0x19, 0x31, 0x19, 0x7d, 0x01, 0x7d,
0x01, 0x7d, 0x19, 0x31, 0x7d, 0x01, 0x7d, 0x45,
0x45, 0x39, 0x01, 0x7d, 0x55, 0x45, 0x01, 0x7d,
0x45, 0x45, 0x39, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
};

#define OBS1SM handsm
#define OBS2SM bat1sm
#define OBS3SM bat2sm
#define OBS4SM bat2sm
#define OBS5SM bat3sm
#define OBS6SM cacts6
#define OBSSM_GLCD_HEIGHT 16
#define OBSSM_GLCD_WIDTH 8
#define OBS1BIG grave1big
#define OBS2BIG grave2big
#define OBS3BIG grave3big
#define OBS4BIG grave4big
#define OBS5BIG bat4big
#define OBS6BIG bat5big
#define OBSBIG_GLCD_HEIGHT 24
#define OBSBIG_GLCD_WIDTH 12
#define GND_SPRITE origgnd
#define GND_GLCD_HEIGHT ORIG_GND_GLCD_HEIGHT 
#define GND_GLCD_WIDTH ORIG_GND_GLCD_HEIGHT 

#endif
