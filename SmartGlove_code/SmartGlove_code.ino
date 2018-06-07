/*
Sign Language Translator, 
http://romanakozak.com/sign-language-translator/

Project by: 
Made with Arduino
*/
#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); // RX | TX
char data = 0; 


// These constants won't change:
//const int sensorPinTHUMB = A0;    // pin that the THUMB flex sensor is attached to
const int sensorPinINDEX = A1;    // pin that the INDEX flex sensor is attached to
const int sensorPinMIDDLE = A2;    // pin that the MIDDLE flex sensor is attached to
//const int sensorPinRING = A3;    // pin that the RING flex sensor is attached to
//const int sensorPinPINKEY = A4;    // pin that the PINKEY flex sensor is attached to
//const int xPin = 2;		// X output of the accelerometer
//const int yPin = 3;		// y output of the accelerometer


const int ledPinBLUE = 4;        // pin that the LED is attached to
//const int ledPinGREEN = 5;        // pin that the LED is attached to


// variables:
//int sensorValueTHUMB = 0;         // the sensor value
int sensorValueINDEX = 0;          // the sensor value
int sensorValueMIDDLE = 0;         // the sensor value
//int sensorValueRING = 0;         // the sensor value
//int sensorValuePINKEY = 0;         // the sensor value

//int sensorMinTHUMB = 1023;        // minimum sensor value
int sensorMinINDEX = 1023;        // minimum sensor value
int sensorMinMIDDLE = 1023;        // minimum sensor value
//int sensorMinRING = 1023;        // minimum sensor value
//int sensorMinPINKEY = 1023;        // minimum sensor value

//int sensorMaxTHUMB = 0;           // maximum sensor value
int sensorMaxINDEX = 0;           // maximum sensor value
int sensorMaxMIDDLE = 0;           // maximum sensor value
//int sensorMaxRING = 0;           // maximum sensor value
//int sensorMaxPINKEY = 0;           // maximum sensor value


void setup() {
  
  // turn on LED to signal the start of the calibration period:
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(18, OUTPUT);
//  pinMode(xPin, INPUT);
//  pinMode(yPin, INPUT);
  
  digitalWrite(ledPinBLUE, HIGH); 
  
  Serial.begin (9600);
  BTserial.begin(9600);

  // calibrate during the first five seconds 
  while (millis() < 5000) {
//      sensorValueTHUMB = analogRead(sensorPinTHUMB);
      sensorValueINDEX = analogRead(sensorPinINDEX);
      sensorValueMIDDLE = analogRead(sensorPinMIDDLE);
//      sensorValueRING = analogRead(sensorPinRING);
//      sensorValuePINKEY = analogRead(sensorPinPINKEY);
//--------------------------------------------------
    // record the maximum sensor value
//    if (sensorValueTHUMB > sensorMaxTHUMB) {
//      sensorMaxTHUMB = sensorValueTHUMB;
//    }
       // record the maximum sensor value
    if (sensorValueINDEX > sensorMaxINDEX) {
      sensorMaxINDEX = sensorValueINDEX;
    }
   // record the maximum sensor value
    if (sensorValueMIDDLE > sensorMaxMIDDLE) {
      sensorMaxMIDDLE = sensorValueMIDDLE;
    }
    // record the maximum sensor value
//    if (sensorValueRING > sensorMaxRING) {
//      sensorMaxRING = sensorValueRING;
//    }
    // record the minimum sensor value
//    if (sensorValueRING < sensorMinRING) {
//      sensorMinRING = sensorValueRING;
//    }
     // record the maximum sensor value
//    if (sensorValuePINKEY > sensorMaxPINKEY) {
//      sensorMaxPINKEY = sensorValuePINKEY;
//    }
    //--------------------------------------------------------

    // record the minimum sensor value
//    if (sensorValueTHUMB < sensorMinTHUMB) {
//      sensorMinTHUMB = sensorValueTHUMB;
//    }
    
       // record the minimum sensor value
    if (sensorValueINDEX < sensorMinINDEX) {
      sensorMinINDEX = sensorValueINDEX;
    }
        // record the minimum sensor value
    if (sensorValueMIDDLE < sensorMinMIDDLE) {
      sensorMinMIDDLE = sensorValueMIDDLE;
    }
    // record the minimum sensor value
//    if (sensorValueRING < sensorMinRING) {
//      sensorMinRING = sensorValueRING;
//    }
    // record the minimum sensor value
//    if (sensorValuePINKEY < sensorMinPINKEY) {
//      sensorMinPINKEY = sensorValuePINKEY;
//    }
  }

  // signal the end of the calibration period
  digitalWrite(ledPinBLUE, LOW);
 
//  
//  Serial.print ("LowTHUMB = ");
//  Serial.println (sensorMinTHUMB);
//  Serial.print ("HighTHUMB = ");
//  Serial.println (sensorMaxTHUMB);
  
  Serial.println ("             ");
  
  Serial.print ("LowINDEX = ");
  Serial.println (sensorMinINDEX);
  Serial.print ("HighINDEX = ");
  Serial.println (sensorMaxINDEX);
  
  Serial.println ("             "); 
  
  Serial.print ("LowMIDDLE = ");
  Serial.println (sensorMinMIDDLE);
  Serial.print ("HighMIDDLE = ");
  Serial.println (sensorMaxMIDDLE);
  
  Serial.println ("             "); 
  
//   Serial.print ("LowRING = ");
//  Serial.println (sensorMinRING);
//  Serial.print ("HighRING = ");
//  Serial.println (sensorMaxRING);
//  
//  Serial.println ("             "); 
//  
//  Serial.print ("LowPINKEY = ");
//  Serial.println (sensorMinPINKEY);
//  Serial.print ("HighPINKEY = ");
//  Serial.println (sensorMaxPINKEY);
  
  Serial.println ("             ");


   
  delay (1000);
}

void loop() {
  
//  // variables to read the pulse widths:
//  int pulseX, pulseY;
//  // variables to contain the resulting accelerations
//  int accelerationX, accelerationY;
  
  // read pulse from x- and y-axes:
//  pulseX = pulseIn(xPin,HIGH);  
//  pulseY = pulseIn(yPin,HIGH);    
  // convert the pulse width into acceleration
  // accelerationX and accelerationY are in milli-g's: 
  // earth's gravity is 1000 milli-g's, or 1g.
//  accelerationX = ((pulseX / 10) - 500) * 8;
//  accelerationY = ((pulseY / 10) - 500) * 8;
  
  // read the sensor:
//  sensorValueTHUMB = analogRead(sensorPinTHUMB);
  sensorValueINDEX = analogRead(sensorPinINDEX);
  sensorValueMIDDLE = analogRead(sensorPinMIDDLE);
//  sensorValueRING = analogRead(sensorPinRING);
//  sensorValuePINKEY = analogRead(sensorPinPINKEY);

  // apply the calibration to the sensor reading
//  sensorValueTHUMB = map(sensorValueTHUMB, sensorMinTHUMB, sensorMaxTHUMB, 1, 255);
  sensorValueINDEX = map(sensorValueINDEX, sensorMinINDEX, sensorMaxINDEX, 1, 255);
  sensorValueMIDDLE = map(sensorValueMIDDLE, sensorMinMIDDLE, sensorMaxMIDDLE, 1, 255);
//  sensorValueRING = map(sensorValueRING, sensorMinRING, sensorMaxRING, 1, 255);
//  sensorValuePINKEY = map(sensorValuePINKEY, sensorMinPINKEY, sensorMaxPINKEY, 1, 255);

  // in case the sensor value is outside the range seen during calibration
//  sensorValueTHUMB = constrain(sensorValueTHUMB, 1, 255);
  sensorValueINDEX = constrain(sensorValueINDEX, 1, 255);
  sensorValueMIDDLE = constrain(sensorValueMIDDLE, 1, 255);
//  sensorValueRING = constrain(sensorValueRING, 1, 255);
//  sensorValuePINKEY = constrain(sensorValuePINKEY, 1, 255);
  
//  Serial.println ("-------------------");
//  Serial.print ("sensorValue-THUMB = ");
//  Serial.println (sensorValueTHUMB);
  
  Serial.print ("sensorValue-INDEX = ");
  Serial.println (sensorValueINDEX);
  
  //Bluetooth data sending 
  BTserial.print("sensorValueINDEX");
  BTserial.print(";");
  
  Serial.print ("sensorValue-MIDDLE = ");
  Serial.println (sensorValueMIDDLE);
  
  //Bluetooth data sending
  BTserial.print("          ");
  BTserial.print("sensorValueINDEX");
  BTserial.print(";");
//  
//  Serial.print ("sensorValue-RING = ");
//  Serial.println (sensorValueRING);
//  
//  Serial.print ("sensorValue-PINKEY = ");
//  Serial.println (sensorValuePINKEY);
//  
//  Serial.print ("acceleration-X = ");
//  Serial.println(accelerationX);
//  
//  Serial.print ("acceleration-y = ");
//  Serial.println(accelerationY);
  
   Serial.println ("   ");
   Serial.println (" ");
  
 
//if the glove is tilted up turn on the green led
  
//  if (accelerationX > 650) {
//    
//    digitalWrite (ledPinGREEN, HIGH);
//  }
//  
//  else {
//   digitalWrite (ledPinGREEN, LOW); 
//  }
  
  //if the glove is tilted to the right turn on the blue led
  
//  if (accelerationY > 500) {
//    
//    digitalWrite (ledPinBLUE, HIGH);
//  }
//  
//  else {
//   digitalWrite (ledPinBLUE, LOW); 
//  }
  
    // if the glove is tilted to the left turn on the blue led
    
//   if (accelerationY < -500) {
//    
//    digitalWrite (ledPinBLUE, HIGH);
//  }
//  
//  else {
//   digitalWrite (ledPinBLUE, LOW); 
//  }

  
  //--------------------------------LetterA-----------------------------
  
  if (sensorValueINDEX == 1 && sensorValueMIDDLE == 1) {
    
    Serial.println  ("\n");
    Serial.println ("A"); //Print letter A to serial
    Serial.println  ("        ");
    //Bluetooth data sending 
    BTserial.print("A");
    BTserial.print(";");
    
  }
  
  else {
    
  }
//  
//  //--------------------------------LetterB-----------------------------
//  
//  if (sensorValueTHUMB > 200 && sensorValueINDEX > 200 && sensorValueMIDDLE > 200 && sensorValueRING > 200 && accelerationX > 650 ) {
//    
//    Serial.println ("B"); //Print letter B to serial
//    Serial.println  ("        ");
//    
//  }
//  
//  else {
//    
//  }
//  
//  //--------------------------------LetterC-----------------------------
//  
//  
//  if (sensorValueTHUMB < 200 && sensorValueTHUMB > 20 && sensorValueINDEX < 200 && sensorValueINDEX > 20 && sensorValueMIDDLE < 200 && sensorValueMIDDLE > 20 && sensorValueRING < 200 && sensorValueRING > 20) {
//    
//    Serial.println ("C"); //Print letter C to serial
//    Serial.println  ("        ");
//   
//  }
//  
//  else {
//   
//  }
//  
//  //--------------------------------LetterD-----------------------------
//  
//  
//  if (sensorValueTHUMB == 1 && sensorValueINDEX > 100 && sensorValueMIDDLE == 1 && sensorValueRING == 1 && accelerationX > 650) {
//    
//    Serial.println ("D"); //Print letter D to serial
//    Serial.println  ("        ");
//    
//  }
//  
//  else {
//   
//  }
//  
//  //--------------------------------LetterE-----------------------------
//  
//  
//  if (sensorValueTHUMB == 1 && sensorValueINDEX == 1 && sensorValueMIDDLE == 1 && sensorValueRING == 1 && accelerationX > 650) {
//    
//    Serial.println ("E"); //Print letter E to serial
//    Serial.println  ("        ");
//    
//  }
//  
//  else {
//   
//  }
//  
//  //--------------------------------LetterF-----------------------------
//  
//  
//  if (sensorValueTHUMB == 1 && sensorValueINDEX == 1 && sensorValueMIDDLE > 200 && sensorValueRING > 200 && accelerationX > 650) {
//    
//    Serial.println ("F"); //Print letter F to serial
//    Serial.println  ("        ");
//    
//  }
//  
//  else {
//   
//  }
//  
//  //--------------------------------LetterG-----------------------------
//  
//  
//  if (sensorValueTHUMB > 150 && sensorValueINDEX > 150 && sensorValueMIDDLE == 1 && sensorValueRING == 1  && accelerationX < 300) {
//    
//    Serial.println ("G"); //Print letter G to serial
//    Serial.println  ("        ");
//    
//  }
//  
//  else {
//   
//  }
//    //--------------------------------HELLO-----------------------------
//  
//  if (sensorValueTHUMB > 200 && sensorValueINDEX > 200 && sensorValueMIDDLE > 200 && sensorValueRING > 200 && accelerationX > 650 ) {
//    
//    Serial.println ("H"); //Print letter H to serial
//    Serial.println  ("        ");
//    
//  }
//  
//  else {
//   
//  }
  
  
  delay (1000);
  
   

}
