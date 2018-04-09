## ADAFRUIT FEATHER HUZZAH ESP8266 WITH HX711 LOAD CELL AMPLIFIER

* THIS BOARD IS NOT 5V SAFE!

* In order to connect to Feather Hazzah using a USB cable, you need to download a driver CP210x: <br>
https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers<br>
For more detail, take a look at Adafruit page: <br>
https://learn.adafruit.com/adafruit-feather-huzzah-esp8266/using-nodemcu-lua

* FEATHER HUZZAH WITH EXP8266 <br>https://www.adafruit.com/product/2821

* PIN LAYOUT ![Pinout](/docs/readme-assets/Huzzah_ESP8266_Pinout_v1.2-1.png) <br> <br>
  * note that clock (SCL) and data (SDA) pins are pins 5 and 4 on the bottom right.
  * on SparkFun HX711 break out, VCC has to be connected to 5V (USB/VBUS pin on the board) and VDD goes to 3.3V supply (3V/3V3 pin on the board)  Other boards have to follow similar convention, but please, check documentation.

* Schematic<br><br>
![schematic](/docs/readme-assets/hazzah_to_hx711.png)

<br>
<br>
Hope this helps.

B.