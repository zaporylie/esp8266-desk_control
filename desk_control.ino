#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>
#include <EEPROM.h>

#define DOWN 13
#define UP 12

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  WiFiManager wifi;
  wifi.autoConnect("AutoConnectAP");

  pinMode(DOWN, OUTPUT);
  pinMode(UP, OUTPUT);

  server.on("/up", [](){
    digitalWrite(UP, 1);
    delay(1000);
    digitalWrite(UP, 0);
    server.send(200, "text/plain", "OK");
  });

  server.on("/down", [](){
    digitalWrite(DOWN, 1);
    delay(1000);
    digitalWrite(DOWN, 0);
    server.send(200, "text/plain", "OK");
  });
  
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
