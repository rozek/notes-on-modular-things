#include <osap.h>
<<<< add more includes here, if necessary

  OSAP_Runtime osap;
  OSAP_Gateway_USBSerial serLink(&Serial);
  OSAP_Port_DeviceNames namePort("xxx");  <<<< don't forget to insert your thing's name here

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