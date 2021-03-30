#!/bin/sh

# extract the firmware as shipped before uploading other firmware
# extract it twice, and then do a diff, to ensure no errors have occurred
# then convert it to intel hex format

avrdude -F -b 19200 -p m328p -P /dev/ttyACM0 usb -c usbasp -U flash:r:firmware-first.bin:r
sleep 2
avrdude -F -b 19200 -p m328p -P /dev/ttyACM0 usb -c usbasp -U flash:r:firmware-second.bin:r
sleep 2
diff firmware-first.bin firmware-second.bin
objcopy -I binary -O ihex firmware-first.bin firmware.hex
