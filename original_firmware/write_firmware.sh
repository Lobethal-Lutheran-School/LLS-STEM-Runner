#!/bin/sh

# note that the eeprom will also need to be written for some of the aftermarket
# firmwares (.hex) to work
#
# this script expects the firmware to be named t3.hex and the eeprom file to be named t3.eep
#
# some experimentation may be necessary to see which firmware set works
# for a given "T3" or "T4" transistor tester
#
# once a working firmware has been found, the schematic of the tester can be deduced

avrdude -c usbasp -P /dev/ttyACM0 usb -b 19800 -p m328P -U flash:w:t3.hex -U eeprom:w:t3.eep
