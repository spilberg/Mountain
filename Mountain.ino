/*
 * RGB Mountain
 */

#include <ESP8266WiFi.h> //Подключаем библиотеку вайфай
#include <ESP8266WebServer.h> //Библиотека веб сервера
#include <ESP8266SSDP.h> // Библиотека SSDP
#include <FS.h>
#include <ArduinoJson.h>


IPAddress apIP(192,168,4,1);  

ESP8266WebServer HTTP(80);

File fsUploadFile;

//String _ssid        = "Kyivstar_guest";
//String _password    = "Ukraine1";

String _ssid        = "ImSmart";
String _password    = "salosalo";
String _ssidAP      = "MountainWiFi";
String _passwordAP  = "";
String SSDP_Name    = "SSDPMountain";
int timezone = 2;

String jsonConfig = "{}";


void setup() {
  Serial.begin(115200);
  Serial.println("");

  // init file system
  Serial.println("Start FS");
  FS_init();

  Serial.println("Load Config");
  loadConfig();
  
  // start WiFi
  Serial.print("Start WiFi");
  WIFI_init();

  //
  Serial.println("Start SSDP");
  SSDP_init();

  // Start webServer
  Serial.println("Start WebServer");
  HTTP_init();
  
}

void loop() {
  HTTP.handleClient();
  delay(1);
}
