#include <Wire.h>
#include <LSM303.h>

LSM303 compass;
LSM303::vector<int16_t> running_min = {32767, 32767, 32767}, running_max = {-32768, -32768, -32768};

//Initial variables
char report[80];
char mp[80];
int acl_X = 0;
int acl_Y = 0;
int acl_Z = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
//Getting the max and min values in calibration
  while (millis() < 10000) {
    compass.read();
   
    running_min.x = min(running_min.x, compass.a.x);
    running_min.y = min(running_min.y, compass.a.y);
    running_min.z = min(running_min.z, compass.a.z);
  
    running_max.x = max(running_max.x, compass.a.x);
    running_max.y = max(running_max.y, compass.a.y);
    running_max.z = max(running_max.z, compass.a.z);
    
    snprintf(report, sizeof(report), "min: {%+6d, %+6d, %+6d}    max: {%+6d, %+6d, %+6d}",
    running_min.x, running_min.y, running_min.z,
    running_max.x, running_max.y, running_max.z);
    Serial.println(report);
    
    
    delay(500);
  
  }
  delay(1000);
  Serial.println("-------------------------------------");
}

void loop() {  
  compass.read();

//  snprintf(report, sizeof(report), "A: %6d %6d %6d",
//    compass.a.x, compass.a.y, compass.a.z);
//    //compass.m.x, compass.m.y, compass.m.z);
//  Serial.println(report);

//---------------Map Testing---------------//
   
   acl_X = (map(compass.a.x, running_min.x, running_max.x, -2000, 2000)); 
   acl_Y = (map(compass.a.y, running_min.y, running_max.y, -2000, 2000));
   acl_Z = (map(compass.a.z, running_min.z, running_max.z, -2000, 2000));
   snprintf(mp, sizeof(mp), "Current Values : {%d, %d, %d}" ,acl_X,acl_Y,acl_Z );
   Serial.println(mp);






  

//-----------------------------------------------------------------//
// unsigned long XSum = 0;
// unsigned long YSum = 0;
// unsigned long ZSum = 0;
// 
// for (int i=0; i<100; i++) 
// {  
//   compass.read();
//   XSum += ((int)compass.a.x);
//   YSum += analogRead(compass.a.y);
//   ZSum += analogRead(compass.a.z);
// }
//
// //Serial.print("Accel X: "); 
//
// Serial.print((int)lsm.accelData.x); 
// Serial.print("\n");
// Serial.print("Accel X: ");
// Serial.print(map(XSum/100, XMin, XMax, -2000, 2000));
// Serial.print("\n");
//
// //Serial.print("Y: "); Serial.print((int)lsm.accelData.y);       Serial.print(" "); //Accel Y
// //Serial.print("Z: "); Serial.println((int)lsm.accelData.z);     Serial.print(" "); //Accel Z
// //Serial.print("Mag X: "); Serial.print((int)lsm.magData.x);     Serial.print(" ");
// //Serial.print("Y: "); Serial.print((int)lsm.magData.y);         Serial.print(" ");
// //Serial.print("Z: "); Serial.println((int)lsm.magData.z);       Serial.print(" ");
// delay(500);
  
  delay(500);
}
