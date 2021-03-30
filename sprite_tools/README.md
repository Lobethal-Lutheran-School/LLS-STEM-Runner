gimp_header_to_sprite.c

code to create sprites for Rex-Runner like games using the ST7565-T3 LCD screen

the sprite to be converted must be exported as an indexed c header file from the gimp

GIMP instructions:

make the image height a multiple of 8, and the image width a multiple of 8

to alter pencil size in the gimp to one pixel use the "[" / "]" keys

draw the sprite as white pixels on a black background

convert the image to an indexed image with 2 colours using the "->image->mode" menu

export the image from the GIMP as a C header using the "->file->export as"  menu

name the exported C header "gimp_header.h"

next, gimp_header_to_sprite.c must be compiled with "gimp_header.h" in the same directory

gcc gimp_header_to_sprite.c -o gimp_header_to_sprite

next, run the program gimp_header_to_sprite and export to a file gimp_sprite.h

./gimp_header_to_sprite > gimp_sprite.h

this sprite can then be used in the rex-runner game with suitable renaming and #include-fu

to visualise the created sprite in ASCII, compile

gcc spriteview.c -o spriteview

in the same directory as "gimp_sprite.h"

and then run 

./spriteview

to see the sprite rotated 90 degrees CCW in ASCII, along with existing sprites in sprites_test.h

Background:

the sprites are encoded as 8 pixel vertical stripes, going from left to right
i.e. each hex encoded byte encodes a vertical stripe, stepping through the image
from left to right, then row by row, where each row start 8 pixels lower

