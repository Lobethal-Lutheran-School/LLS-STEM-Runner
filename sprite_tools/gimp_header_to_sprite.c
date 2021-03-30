//
// gimp_header_to_sprite.c
//
// copyright 2021
// Dr Erich S. Heinzle
//
// licence: GPL v2.0
//
// code to create sprites for Rex-Runner like games using the ST7565-T3 LCD screen
// the sprite to be converted must be exported as an indexed
// c header file from the gimp
//
// GIMP instructions:
// make the image height a multiple of 8, and the image width a multiple of 8
// to alter pencil size in the gimp to one pixel use the "[" / "]" keys
// convert the image to an indexed image with 2 colours using the "->image->mode" menu
// export the image from the GIMP as a C header using the "->file->export as"  menu
// name the exported C header "gimp_header.h"
//
// next
// this program must be compiled with "gimp_header.h" in the same directory
//
// gcc gimp_header_to_sprite.c -o gimp_header_to_sprite
//
// next, run the program and export to a file gimp_sprite.h
//
// ./gimp_header_to_sprite > gimp_sprite.h
//
// this sprite can then be used in the rex-runner game with suitable renaming and #include-fu
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

#include "gimp_header.h"
#include <stdio.h>

int main() {
	int w, bit, row, index;
	int word_size = 8;
	int rows = height/word_size;
	int new_byte;
	int out_count = 0;
	printf("#define GIMP_HEIGHT %d\n", height);
	printf("#define GIMP_WIDTH %d\n", width);
	printf("const static char gimp[]={\n");
	for (row = 0; row < rows; row++) {
		for (w = 0; w < width; w++) {
			new_byte = 0;
			for (bit = 0; bit < word_size; bit++) {
				index = (row*word_size*width) + bit*width + w;
				new_byte += header_data[index] << bit;
			}
			printf("0x%02x", new_byte);
			out_count++;
			if (!(out_count%8) && (out_count != rows*width)) {
                                printf(",\n");
                        } else if (out_count != rows*width) {
				printf(", ");
			}
		}
	}
	printf("\n};\n");
}
