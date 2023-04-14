

/*
 * TTC = (X_F) / (V_forward - V_host) = f/V_rel
 * (V_forward - V_host) = V_relative = (X_F(+) - X_F(-)) / T_sample  
 * V_rel=
 * THW = (X_F) / (V_host)
 * V_host = CAR_VELOCITY
 */
 double MotorOrder=93;
 #include <Servo.h>
 //---------------------------------------------------------------------------------------
//////////////////////BUZZER///////////////////////////////
int speakerPin = 5;
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;
///////////////////////led//////////////////////////////

//LED_BUILTIN=4;
///////////////////////brake//////////////////////////////
//const byte interruptPin = 22;
volatile unsigned long HighTime = 1500;
volatile unsigned long LowTime = 1;
volatile unsigned long Time1 = 0;
volatile unsigned long Time2 = 0;
byte state = LOW;
Servo myservo;
double pos = 0;
double scale = 1;
double initialPos;
double filteredPos;


//----------------------------------------------------------------------------------------
///////////////////////////
 void Timing() {
if (!digitalRead(interruptPin)){
   Time1=micros();
   HighTime=Time1-Time2;
  }else{
   Time2=micros();
   LowTime=Time2-Time1;  
  }
}
//------------------------------------------------------------------------------------------ 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void DecisionMaking_SetupFunction () {
  ///BUZZERR////
  pinMode(speakerPin, OUTPUT);
  ////led/////
  pinMode(LED_BUILTIN, OUTPUT);
  //////brake/////
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(interruptPin, Timing, CHANGE );
   delay(10);
   myservo.attach(9);
   initialPos=0.097*HighTime-52.632;
}
//------------------------------------------------------------------------------------------
void FCW1(){
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}
//---------------------------------------------------------------------------------------
void FCW2(){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}
//-----------------------------------------------------------------------------------------
void LBrake(){
/*if (num < 2) {
 MotorOrder=70;
} else
{MotorOrder=filteredPos;}
myservo.write(MotorOrder);
*/
}
//--------------------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void DecisionMaking_LoopFunction() {
  // put your main code here, to run repeatedly:
//////////////////

if (TTC<3) {
 if (T_h<2){
    
    FCW1();
    FCW2();
    LBrake();
//  }
//}
}


