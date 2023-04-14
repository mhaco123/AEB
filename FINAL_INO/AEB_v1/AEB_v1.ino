///////* IN THE NAME OF ALLAH THE BENEFICENT THE MERCIFUL */////
//// ** Autonomous Emergency Braking System  ** /////
/// *** BY Mohammad hasan Aghanoori _ 9302274 *** ///
// **** CREATED  1395.8.19 ****//
#include "arduino.h"
#include "Laser_sensing.h"
#include "UltraSonic_sensing.h"
#include "InfraRed_sensing.h"
#include "velocity_sensing.h"
#include "Fusion_EWA.h"
#include "DecisionMaking.h"
//#include "motorPWM.h"
//#include "WiFiSend.h"
void setup() {
  Serial.begin(115200);
  Laser_sensing_SetupFunction ();
  UltraSonic_sensing_SetupFunction ();
  InfraRed_sensing_SetupFunction ();
  velocity_sensing_SetupFunction ();
  Fusion_EWA_SetupFunction ();
  DecisionMaking_SetupFunction ();
  //motorPWM_SetupFunction ();
  //WiFiSend_SetupFunction ();
}
void loop() {

  Laser_sensing_LoopFunction ();
  UltraSonic_sensing_LoopFunction ();
  InfraRed_sensing_LoopFunction ();
  velocity_sensing_LoopFunction ();
  Fusion_EWA_LoopFunction ();
  DecisionMaking_LoopFunction ();
  //motorPWM_LoopFunction ();
  //WiFiSend_LoopFunction ();
}
  
