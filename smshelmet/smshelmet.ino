

#include <SoftwareSerial.h>
#include "Adafruit_FONA.h"

#define FONA_RX 2
#define FONA_TX 3
#define FONA_RST 4

// this is a large buffer for replies
char replybuffer[255];

SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
Adafruit_FONA fona = Adafruit_FONA(&fonaSS, FONA_RST);

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout = 0);

void setup() {
  Serial.begin(115200);

  // See if the FONA is responding
  if (! fona.begin(4800)) {  // make it slow so its easy to read!
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }
  Serial.println(F("FONA is OK"));

}

     char sendto[21], message[141];

void loop() {


 uint16_t vbat;
      if (! fona.getBattVoltage(&vbat)) {
        Serial.println(F("Failed to read Batt"));
      } 
      else {
       // Serial.print(F("VBat = ")); 
        Serial.println(vbat); 
     //   Serial.println(F(" mV"));
      }

 // make noise for crash ack?

// fona.playToolkitTone(2, 1000)) ;

 

 // or make a noise this way?
  //    fona.PWM(freq);
    
  
 //  fona.sendSMS(sendto, message));
  
  delay(6000);
}

