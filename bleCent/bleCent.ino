#include <ArduinoBLE.h>
int thumbVal=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  BLE.begin();
 // if(!BLE.begin()){
 //   Serial.println("starting BLE failed.");
  Serial.println("BLE Central - Glove");
  BLE.scanForUuid("2fb70000-e6e7-4b12-92fd-c75313df3ce4");
}

void loop() {
  // put your main code here, to run repeatedly:
  BLEDevice peripheral = BLE.available();
  
  if (peripheral){
    Serial.print("Found ");
    Serial.print(peripheral.address());
    Serial.print(" '");
    Serial.print(peripheral.localName());
    Serial.print("' ");
    Serial.println(peripheral.advertisedServiceUuid());
    
    BLE.stopScan();
    controlled(peripheral);
    BLE.scanForUuid("2fb70000-e6e7-4b12-92fd-c75313df3ce4");

  if (peripheral.localName()!="glove"){
    return;
  }
  //BLE.stopScan();
  
  
 }
}

void controlled(BLEDevice peripheral){
  Serial.println("Connecting to peripheral...");
  if (peripheral.connect()) {
    Serial.println("Connected");
    }
    else {
      Serial.println("Failed");
      return;
      }
  Serial.println("Discovering attributes...");
  if (peripheral.discoverAttributes()) {
    Serial.println("Attributes discovered"); 
    }
    else {
      Serial.println("No attributes discovered");
      peripheral.disconnect();
      return;
    }
    Serial.println("Discovering the glove characteristics...");
    BLECharacteristic thumb = peripheral.characteristic ("2fb70000-e6e7-4b12-92fd-c75313df3ce4");
    if (thumb) {
      while (peripheral.connected()) {
      int newThumbVal= Serial.read();
      if (thumbVal != newThumbVal){
        thumbVal=newThumbVal;
        Serial.println(thumbVal);
        delay(100);
          }
        }
      }
     else if (!thumb){
      Serial.println("no glove characteristics");
      peripheral.disconnect();
      return;
      }
    else if(!thumb.canWrite()){
      Serial.println("no writable glove characteristics");
      peripheral.disconnect();
      return;
    }
    
 }
