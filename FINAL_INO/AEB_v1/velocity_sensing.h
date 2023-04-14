/* In The Name Of GOD
 *  This code calculate the rotational velocity of wheel (w) with counting pulses in specified interval of time (delta_t).
 *  Then the w is filtered with a simple time filtering and 
 */

//************************************************************************************* PreSetup
//for uno it should be transformed:
const byte interruptPin = 24;
#define pi 3.142

double pcounter=0;    //It counts the pulses
double w=0;   //Unfiltered rotational velocity
double WF=0;  //Filtered rotational velocity
double Nolines = 14;  //Number of couples of white and black lines
double rpm=0;  //filtered rpm of wheel

//For delta_t:
double t1=0;
double t2=0;
double delta_t=0;

//For delta_t2:
double t3=0;
double t4=0;
double delta_t2=0;

float v_h;

//************************************************************************************* Functions
void VS_interrupt_act(){
  t4=micros();
  delta_t2=t4-t3;
  if (delta_t2>200)
  {
  pcounter=pcounter+1;
  t3=t4;
  }
}
//************************************************************************************* Setup Function
void velocity_sensing_SetupFunction () {
  Serial.println("ready..");
  pinMode(interruptPin, INPUT_PULLUP);// input port with mode pull-up
  attachInterrupt(interruptPin,VS_interrupt_act, CHANGE );
}

//*************************************************************************************Loop Function
void velocity_sensing_LoopFunction () {
  t2=millis();
  delta_t=t2-t1;
  if (delta_t>50)
  {
    w=pcounter/Nolines*2*(3.14/delta_t)*1000;  // (rad/s)
    WF=.8*WF+.2*w;
    rpm=WF*60/(2*pi);
    pcounter=0;
    t1=t2;
    v_h=WF*0.05  ;
  }
        Serial.print("  pcounter= ");
        Serial.print(pcounter);
        Serial.print("  delta_t: ");
        Serial.print(delta_t);
        Serial.print("  w: ");
        Serial.println(rpm);  //print the rpm
        Serial.print("  w: ");
        Serial.println(v_h);  //print the rpm
      
 }
