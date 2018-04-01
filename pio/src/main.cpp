    /*
     *  Simple HTTP get webclient test
     */
     
    #include <ESP8266WiFi.h>
    #include "HX711.h"

    //////////////////////////////////////////////////////////////////////////////////
    // Define switch pin
    //////////////////////////////////////////////////////////////////////////////////
    #define MODE_PIN 2
    //////////////////////////////////////////////////////////////////////////////////
    // Define scale amp data pins
    //////////////////////////////////////////////////////////////////////////////////
    #define DOUT SDA
    #define SCL1 SCL
    ///////////////////////////////////////////////////////////////////////////////////
    // Assign mode pin
    ///////////////////////////////////////////////////////////////////////////////////
    uint32_t switchPin = MODE_PIN;
    ///////////////////////////////////////////////////////////////////////////////////
    // mode is used to run the program either in measurement or
    // calibration mode.  This avoids having to run two separate
    // sketches.
    ///////////////////////////////////////////////////////////////////////////////////
    bool mode = true; // True mode is measurement.
    ///////////////////////////////////////////////////////////////////////////////////
    // mode is used to run the program either in measurement or
    // calibration mode.  This avoids having to run two separate
    // sketches.
    ///////////////////////////////////////////////////////////////////////////////////
    HX711 scale(DOUT, SCL1);
    ///////////////////////////////////////////////////////////////////////////////////
    // Define calibration factor.  This can be adjusted in calibration mode by pressing
    // a/z or +/- keys
    ///////////////////////////////////////////////////////////////////////////////////
    float calibration_factor = -21050;
     

    const char* ssid     = "Aspen 2.4";
    const char* password = "1029384756";
     
    const char* host = "wifitest.adafruit.com";
     
    void setup() {
      Serial.begin(115200);
      delay(100);
     
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
    }
     
    int value = 0;
     
    void loop() {
      delay(5000);
      ++value;
     
      Serial.print("connecting to ");
      Serial.println(host);
      
      // Use WiFiClient class to create TCP connections
      WiFiClient client;
      const int httpPort = 80;
      if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
      }
      
      // We now create a URI for the request
      String url = "/testwifi/index.html";
      Serial.print("Requesting URL: ");
      Serial.println(url);
      
      // This will send the request to the server
      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                   "Host: " + host + "\r\n" + 
                   "Connection: close\r\n\r\n");
      delay(500);
      
      // Read all the lines of the reply from server and print them to Serial
      while(client.available()){
        String line = client.readStringUntil('\r');
        Serial.print(line);
      }
      
      Serial.println();
      Serial.println("closing connection");
    }