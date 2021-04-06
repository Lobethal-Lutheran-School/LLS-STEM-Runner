gimp_header_to_sprite.c

code to create sprites for Rex-Runner like games using the ST7565-T3 LCD screen

the sprite to be converted must be exported as an indexed c header file from the gimp

GIMP instructions:

make the image height a multiple of 8, but the image width can be something other than a multiple of 8

Ground dimensions: 512 pixels wide, and 8 pixels high

Runner dimensions: 20 pixels wide, and 24 pixels high, and three different pixmaps are used for the runner for animation, i.e. legs, or tail

Small obstacles (6 different ones can be used): 8 pixels wide, and 16 pixels high

Large obstacles (6 different ones can be used): 12 pixels wide, and 24 pixels high

to alter pencil size in the gimp to one pixel use the "[" / "]" keys

draw the sprite as white pixels on a black background

convert the image to an indexed image with 2 colours using the "->image->mode" menu

export the image from the GIMP as a C header using the "->file->export as"  menu

name the exported C header "something.h"

the simplest way to turn this into a sprite for use in the runner game is to run

./convert_gimp_header.sh something.h 

this will produce a sprite header file called

gimp_sprite.h

which will then be displayed in the terminal as ASCII


If you want to do it step by step, assuming you have first exported a C header from the gimp called "gimp_header.h"

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

ASCII sprite text saves as something.asc can be converted to a pgm bitmap with

asciitopgm height width something.asc > something.pgm

which can then be opened with the gimp

Background:

the sprites are encoded as 8 pixel vertical stripes, going from left to right
i.e. each hex encoded byte encodes a vertical stripe, stepping through the image
from left to right, then row by row, where each row start 8 pixels lower

