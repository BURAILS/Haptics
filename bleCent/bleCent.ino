#include <ArduinoBLE.h>

  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  BLE.begin();
  Serial.println("BLE Central - Test");
  BLE.scanForUuid("2fb70000-e6e7-4b12-92fd-c75313df3ce4");
}

void loop() {
  // put your main code here, to run repeatedly:
  BLEDevice peripheral = BLE.available();
  
  if(peripheral){
    Serial.println("Found: " + peripheral.address() + ", " + peripheral.localName() + ", " + peripheral.advertisedServiceUuid());
    BLE.stopScan();
    BLE.scanForUuid("2fb70000-e6e7-4b12-92fd-c75313df3ce4");
  }
}
