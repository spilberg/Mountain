/*
 * Инициализация Веб сервера
 */

void HTTP_init(void){
 // HTTP.onNotFound(handleNotFound); // хендл 
 // HTTP.on("/", handleRoot);
  HTTP.on("/restart", handle_Restart);
  HTTP.on("/configs.json", handle_ConfigJSON);
  HTTP.on("/ssdp", handle_Set_Ssdp);
  HTTP.on("/ssid", handle_Set_Ssid);
  HTTP.on("/ssidap", handle_Set_Ssidap);

  HTTP.begin();
}

/* void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += HTTP.uri();
  message += "\nMethod: ";
  message += (HTTP.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += HTTP.args();
  message += "\n";

  for(uint8_t i=0; i<HTTP.args(); i++  ){
    message += " " + HTTP.argName(i) + ": " + HTTP.arg(i) + "\n";
  }

  HTTP.send(404, "text/plain", message);
}*/

void handle_Set_Ssdp(){
  SSDP_Name = HTTP.arg("ssdp");
  saveConfig();
  HTTP.send(200, "text/plain", "OK");
}

void handle_Set_Ssid(){
  _ssid = HTTP.arg("ssid");
  _password = HTTP.arg("password");
  saveConfig();
  HTTP.send(200, "text/plain", "OK");
}

void handle_Set_Ssidap(){
  _ssidAP = HTTP.arg("ssidAP");
  _passwordAP = HTTP.arg("passwordAP");
  saveConfig();
  HTTP.send(200, "text/plain", "OK");
}

void saveConfig(){
  
}

void handle_ConfigJSON(){
   String json = "{";  // Формировать строку для отправки в браузер json формат
  //{"SSDP":"SSDP-test","ssid":"home","password":"i12345678","ssidAP":"WiFi","passwordAP":"","ip":"192.168.0.101"}
  // Имя SSDP
  json += "\"SSDP\":\"";
  json += SSDP_Name;
  // Имя сети
  json += "\",\"ssid\":\"";
  json += _ssid;
  // Пароль сети
  json += "\",\"password\":\"";
  json += _password;
  // Имя точки доступа
  json += "\",\"ssidAP\":\"";
  json += _ssidAP;
  // Пароль точки доступа
  json += "\",\"passwordAP\":\"";
  json += _passwordAP;
  // Времянная зона
  json += "\",\"timezone\":\"";
  json += timezone;
  // IP устройства
  json += "\",\"ip\":\"";
  json += WiFi.localIP().toString();
  json += "\"}";
  HTTP.send(200, "text/json", json);
}

void handle_Restart(){
  String restart = HTTP.arg("device");
  if (restart == "ok"){
    HTTP.send(200, "text/plain", "Device is Restarted");
    delay(2000);
    ESP.restart();
  } else {
    HTTP.send(200, "text/plain", "Don`t restart");
  }
  
}

