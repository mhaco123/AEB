////IN THE NAME OF ALLAH THE BEST CREATOR

double MotorOrder=93;
#include "motorPWM.h"

#include "Laser_sensing.h"
#include "UltraSonic_sensing.h"
#include "InfraRed_sensing.h"
#include "velocity_sensing.h"

#include "WiFiSend.h"
void setup(void)
{
WiFiSend_SetupFunction ();
motorPWM_SetupFunction ();
Laser_sensing_SetupFunction();
velocity_sensing_SetupFunction ();
UltraSonic_sensing_SetupFunction ();
InfraRed_sensing_SetupFunction ();
}
void loop() {
if (num < 100) {
 MotorOrder=50;
} else
{MotorOrder=filteredPos;}
Laser_sensing_LoopFunction();
myservo.write(MotorOrder);
motorPWM_LoopFunction ();
velocity_sensing_LoopFunction ();
UltraSonic_sensing_LoopFunction ();
InfraRed_sensing_LoopFunction ();
WiFiSend_LoopFunction ();   

      Serial.println("num=");
      Serial.println(num);
}


