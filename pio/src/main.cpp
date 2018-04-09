    #include <ESP8266WiFi.h>
    #include "HX711.h"

    //////////////////////////////////////////////////////////////////////////////////
    // Define scale amp data pins
    //////////////////////////////////////////////////////////////////////////////////
    #define DOUT SDA
    #define SCL1 SCL

    ///////////////////////////////////////////////////////////////////////////////////
    HX711 scale(SDA, SCL);
    ///////////////////////////////////////////////////////////////////////////////////
    // Define calibration factor.  This can be adjusted in calibration mode by pressing
    // a/z or +/- keys
    ///////////////////////////////////////////////////////////////////////////////////
    float calibration_factor = -21050;
    float reading = 0;
     

    const char* ssid     = "Vail 2.4";
    const char* password = "1029384756";
     
    const char* host = "wifitest.adafruit.com";
     
    void setup() {
      Serial.begin(9600);
      delay(1000);
     
      // We start by connecting to a WiFi network
     
      Serial.println();
      Serial.println();
      Serial.print("Connecting to ");
      Serial.println(ssid);
      
      WiFi.begin(ssid, password);
      
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
     
      Serial.println("");
      Serial.println("WiFi connected");  
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());

      scale.set_scale(calibration_factor);
    }
     
    int value = 0;
     
    void loop() {
      delay(1000);
      
      reading = scale.get_units();
      Serial.println(reading, 1);
    }