////IN THE NAME OF ALLAH THE BEST CREATOR
//// ** fusion System  ** /////
/// *** BY Mohammad hasan Aghanoori _ 9302274 *** ///
// **** CREATED  1395.10.15 , 15:30 ****//
//*****Edited 1395.10.15***9:21///

#include "Laser_sensing.h"
#include "UltraSonic_sensing.h"
#include "InfraRed_sensing.h"
#include "Fusion_EWA.h"

void setup(void)
{
UltraSonic_sensing_SetupFunction ();
InfraRed_sensing_SetupFunction ();
Laser_sensing_SetupFunction();
Fusion_EWA_SetupFunction ();
}

void loop() {
Laser_sensing_LoopFunction();
InfraRed_sensing_LoopFunction ();
UltraSonic_sensing_LoopFunction ();
Fusion_EWA_LoopFunction ();
Serial.println("X(LASER)=");
Serial.println(num);

Serial.println("X(ultrasound)=");
Serial.println(mu1);


Serial.println("X(infrared)=");
Serial.println(cm);

Serial.println("X(fusion)=");
Serial.println(f);


}


