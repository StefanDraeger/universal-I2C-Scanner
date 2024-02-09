
## universal I2C-Scanner
This small project is for scanning for I2C devices on the I2C bus of a microcontroller. 
I initially used the [I2C scanner from the Arduino Playground](https://playground.arduino.cc/Main/I2cScanner/) as a basis. 

 ### I2C Pins at Microcontroller
 Here is a small table with I2C pins of the most popular microcontrollers. (Of course this is not exhaustive).
 
| Microcontroller|SDA|SCL
|--|--|--|
|Arduino UNO, Arduino Nano|A5|A4
|Arduino Micro|D2|D3
|Arduino Mega 2560 R3|D20|D21
|Arduino DUE|D20|D21
|Wemos D1 Mini - ESP8266|D2 (GPIO04)|D1 (GPIO05)
|ESP8266 - Ideaspark|D6 (GPIO12)|D5 (GPIO14)
|ESP32|GPIO21|GPIO21
|ESP32 S3|GPIO08|GPIO09

### predefined microcontroller
I have already predefined some microcontrollers (file boards.h).

    #if defined(ARDUINO_ESP8266_GENERIC)
	    #define  otherBoard
	    //Boardconfiguration for Heltec HTIT-W8266 board with oboard OLED Display
	    BoardConfiguration bc = { "Generic ESP8266 Module", 1, { { 16, 24 } } };

You find the definions in %user%\AppData\Local\Arduino15\packages\*\hardware\...\boards.txt.

    Example: %user%\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.11

### Output

    An Generic ESP8266 Module was recognized!
    The microcontroller has 1 I2C Interfaces!
		[0] SDA: 4, SCL: 5
			Scanning...
			I2C device found at address 0x3c!
	End.
