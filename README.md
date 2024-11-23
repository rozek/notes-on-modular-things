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

## Hardware Requirements ##

In this work, the base of every module is a breakout board for the [Raspberry Pi Pico RP2040](https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html#rp2040) microcontroller - usually a [Waveshare RP2040-Zero](https://www.waveshare.com/wiki/RP2040-Zero) (because that seems to be the cheapest one - at least, here in Germany). However, many other modules (e.g., the [Pimoroni Tiny2040](https://shop.pimoroni.com/products/tiny-2040)) may be used as well - sometimes after slightly modifying the Arduino sketch that is required for the "firmware" of a "thing".

(t.b.w)

## Installation and Usage ##

Let's say, you have chosen a "thing" that you plan to build - or you want to develop a new one. Assuming, that this thing is called "xxx" (the name should qualify as a valid Javascript identifier), then you will find below the instructions for installation and use of that thing (skip whatever does not seem applicable and change `xxx` to the actual name of your thing):

#### Firmware Preparation ####

1. Install Arduino IDE (see https://www.arduino.cc/en/software)
2. Install the board "**Raspberry Pi Pico/RP2040/RP2350** by Earle F. Philhower, III" using the Arduino "Boards Manager"
3. Install "**osap** by Jake Robert Read" using the Arduino "Library Manager"

#### Firmware Installation ####

1. Create a new sketch and rename it to `xxx`
2. Copy the firmware for your thing from the internet into the sketch editor (or develop your own)
3. Connect the RP2040 board via USB and select it from the board dropdown in the Arduino IDE
4. Compile and upload the sketch

#### Software Preparation ####

1. Install Node.js (see https://nodejs.org/en/)
2. Download "modular-things" as a [ZIP archive](https://github.com/modular-things/modular-things/archive/refs/heads/main.zip), unpack it, and move it to a location of your choice
3. Open a terminal window and navigate to the extracted directory
4. run `npm install`

#### Software Installation ####

1. Open the terminal window and navigate to the extracted directory
2. copy the "xxx" directory from this repository and its contents into the `./things` folder. In the end, `./things/xxx` should have the following structure:
```
./things/xxx/
  circuit/
    images/
      layout.png
      schematic.png
      preview.png
  firmware/
    xxx/
      xxx.ino
  software/
    xxx.ts
```
3. Insert the following text into file `./things/_things.json` after the first line (i.e., after the opening bracket):
```json
  {
    "author":  "your name",
    "name":    "xxx",
    "software":"software/xxx.ts",
    "firmware":"firmware/xxx/xxx.ino",
    "images": [
      { 
        "name": "layout", 
        "src": "circuit/images/layout.png"
      },
      { 
        "name": "schematic", 
        "src": "circuit/images/schematic.png"
      },
      { 
        "name": "preview", 
        "src": "circuit/images/preview.png"
      }
    ]
  },
```
4. Insert the following lines into file `./index.ts`
  * `import xxx from "./xxx/software/xxx";`<br>e.g., as the last import statement
  * `xxx,`<br>e.g., as the last line in the `export default {` block
5. (Re)start the server<br>
    `npm run dev`

#### Thing Usage ####

1. Connect the properly prepared RP2040 board to your computer via USB.
2. Open the (**custom**) web environment: [http://localhost:3000](http://localhost:3000)
3. Click on "pair new thing" and select the "thing" you connected before<br>(the "List of Things" should now display a description of its interface).
4. Click on "rename" and change the name of your thing to something you want to use in your application (the new name must be a valid JavaScript variable identifier).

You should now be able to access your thing using JavaScript from within the IDE.

## How to develop your own "Thing" ##

Thanks to the design of "modular things", it turns out to be pretty simple to develop custom "things" - you do not even have to really know the Arduino environment and its C dialect. In many cases it is sufficient to use the templates shown below and fill in the "Building Blocks" for the desired functionality - that's it. The hardware may then be built using a breadboard.

### Templates ###

The following sections contain templates for the most important files that make up a "thing" - with placeholders where you should fill in the actual code for the functionalities you need. That code may either be found further below (in chapter "Building Blocks") or you will have to develop it yourself.

After completing these files, you should copy them into your thing's directory within your server's `./things` folder (as already described above):

```
./things/
  _things.json
  index.ts
  xxx/
    circuit/
      images/
        layout.png
        schematic.png
        preview.png
    firmware/
      xxx/
        xxx.ino
    software/
      xxx.ts
```

#### _things.json ####

`_things.json` is the filw where you tell the server your thing's name and where to find all files that make up that thing.

Insert the following lines to that file (usually at the second line):

```json
  {
    "author":  "your name",
    "name":    "xxx",
    "software":"software/xxx.ts",
    "firmware":"firmware/xxx/xxx.ino",
    "images": [
      {
        "name": "layout",
        "src": "circuit/images/layout.png"
      },
      {
        "name": "schematic",
        "src": "circuit/images/schematic.png"
      },
      {
        "name": "preview",
        "src": "circuit/images/preview.png"
      }
    ]
  },
```

#### index.ts ####

`index.ts` is used by the web IDE to load your thing's JavaScript interface.

You will have to apply two changes:

1. add line `import xxx from "./xxx/software/xxx";` e.g., as the last import statement
2. add line `xxx,` e.g., as the last line in the `export default {` block

#### xxx.ino ####

`xxx.ino` is an arduino "sketch" implementing the communication between the RP2040 and your PC over USB and the actual functionality of your "thing"

Use the following template as a basis for your development:

```c++
#include <osap.h>
<<<< add more includes here, if necessary

  OSAP_Runtime osap;
  OSAP_Gateway_USBSerial serLink(&Serial);
  OSAP_Port_DeviceNames namePort("xxx");

<<<< add any required definitions and functions for your thing

/**** Startup ****/

  void setup() {
    osap.begin();

<<<< add any required initialization code here
  }

/**** Operation ****/

  void loop() {
    osap.loop();

<<<< add any required operation code here
  }
```

#### xxx.ts ####

(t.b.w)

## Building Blocks ##

(t.b.w)

#### Built-in RGB LEDs ####

(t.b.w)

#### Digital In ####

(t.b.w)

#### Digital Out ####

(t.b.w)

#### Analog In ####

(t.b.w)

#### Analog Out ####

(t.b.w)

#### RC Servo Control ####

(t.b.w)

#### Continuous Rotation RC Servo Control ####

(t.b.w)

#### NeoPixel (WS2812) Control ####

(t.b.w)

## Application Examples ##

(t.b.w)

## License ##

[MIT License](LICENSE.md)
