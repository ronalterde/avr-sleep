# Sample code for the blog article *AVR sleep mode for fun and profit*
[Link to blog part 1](http://steffen.ronalter.de/2017/11/26/avr-sleep-mode-for-fun-and-profit/)
[Link to blog part 2](http://steffen.ronalter.de/2017/12/03/avr-sleep-mode-for-fun-and-profit-part-2/)

To build the project (AVR libc is a prerequisite):
```
$ make all
```

To flash onto an ATmega32 (using avrdude with USBtiny programmer):
```
$ make program
```

To apply the fuse settings used in the example:
```
$ make fuse
```
