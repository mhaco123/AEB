/* this cod read the receiver PWM signal on "pin 22" DUE board Scale it (reduce motor Speed for example) and generate scaled PWM
 *  and generate scaled PWM on "pin 7".
 *  
 */
    #include <Servo.h>
//************************************************************************************* PreSetup

const byte interruptPin = 22;
volatile unsigned long HighTime = 1500;
volatile unsigned long LowTime = 1;
volatile unsigned long Time1 = 0;
volatile unsigned long Time2 = 0;
//byte state = LOW;
Servo myservo;
double pos = 0;
double scale = 1;
double initialPos;
double filteredPos;

//************************************************************************************* Functions
 void Timing() {
if (!digitalRead(interruptPin)){
   Time1=micros();
   HighTime=Time1-Time2;
  }else{
   Time2=micros();
   LowTime=Time2-Time1;  
  }
}

//************************************************************************************* Setup Function
void motorPWM_SetupFunction () {
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(interruptPin, Timing, CHANGE );
   delay(10);
   myservo.attach(9);
   initialPos=0.097*HighTime-52.632;
}

//*************************************************************************************Loop Function
void motorPWM_LoopFunction () {
   delay(13);
   if (HighTime>900 & HighTime<2100){
    pos=0.097*HighTime-52.632;
//    pos=(pos-initialPos)*scale+initialPos;
    filteredPos=(1-0.8)*pos+0.8*filteredPos;
   }else{
    filteredPos=initialPos;
   }
   
}
