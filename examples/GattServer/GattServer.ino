#include <EspBLE.h>

EspBLE esp;

const uint8_t SERVICE_UUID[16] = {
    0x01, 0x02, 0x03, 0x04,
    0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c,
    0x0d, 0x0e, 0x0f, 0x10
};

const uint8_t CHAR_UUID[16] = {
    0x01, 0x02, 0x03, 0x04,
    0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c,
    0x0d, 0x0e, 0x0f, 0x10
};

void setup(){
    Serial.begin(115200);
    esp.setServiceUUID(SERVICE_UUID, sizeof(SERVICE_UUID));
    esp.setCharUUID(CHAR_UUID, sizeof(CHAR_UUID));
    esp.init();


}

uint8_t d = 0;
uint8_t buff[2] = {0, 0}; 
void loop(){

  //Send Data to Client (Notify Request)
  Serial.print("Notify Request: ");
  for(int i = 0; i < sizeof(buff); i++){
    buff[i] = d;
    Serial.print(d);
    Serial.print(" ");
  }
  Serial.println();
  
  esp.write(buff, sizeof(buff));
  d++;

  //Receive Data from Client
  uint8_t c;
  uint8_t len;
  if(len = esp.available()){
    Serial.print("Detect Write Request: ");
    for(int i = 0; i < len; i++){
      c = esp.read();
      Serial.print(c);
      Serial.print(" ");
    }
    Serial.println();    
  }

  delay(1000);
  
}
