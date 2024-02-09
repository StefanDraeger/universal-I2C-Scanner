#include <Wire.h>
#include "boards.h"

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("\nI2C Scanner");
}

void findDevices() {
  int countDevices = 0;
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();
    if (error == 0 || error == 4) {
      countDevices++;
      if (error == 0) {
        Serial.print("\t\tI2C device found at address 0x");
      } else {
        Serial.print("\t\tUnknown error at address 0x");
      }
      String i2cAddress = (address < 16 ? "0" : "") + String(address, HEX) + "!";
      Serial.println(i2cAddress);
    }
  }
  if (countDevices == 0) {
    Serial.println("\t\tNo I2C devices found!");
  }
}

void loop() {
  Serial.print("An ");
  Serial.print(bc.boardname);
  Serial.println(" was recognized!");
#elif defined(otherBoard)
  uint8_t numI2CInterfaces = bc.numI2CInterfaces;
  Serial.println("The microcontroller has " + String(numI2CInterfaces, DEC) + " I2C Interfaces!");
  for (int pair = 0; pair < numI2CInterfaces; pair++) {
    uint8_t(*i2cPins)[2] = bc.i2cPins;

    uint8_t sda = i2cPins[pair][0];
    uint8_t scl = i2cPins[pair][1];

    Serial.println("\t[" + String(pair, DEC) + "] SDA: " + String(SDA, DEC) + ", SCL: " + String(SCL, DEC));
    Wire.begin(sda, scl);
    Serial.println("\tScanning...");
    findDevices();
  }
#else
  #ifdef defined(notDeclaredBoard)
    Serial.println("Boardtype not found, try default!");
  #endif
  Wire.begin();
  Serial.println("\tScanning...");
  findDevices();
#endif
  Serial.println("End.");
  delay(10000);
}