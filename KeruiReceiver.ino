/*
 * Mark Liebrand 2018
 * liebrand.io
 * 
 */

#include <RCSwitch.h>



#include <ELECHOUSE_CC1101_RCS_DRV.h>


int esp; // for ESP8266 & Arduino setting.
RCSwitch mySwitch = RCSwitch();



void setup() {
  Serial.begin(9600);
  esp = 0; 
  // Depending on the version of the elechouse library the following line is not needed / must be removed
  ELECHOUSE_cc1101.setESP8266(esp);    // esp8266 & Arduino SPI pin settings. Don´t change this line!
  ELECHOUSE_cc1101.setMHZ(433.92); // Here you can set your basic frequency. The lib calculates the frequency automatically (default = 433.92).The cc1101 can: 300-348 MHZ, 387-464MHZ and 779-928MHZ. Read More info from datasheet.
  ELECHOUSE_cc1101.Init(PA10);    // must be set to initialize the cc1101! set TxPower  PA10, PA7, PA5, PA0, PA_10, PA_15, PA_20, PA_30.  
  ELECHOUSE_cc1101.SetRx();    // set Receive on
  mySwitch.enableReceive(0); 
}

void loop() {
  if(mySwitch.available()) {
    Serial.println(mySwitch.getReceivedValue());
    mySwitch.resetAvailable();
  }
}


