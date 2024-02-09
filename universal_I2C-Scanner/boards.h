struct BoardConfiguration {
  const char* boardname;
  uint8_t numI2CInterfaces;
  uint8_t i2cPins[][2];
};

#ifdef ARDUINO_AVR_UNO
  #define arduinoBoard
  BoardConfiguration bc = { "Arduino UNO", 0, { { 0, 0 } } };
#elif defined(ARDUINO_AVR_LEONARDO)
  #define arduinoBoard
  BoardConfiguration bc = { "Arduino Leonardo", 0, { { 0, 0 } } };
#elif defined(ARDUINO_AVR_NANO)
  #define arduinoBoard
  BoardConfiguration bc = { "Arduino Nano", 0, { { 0, 0 } } };
#elif defined(ARDUINO_AVR_MEGA2560)
  #define arduinoBoard
  BoardConfiguration bc = { "Arduino Mega 2560 R3", 0, { { 0, 0 } } };
#elif defined(ARDUINO_AVR_MICRO)
  #define arduinoBoard
  BoardConfiguration bc = { "Arduino Micro", 0, { { 0, 0 } } };
#elif defined(ARDUINO_ESP8266_NODEMCU_ESP12E)
  #define otherBoard
  BoardConfiguration bc = { "NodeMCU 1.0 (ESP-12E)", 1, { { D6, D5 } } };
#elif defined(ARDUINO_ESP8266_WEMOS_D1MINIPRO)
  #define otherBoard
  BoardConfiguration bc = { "LOLIN(WEMOS) D1 mini Pro", 1, { { 4, 5 } } };
#elif defined(ARDUINO_ESP8266_GENERIC)
  #define otherBoard
  //Boardconfiguration for Heltec HTIT-W8266 board with oboard OLED Display
  BoardConfiguration bc = { "Generic ESP8266 Module", 1, { { 16, 24 } } };
#else
  #define notDeclaredBoard
  BoardConfiguration bc = { "-undefined-", 0, { { 0, 0 } } };
#endif
