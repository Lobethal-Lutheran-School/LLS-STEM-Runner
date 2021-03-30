#!/bin/sh

# note that eeprom will need to be written for some of the aftermarket
# firmwares to work
#
# some experimentation may be necessary to see which firwmare works
# for a given "T3" or "T4" transistor tester

avrdude -c usbasp -P /dev/ttyACM0 usb -b 19800 -p m328P -U flash:w:t3.hex -U eeprom:w:t3.eep
