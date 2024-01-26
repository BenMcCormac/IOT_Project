/*Code by Ben McCormack------*/
/*15/Nov/2023----------------*/
/*IOT Apiary-----------------*/


//Declare Libraries
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "homepage.h"
#include <DFRobot_DHT11.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#include <Servo.h>
#include "rgb_lcd.h"

//DHT11 Setup
DFRobot_DHT11 DHT;
#define DHT11_PIN 14

#define PN532_IRQ   (18)
#define PN532_RESET (23)
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

Servo servo1;
static const int servoPin = 4;

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

const char* ssid = "Humm";
const char* password = "g00416547";

WebServer server(80);

void setup(void) {
  lcd.clear();

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  lcd.setRGB(colorR, colorG, colorB);

  while (!Serial) delay(10); // for Leonardo/Micro/Zero

  nfc.begin();

  //Error catching
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print(versiondata);
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }

  servo1.attach(servoPin);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(20);//allow the cpu to switch to other tasks
  
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };	// Buffer to store the returned UID
  uint8_t uidLength;				// Length of the UID (4 or 7 bytes depending on ISO14443A card type)

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  nfc.PrintHex(uid, uidLength);
  Serial.println("");

  if(uidLength == 4)
  {
    // We probably have a Mifare Classic card ...
    Serial.println("Seems to be a Mifare Classic card (4 byte UID)");

    // Now we need to try to authenticate it for read/write access
    // Try with the factory default KeyA: 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF
    Serial.println("Authenticating block 4 with KEYA value");
    uint8_t keya[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

    success = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);

    //To test to see if it is a blocking function
    //lcd.print("No Block");
    if(success)
    {
      motor();
    }
  }
}
