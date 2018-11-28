// Запуск модуля в режиме точки доступа
bool StartAPMode(){
  WiFi.disconnect(); // отключаем модуль
  WiFi.mode(WIFI_AP); // устанавливаем режим точки доступа
  WiFi.softAPConfig(apIP, apIP, IPAddress(255,255,255,0));
  WiFi.softAP(_ssidAP.c_str(), _passwordAP.c_str());
  return true;
}


void WIFI_init(){

  // пробуем подключится к точке доступа
  WiFi.mode(WIFI_STA); // переводим модуль в рехим "подключится к точке доступа"
  byte tries = 11; // количеество попыток подключения
  WiFi.begin(_ssid.c_str(), _password.c_str()); // стартуем модуль

  while(--tries && WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }

  if(WiFi.status() != WL_CONNECTED){
    // если попытки подключится не увенчались успехом
    // запускаемся в режиме точки доступа
    Serial.println("");
    Serial.print("Unable to connect to ");
    Serial.println(_ssid.c_str());
    
    Serial.print("Starting as AP: ");
    Serial.println(_ssidAP.c_str());

    StartAPMode();
    
  } else {

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}


