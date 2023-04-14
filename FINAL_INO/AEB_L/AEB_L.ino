////IN THE NAME OF ALLAH THE BEST CREATOR
//// ** Autonomous Emergency Braking System  ** /////
/// *** BY Mohammad hasan Aghanoori _ 9302274 *** ///
// **** CREATED  1395.8.19 ****//
//*****Edited 1395.10.15***9:21///

#include "Laser_sensing.h"

#include "WiFiSend.h"

void setup(void)
{
WiFiSend_SetupFunction ();
Laser_sensing_SetupFunction();
}

void loop() {

Laser_sensing_LoopFunction();
WiFiSend_LoopFunction ();
} 
