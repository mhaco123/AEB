 double MotorOrder=93;
    #include "motorPWM.h"
    #include "WiFiSend.h"

void setup(void)
{
WiFiSend_SetupFunction ();
motorPWM_SetupFunction ();

}
void loop() {
if (filteredPos> 110) {
 MotorOrder=30;
} else
{MotorOrder=filteredPos;}
myservo.write(MotorOrder);
motorPWM_LoopFunction ();
WiFiSend_LoopFunction ();   
}


