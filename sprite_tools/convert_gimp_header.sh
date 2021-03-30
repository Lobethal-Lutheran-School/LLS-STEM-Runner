#!/bin/sh

file="$1"
cp "$1" gimp_header.h

gcc gimp_header_to_sprite.c -o gimp_header_to_sprite
./gimp_header_to_sprite > gimp_sprite.h

gcc spriteview.c -o spriteview
./spriteview
