# electronics
Various electronics related notes, projects and schematics


## Debian setup

```
$ sudo apt install -y avrdude
```

## Arduino boards

### [Arduino Pro Mini atmega328 Board 5V 16M Compatible Nano](https://store.arduino.cc/arduino-pro-mini)

> **LED: 13**. There is a built-in LED connected to digital pin 13. When the pin is HIGH value, the LED is on, when the pin is LOW, it's off.

* [Pin outs](https://www.arduino.cc/en/Hacking/MiniBootloader)

### [Mini ATTINY85 Micro USB Development Board for Digispark Kickstarter](https://irishelectronics.ie/epages/950018241.sf/en_IE/?ObjectID=5295918)

https://www.electroschematics.com/learn-to-use-attiny85-usb-mini-development-board/

## Arduino programmers

### USB2TT_CO4 from homsun-ic.com

```
$ sudo modprobe ch341

$ sudo dmesg -H
...
[  +0,149280] usb 1-2: New USB device found, idVendor=1a86, idProduct=7523, bcdDevice= 2.64
[  +0,000006] usb 1-2: New USB device strings: Mfr=0, Product=2, SerialNumber=0
[  +0,000003] usb 1-2: Product: USB Serial
[  +0,001315] ch341 1-2:1.0: ch341-uart converter detected
[  +0,000505] usb 1-2: ch341-uart converter now attached to ttyUSB0

$ sudo -i
# cat /dev/urandom > /dev/ttyUSB0

# the led should blink

```

Connect:

```
     usb2ttl    arduino pro mini
     GND <--------> GND
     RXD <--------> TXD
     TXD <--------> RXD
     5V  <--------> VCC
```


### [USBasp](https://irishelectronics.ie/USB-ISP-AVR-Programmer-Adapter-51)

```
[kwi15 14:36] usb 1-1: new low-speed USB device number 51 using xhci_hcd
[  +0,154185] usb 1-1: New USB device found, idVendor=16c0, idProduct=05dc, bcdDevice= 1.02
[  +0,000007] usb 1-1: New USB device strings: Mfr=1, Product=2, SerialNumber=0
[  +0,000003] usb 1-1: Product: USBasp
[  +0,000003] usb 1-1: Manufacturer: www.fischl.de
```
