# Esp32 Data read and write

## Useful commands
idf.py build

idf.py -p PORT flash

idf.py monitor

sudo chmod 666 PORT

## LCD led commands

0x01 --> Clear Display.

0x02 --> Return Home.

0x03 --> 8-bit mode

0x04 --> Cursor Decrement (shift left).

0x06 --> Cursor Increment (shift right).

0x0C --> Display ON, Cursor OFF.

0x28 --> 4-bit mode, 2 lines, 5x8 font.

0x80 + col --> Set cursor to first row (column).

0xC0 + col --> Set cursor to second row (column).

https://cdn.sparkfun.com/assets/9/5/f/7/b/HD44780.pdf

