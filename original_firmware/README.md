utilities to simplify extraction of the original firmware, and testing of new, or aftermaket, component tester firmware 

extract_firmware.sh 

used to extract the firmware as shipped before uploading other firmware

the script extracts it twice, and then does a diff, to ensure no errors have occurred

the script then converts the extracted firmware to intel hex format

write_firmware.sh

used to write a firmware and eeprom file to the component tester

note that the eeprom (.eep) needs to be written for some of the aftermarket firmwares (.hex) to work

the script expects the firmware to be named t3.hex and the eeprom file to be named t3.eep

some experimentation may be necessary to see which firmware set works for a given "T3" or "T4" transistor tester

once a working firmware has been found, the schematic of the tester can be deduced by looking at the Makefile for the firmware set and comparing it to the canonical T3 or T4 +/1 v2 versions. In particular, check out the Makefiles in

https://github.com/Mikrocontroller-net/transistortester/tree/master/Software/trunk

