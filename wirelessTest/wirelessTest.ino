#include <math.h>
#include <ArduinoBLE.h>

BLEService ledService("2fb70000-e6e7-4b12-92fd-c75313df3ce4"); // BLE LED Service
BLEByteCharacteristic switchCharacteristic("2fb70001-e6e7-4b12-92fd-c75313df3ce4", BLERead | BLEWrite);

const float VCC = 3.3;  // Measured voltage of Arduino 5V line 

const float R_DIV = 51000; // Measured resistance of 47k resistor

const float STRAIGHT_RESISTANCE = 11700; // resistance when straight 

const float BEND_RESISTANCE = 20000; // resistance at 90 deg



void setup() { 
  Serial.begin(9600); // Startup the serial communications at 9600 baud }
  BLE.begin();                                        // begin initialization
  BLE.setLocalName("Flex Sensor");                    // define local name
  BLE.setAdvertisedService(ledService);               // set advertised local name and service UUID:
  ledService.addCharacteristic(switchCharacteristic); // add the characteristic to the service
  BLE.addService(ledService);                         // add service
  switchCharacteristic.writeValue(0);                 // set the initial value for the characeristic:
  BLE.advertise(); Serial.println("BLE LED Peripheral");
}

void loop() { 

  int flexADC = analogRead(A0);
  
  float flexV = flexADC * VCC / 1023.0;
  

  float flexR = R_DIV * (VCC / flexV - 1.0);
  
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);

  Serial.print("FLEX SENSOR 1: ") ; Serial.print(angle); Serial.print(","); Serial.println(flexR);
  delay(500);

/*
   //FLEX SENSOR 2
  flexADC = analogRead(A1);
  flexV = flexADC * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);
  angle = map(flexR, 9500, 18500, 0, 90.0);
  Serial.print("FLEX SENSOR 2: ") ; Serial.print(angle); Serial.print(","); Serial.println(flexR);

  
   //FLEX SENSOR 3
  flexADC = analogRead(A2);
  flexV = flexADC * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);
  angle = map(flexR, 11000, 18000, 0, 90.0);
  Serial.print("FLEX SENSOR 3: ") ; Serial.print(angle); Serial.print(","); Serial.println(flexR);


   //FLEX SENSOR 4
  flexADC = analogRead(A3);
  flexV = flexADC * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);
  angle = map(flexR,9800 , 17300, 0, 90.0);
  Serial.print("FLEX SENSOR 4: ") ; Serial.print(angle); Serial.print(","); Serial.println(flexR);


  
   //FLEX SENSOR 5
  flexADC = analogRead(A4);
  flexV = flexADC * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);
  angle = map(flexR, 9500, 17200, 0, 90.0);
  Serial.print("FLEX SENSOR 5: ") ; Serial.print(angle); Serial.print(","); Serial.println(flexR);


  delay(1000); // Read the sensor at 4Hz.
  */
}
