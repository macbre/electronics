# electronics
Various electronics related notes, projects and schematics


## Debian setup

```
$ sudo apt install -y avrdude
$ sudo avrdude -v -v -P /dev/ttyUSB0 -c avrisp -p t85 
```

## Arduino boards

### [Arduino Pro Mini atmega328 Board 5V 16M Compatible Nano](https://store.arduino.cc/arduino-pro-mini)

> **LED: 13**. There is a built-in LED connected to digital pin 13. When the pin is HIGH value, the LED is on, when the pin is LOW, it's off.

* [Pin outs](https://www.arduino.cc/en/Hacking/MiniBootloader)

### [Mini ATTINY85 Micro USB Development Board for Digispark Kickstarter](https://irishelectronics.ie/epages/950018241.sf/en_IE/?ObjectID=5295918)

https://www.electroschematics.com/learn-to-use-attiny85-usb-mini-development-board/

![](https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/i/0995f7a6-730b-48d0-8612-c4408d15e84d/dc7h4n3-51e6389c-5f86-4fb2-a7ad-34f75f672003.png)

```
# avrdude -v -v -c usbasp-clone -p t85 -n 2>&1 | tail  -n12
avrdude: Device signature = 0x1e930b (probably t85)
avrdude: safemode: lfuse reads as E1
avrdude: safemode: hfuse reads as DD
avrdude: safemode: efuse reads as FE

avrdude: safemode: lfuse reads as E1
avrdude: safemode: hfuse reads as DD
avrdude: safemode: efuse reads as FE
avrdude: safemode: Fuses OK (E:FE, H:DD, L:E1)

avrdude done.  Thank you.
```

[Fuse bits](http://eleccelerator.com/fusecalc/fusecalc.php?chip=attiny85&LOW=E1&HIGH=DD&EXTENDED=FE&LOCKBIT=FF)

Bootloader:

```
wget https://raw.githubusercontent.com/micronucleus/micronucleus/master/firmware/releases/t85_aggressive.hex
avrdude -v -v -c usbasp-clone -p t85  -U flash:w:t85_aggressive.hex
```

https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json - board definitions for ATTiny

https://electronics.stackexchange.com/a/216233 - Arduino programming directly via USB

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

![](https://raw.githubusercontent.com/macbre/electronics/master/pictures/IMG_20200419_164215.png)
