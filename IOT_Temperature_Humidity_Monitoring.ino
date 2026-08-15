#include <ESP8266WiFi.h>

const char* ssid = "ESP8266_TEST";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  int count = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    count++;

    if (count > 20) {
      Serial.println("\nFAILED");
      return;
    }
  }

  Serial.println("\nCONNECTED");
  Serial.println(WiFi.localIP());
}

void loop() {}