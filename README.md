# electronics
Various electronics related notes, projects and schematics


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
