////IN THE NAME OF ALLAH THE BEST CREATOR
//// ** Autonomous Emergency Braking System  ** /////
/// *** BY Mohammad hasan Aghanoori _ 9302274 *** ///
// **** CREATED  1395.8.19 ****//
//*****Edited 1395.10.15***9:21///

double MotorOrder=70;
#include "motorPWM.h"
#include "Laser_sensing.h"
#include "UltraSonic_sensing.h"
#include "InfraRed_sensing.h"
#include "velocity_sensing.h"
#include "Fusion_EWA.h"
#include "WiFiSend.h"

void setup(void)
{
WiFiSend_SetupFunction ();
motorPWM_SetupFunction ();
UltraSonic_sensing_SetupFunction ();
InfraRed_sensing_SetupFunction ();
Laser_sensing_SetupFunction();
velocity_sensing_SetupFunction ();
Fusion_EWA_SetupFunction ();
}

void loop() {
WiFiSend_LoopFunction (); 
Laser_sensing_LoopFunction();
InfraRed_sensing_LoopFunction ();
UltraSonic_sensing_LoopFunction ();
myservo.write(MotorOrder);
motorPWM_LoopFunction ();
MotorOrder=filteredPos;
velocity_sensing_LoopFunction ();
Fusion_EWA_LoopFunction ();
Serial.println("tt0c=");
if (TTC < 2) {
  Serial.println("ttc=");
  if (num < 2) {
    Serial.println("num=");
 MotorOrder=70;
} 
}
else
{MotorOrder=filteredPos;}
//WiFiSend_LoopFunction ();  
Serial.println("ttc1="); 
Serial.println("num=");
      Serial.println(num);
}


