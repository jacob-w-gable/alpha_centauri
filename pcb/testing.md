# Testing PCB

## Before powering on

1. Test GND and 3v3 = 0 ohm
1. Test GND and 5v = 0 ohm
1. Test 3v3 and 5v = 0 ohm
1. Test for continuity between GND and all GND pins on rp2040
1. Test for continuity between 3v3 and all 3v3 pins on rp2040
1. Test for shorts on both sides of all resistors and capacitors. Note: One of the resistors by the mosfet will beep - this is noraml. Also seems like it can happen on the data resistors if you push hard enough.
1. Test for no continuity between each column with each other column
1. Test for no continuity between each row with each other row
1. Test for no continuity between each column with each row
1. Test for continuity between each column with rp2040
1. Test for continuity between each row with rp2040
1. Test for continuity on GND of each capacitor
1. Test for continuity on 3v3 of each 3v3 capacitor
1. Test for continuity on 1v1 of each 1v1 capacitor (just compare them against each other)
1. Test for continuity to 1v1 pins of rp2040 against one the side of one of the 1v1 capacitors
1. Test for no continuity between 3v3 and 1v1 capacitor sides
1. Test for no continuity between the two inputs of the mosfet
1. Test for no continuity between each pin of the flash device
1. Test for continuity between the GND pin of the flash device and GND
1. Test for continuity between the VCC pin of the flash device and 3v3
1. Test for continuity between each pin with the rp2040
1. Test for no continuity between the buttons, unless pressed
1. Test for no continuity between each complimenting side of the data resistors
1. Test for continuity between USB and data resistors
1. Test for continuity between data resistors and rp2040
1. Test for continuity between GND and GND pads of crystal
1. Test for continuity between XIN and rp2040
1. Test for continuity between XOUT (side of a resistor) and rp2040
1. Test for continuity between the other side of that resistor and crystal
1. Test for continuity between the data pins of the slave USB and rp2040
1. Test for continuity between LED input to rp2040
1. Test for continuity between haptic control line to rp2040
1. Test for no continuity between LED input and 3v3
1. Test for no continuity between columns and 3v3
1. Test for no continuity between rows and 3v3
1. Test for no continuity between split kb data line and 3v3
1. Test for no continuity between haptic control line and 3v3
1. Test for no continuity between haptic control line and LED input
1. Test for no continuity between haptic control line and data lines
1. Test for no continuity between LED input and data lines

## After powering on

1. Measure 1v1, 3v3, and 5v voltage.

## Notes

- The top row is the most important. It contains the 1v1 and 3v3 reference points, D+/D-, and QSPI pins. If these pins have good connections while others have poor connections (within reason), then the flashing should at least work.
- Might want to wait to put the LEDs and sockets on until after we can verify that the flashing works
