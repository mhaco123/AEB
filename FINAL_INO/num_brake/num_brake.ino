 
    #include "motorPWM.h"
    #include "Laser_sensing.h"
    #include "WiFiSend.h"

void setup(void)
{
WiFiSend_SetupFunction ();
motorPWM_SetupFunction ();
Laser_sensing_SetupFunction();

}
void loop() {
  Laser_sensing_LoopFunction();
if (num < 250) {
 MotorOrder=30;
} else
{MotorOrder=filteredPos;}
myservo.write(MotorOrder);
motorPWM_LoopFunction ();
WiFiSend_LoopFunction ();  
      Serial.println("num=");
      Serial.println(num); 
}


