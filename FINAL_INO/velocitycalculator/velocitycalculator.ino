//In The Name Of GOD
 #include "arduino.h" 
#include "velocity_sensing.h"
#include "WiFiSend.h"
    
void setup(void)
{
      Serial.begin(115200);
  velocity_sensing_SetupFunction ();
  WiFiSend_SetupFunction ();
}


void loop() {
  velocity_sensing_LoopFunction ();
  WiFiSend_LoopFunction ();   

}


