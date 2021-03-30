//
// spriteview.c
//
// copyright 2021
// Dr Erich S. Heinzle
//
// licence: GPL v2.0
//
// code to view sprites for Rex-Runner like games using the ST7565-T3 LCD screen
//
// to visualise the created sprite in ASCII, compile
//
// gcc spriteview.c -o spriteview
//
// in the same directory as "gimp_sprite.h"
//
// and then run 
//
// ./spriteview
//
// to see the sprite rotated 90 degrees CCW in ASCII
//
// Background:
//
// the sprites are encoded as 8 pixel vertical stripes, going from left to right
// i.e. each hex encoded byte encodes a vertical stripe, stepping through the image
// from left to right, then row by row, where each row start 8 pixels lower
//

#include "sprites_test.h"
#include "gimp_sprite.h"
#include <stdio.h>


int main () {
	int i, j, k, pixel, columns;
	char word, mask;
	int word_width = 8;

        columns = DINO1_GLCD_HEIGHT/word_width;
        for (i = 0; i < DINO1_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*DINO1_GLCD_WIDTH;
                        word = dino1[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }

        columns = DINO2_GLCD_HEIGHT/word_width;
        for (i = 0; i < DINO2_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*DINO2_GLCD_WIDTH;
                        word = dino2[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }

        columns = DINO3_GLCD_HEIGHT/word_width;
        for (i = 0; i < DINO3_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*DINO3_GLCD_WIDTH;
                        word = dino3[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }


	for (i = 0; i < 16*8; i++) {
                word = chess[i/word_width];
                mask = 1 << (i%word_width);
                pixel = word & mask;
                if (pixel) {
                        printf("#");
                } else {
                        printf("-");
                }
                if (!((i+1)%8)) {
                        printf("\n");
                }
        }
	printf("\n");
        for (i = 0; i < 16*8; i++) {
                word = zeros[i/word_width];
                mask = 1 << (i%word_width);
                pixel = word & mask;
                if (pixel) {
                        printf("#");
                } else {
                        printf("-");
                }
                if (!((i+1)%8)) {
                        printf("\n");
                }
	}
	printf("\n");
        for (i = 0; i < 16*8; i++) {
                word = sqr[i/word_width];
                mask = 1 << (i%word_width);
                pixel = word & mask;
                if (pixel) {
                        printf("#");
                } else {
                        printf("-");
                }
                if (!((i+1)%8)) {
                        printf("\n");
                }
        }
	printf("\n");
        for (i = 0; i < 16*8; i++) {
                word = ones[i/word_width];
                mask = 1 << (i%word_width);
                pixel = word & mask;
                if (pixel) {
                        printf("#");
                } else {
                        printf("-");
                }
                if (!((i+1)%8)) {
                        printf("\n");
                }
        }
	printf("\n");
        columns = CACTS1_GLCD_HEIGHT/word_width;
        for (i = 0; i < CACTS1_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*CACTS1_GLCD_WIDTH;
                        word = cacts1[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }

	printf("\n");
        columns = CACTS2_GLCD_HEIGHT/word_width;
        for (i = 0; i < CACTS2_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*CACTS2_GLCD_WIDTH;
                        word = cacts2[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }

        printf("\n");
        columns = CACTS3_GLCD_HEIGHT/word_width;
        for (i = 0; i < CACTS3_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*CACTS3_GLCD_WIDTH;
                        word = cacts3[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }
        
        printf("\n");
        columns = CACTS4_GLCD_HEIGHT/word_width;
        for (i = 0; i < CACTS4_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*CACTS4_GLCD_WIDTH;
                        word = cacts4[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }
        printf("\n");
        columns = CACTS5_GLCD_HEIGHT/word_width;
        for (i = 0; i < CACTS5_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*CACTS5_GLCD_WIDTH;
                        word = cacts5[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }
        printf("\n*****************\n");
	columns = CACTUSB1_GLCD_HEIGHT/word_width;
        for (i = CACTUSB1_GLCD_WIDTH - 1; i >= 0; i--) {
		for (j = 0; j < columns; j++) {
			int index = i + j*CACTUSB1_GLCD_WIDTH;
                	word = cactusb1[index];
			for (k = 0; k < 8; k++) {
                		mask = 1 << k;
                		pixel = word & mask;
                		if (pixel) {
                		        printf("#");
                		} else {
                		        printf("-");
                		}
			}
                	if (j == (columns - 1)) {
                		printf("\n");
			}
		}
        }
	printf("\n*****************\n");
        columns = GND_GLCD_HEIGHT/word_width;
        for (i = GND_GLCD_WIDTH - 1; i >= 0; i--) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*GND_GLCD_WIDTH;
                        word = gnd[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }
        printf("\n*****************\n");
        columns = GIMP_HEIGHT/word_width;
        for (i = GIMP_WIDTH - 1; i >= 0; i--) {
//      for (i = 0; i < CACTUSB1_GLCD_WIDTH; i++) {
                for (j = 0; j < columns; j++) {
                        int index = i + j*GIMP_WIDTH;
                        word = gimp[index];
                        for (k = 0; k < 8; k++) {
                                mask = 1 << k;
                                pixel = word & mask;
                                if (pixel) {
                                        printf("#");
                                } else {
                                        printf("-");
                                }
                        }
                        if (j == (columns - 1)) {
                                printf("\n");
                        }
                }
        }
        printf("\n*****************\n");
}
