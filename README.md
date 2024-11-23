# notes-on-modular-things #

This work contains a (growing) collection of notes on the [Modular-Things](https://github.com/modular-things/modular-things) project.

## Background ##

"Hardware Computing" is exciting but requires knowledge and skills in

* Mechanics (and possibly case construction)
* Electronics and
* Programming

For mechanics, there are [fischertechnik](https://www.fischertechnik.de/en) and [Lego technic](https://www.lego.com/de-de/themes/technic/about), case construction is aided by 3D printers, and programming is becoming easier for beginners thanks to [Blockly](https://developers.google.com/blockly), web-based development environments, or even generative AI.

However, electronics has remained difficult so far. Even modern microcontroller solutions like [Arduino](https://www.arduino.cc/) or [Espruino](https://www.espruino.com/) require (in addition to pure application development) at least the engagement with another environment - sometimes even the learning of another programming language.

[Modular Things](https://github.com/modular-things/modular-things) solve the problem by connecting prefabricated functional modules to a computer via USB, where they "register" along with their capabilities and can be controlled and linked together using JavaScript in a [web-based user interface](https://modular-things.com/), for example. The electronics side of hardware computing is thus reduced to simply wiring modules - on one side to a computer, and on the other side to sensors, actuators, and displays. The rest is just software.

And even if one has to assemble these modules (the "Things") themselves (because they are currently not available for purchase), they can be easily recombined afterwards - making them ideal for learning, experimenting, prototyping and for demonstrators.

### Terminology ###

In the "Modular Things" terminology, a "**thing**" is a complete module consisting of some hardware (e.g., an RP2040 board with any additional electronics required) and some software which lets the microcontroler communicate with a PC over USB and advertise itself and its functionalities in the modular-things web-based IDE.

The "**firmware**" of a thing is an Arduino sketch which implements a thing's functionality on the hardware side, and the "**software**" of a thing is  its JavaScript interface (which may still include some additional functionality on the software side)

## Hardware ##

In this work, the base of every module is a breakout board for the Raspberry Pico 2040 microcontroller - usually a [Waveshare RP2040-Zero](https://www.waveshare.com/wiki/RP2040-Zero) (because that seems to be the cheapest one - at least, here in Germany). However, many other modules (e.g., the [Pimoroni Tiny2040](https://shop.pimoroni.com/products/tiny-2040)) may be used as well - sometimes after slightly modifying the Arduino sketch that is required for the "firmware" of a "thing"






## License ##

[MIT License](LICENSE.md)
