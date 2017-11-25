# Sample code for the blog article *AVR sleep mode for fun and profit*
[Link to blog](http://steffen.ronalter.de/2017/11/26/avr-sleep-mode-for-fun-and-profit/)

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
