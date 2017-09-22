#include <EspBLE.h>

EspBLE esp;

const uint8_t SERVICE_UUID[16] = {
    0x01, 0x02, 0x03, 0x04,
    0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c,
    0x0d, 0x0e, 0x0f, 0x10
};


//const uint16_t SERVICE_UUID = 0xAAAA;

//const uint16_t CHAR_UUID = 0x1122;

const uint8_t CHAR_UUID[16] = {
    0x01, 0x02, 0x03, 0x04,
    0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c,
    0x0d, 0x0e, 0x0f, 0x10
};

void setup(){
    Serial.begin(115200);
    //pinMode(LED, OUTPUT);
    //digitalWrite(LED, LOW);
    //esp.setServiceUUID(SERVICE_UUID);
    esp.setServiceUUID(SERVICE_UUID, sizeof(SERVICE_UUID));
    //esp.setCharUUID(CHAR_UUID);
    esp.setCharUUID(CHAR_UUID, sizeof(CHAR_UUID));
    esp.init();


}
uint8_t d = 0;
uint8_t buff[2] = {0, 0}; 
void loop(){
  //esp.write(d);
  for(int i = 0; i < sizeof(buff); i++){
    buff[i] = d;
  }
  
  esp.write(buff, sizeof(buff));
  d++;
  
  uint8_t c;
  uint8_t len;
  if(len = esp.available()){
    for(int i = 0; i < len; i++){
      c = esp.read();
      Serial.print(c);
      Serial.print(" ");
    }
  }
  Serial.println();
  delay(1000);
  
}
