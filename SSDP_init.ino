void SSDP_init(){
  HTTP.on("/description.xml", HTTP_GET, []()
  {
    SSDP.schema(HTTP.client());
  });

 SSDP.setDeviceType("upnp:rootdevice");
  SSDP.setSchemaURL("description.xml");
  SSDP.setHTTPPort(80);
  SSDP.setName(SSDP_Name);
  SSDP.setSerialNumber("001788102201");
  SSDP.setURL("/");
  SSDP.setModelName("SSDP-test");
  SSDP.setModelNumber("000000000001");
  SSDP.setModelURL("http://http://redsail.club");
  SSDP.setManufacturer("Nick Korbut");
  SSDP.setManufacturerURL("http://http://redsail.club");
  SSDP.begin();
}

