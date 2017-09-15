#include <EspBLE.h>

EspBLE esp;

const uint8_t SERVICE_UUID[16] = {
    0x01, 0x02, 0x03, 0x04,
    0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c,
    0x0d, 0x0e, 0x0f, 0x10};

/*
const uint16_t SERVICE_UUID = 0xAAAA;
*/

void setup(){
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    //esp.setServiceUUID(SERVICE_UUID);
    esp.setServiceUUID(SERVICE_UUID, sizeof(SERVICE_UUID));
    esp.init();


}
void loop(){
  
}
