#include <ArduinoBLE.h>
BLEService gloveService ("2fb70000-e6e7-4b12-92fd-c75313df3ce4");
BLEIntCharacteristic thumb("2fb70001-e6e7-4b12-92fd-c75313df3ce4", BLERead | BLEWrite);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  if(!BLE.begin()){
    Serial.println("starting BLE failed.");
  }
  BLE.setLocalName("GLOVE");
  BLE.setAdvertisedService(gloveService);
  gloveService.addCharacteristic(thumb);
  BLE.addService(gloveService);
  thumb.writeValue(0);
  BLE.advertise(); 
  Serial.println("BLE Glove Peripheral");

}

void loop() {
  // put your main code here, to run repeatedly:
  BLEDevice central = BLE.central();
  if (central){
    Serial.println("Connected to central: " + central.address());
    //Serial.println(thumb.value());
    
  Serial.println(thumb);  
  while (central.connected()) {
   thumb.writeValue(thumb + 1);
   Serial.println(thumb);
  }
 }
}
