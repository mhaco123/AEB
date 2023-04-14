////IN THE NAME OF ALLAH THE BEST CREATOR
//// ** Autonomous Emergency Braking System  ** /////
/// *** BY Mohammad hasan Aghanoori _ 9302274 *** ///
// **** CREATED  1395.8.19 ****//
//*****Edited 1395.10.15***9:21///

#include "Laser_sensing.h"
#include "UltraSonic_sensing.h"
#include "InfraRed_sensing.h"
#include "Fusion_EWA.h"
#include "WiFiSend.h"

void setup(void)
{
WiFiSend_SetupFunction ();
UltraSonic_sensing_SetupFunction ();
InfraRed_sensing_SetupFunction ();
Laser_sensing_SetupFunction();
Fusion_EWA_SetupFunction ();
}

void loop() {

Laser_sensing_LoopFunction();
InfraRed_sensing_LoopFunction ();
UltraSonic_sensing_LoopFunction ();
//Serial.println("num=");
//      Serial.println(num);
Fusion_EWA_LoopFunction ();
WiFiSend_LoopFunction ();
} 
