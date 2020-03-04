#include <ArduinoBLE.h>
#include <math.h>

const float VCC = 3.3;  // Measured voltage of Arduino 5V line 

const float R_DIV = 51000; // Measured resistance of 47k resistor

// Upload the code and try to determine an average value of 
// resistance when the sensor is not bent, and when it is 
// bent at 90 degrees. Enter those and reload the code for 
// a more accurate angle estimate. 

const float STRAIGHT_RESISTANCE = 11700; // resistance when straight 

const float BEND_RESISTANCE = 20000; // resistance at 90 deg

BLEService Glove("2fb70000-e6e7-4b12-92fd-c75313df3ce4");
BLEFloatCharacteristic Thumb("2fb70001-e6e7-4b12-92fd-c75313df3ce4", BLERead);

void setup() {
  Serial.begin(9600);

  BLE.begin();
  BLE.setLocalName("Glove");
  BLE.setAdvertisedService(Glove);
  Glove.addCharacteristic(Thumb);
  BLE.addService(Glove);
  Thumb.writeValue(0);
  BLE.advertise();
  Serial.println("BLE Glove Peripheral");  
}

void loop() {
   /* //FLEX SENSOR 1
  // Read the ADC 
  int flexADC = analogRead(A0);
  
  // Calculate the voltage that the ADC read 
  float flexV = flexADC * VCC / 1023.0;
  
  // Calculate the resistance of the flex sensor 
  float flexR = R_DIV * (VCC / flexV - 1.0);
  
  // Use the calculated resistance to estimate the sensor's 
  // bend angle my mapping the measured resistance onto the 
  // known resistances at zero and ninety degrees of bend. 
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
  
  // Send the results back to the computer formatted as a comma delimited line.
  Serial.print("FLEX SENSOR 1: ");
  Serial.print(angle);
  Serial.print(",");
  Serial.println(flexR);
  Thumb.writeValue(angle);
  
  
  delay(500);*/
}
