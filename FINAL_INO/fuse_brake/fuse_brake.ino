
#include "motorPWM.h"
#include "Laser_sensing.h"
#include "UltraSonic_sensing.h"
#include "InfraRed_sensing.h"
#include "WiFiSend.h"

void setup(void)
{
WiFiSend_SetupFunction ();
motorPWM_SetupFunction ();
Laser_sensing_SetupFunction();
UltraSonic_sensing_SetupFunction ();
InfraRed_sensing_SetupFunction ();
}
void loop() {
  Laser_sensing_LoopFunction();
  InfraRed_sensing_LoopFunction ();
UltraSonic_sensing_LoopFunction ();
if (num < 110) {
 MotorOrder=30;
} else
{MotorOrder=filteredPos;}
myservo.write(MotorOrder);
motorPWM_LoopFunction ();
WiFiSend_LoopFunction ();  
      Serial.println("num=");
      Serial.println(num); 
      Serial.println("ultrasound=");
      Serial.println(mu1); 
}


