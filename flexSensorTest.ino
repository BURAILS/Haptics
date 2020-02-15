const int FLEX_PIN = A0; 
// Pin connected to voltage divider output
// Measure the voltage at 5V and the actual resistance of your 
// 47k resistor, and enter them below. This makes the angle 
// calculation much more accurate. 

const float VCC = 4.8;  // Measured voltage of Arduino 5V line 

const float R_DIV = 51000; // Measured resistance of 47k resistor

// Upload the code and try to determine an average value of 
// resistance when the sensor is not bent, and when it is 
// bent at 90 degrees. Enter those and reload the code for 
// a more accurate angle estimate. 

const float STRAIGHT_RESISTANCE = 11700; // resistance when straight 

const float BEND_RESISTANCE = 20000; // resistance at 90 deg

void setup() { 
  Serial.begin(9600); // Startup the serial communications at 9600 baud }
}

void loop() { 
  //FLEX SENSOR 1
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
  Serial.print("FLEX SENSOR 1: ") ; Serial.print(angle); Serial.print(","); Serial.println(flexR);
 // delay(250);

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
}
