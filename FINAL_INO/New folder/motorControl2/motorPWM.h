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
///////////////////////////////
#define CNT 10
long n=0;
int laser_index = 0;int laser_data[CNT];
float f;
float var_laser = 0, mng_laser = 0;
float num;

         String laserOut = "";
      char buffer;
      int i;
     
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

   Serial.begin(9600);
    Serial2.begin(115200); //Opens the virtual serial port with a baud of 115200
    delay(100);
    Serial2.write("C");
    delay(100);
    Serial2.write("O");
    delay(100);
    Serial2.write("V");
    delay(1000);
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

 
      //Serial.print("Distance(m): ");
      do
      {
        if(Serial2.available() > 0)
        {
          buffer = Serial2.read();// data a dar yek buffer zakhire mishvand
          laserOut += buffer;// sepas dar string kenare ham miayand ta betavanim process konim
          //Serial.print(buffer);//check kardane inke in kar dorost mishavad ya na
        }
      }
      while(buffer != '\n');
      i = laserOut.indexOf("m");// jayee ke m vojood darad ra peda kon
      laserOut.remove(i);///  az bade m hazf mikond
      i = laserOut.lastIndexOf(" ");// jayee ke m vojood darad ra peda kon
      laserOut.remove(0, i + 1);//az ghble fasele hazf mikond
      num = laserOut.toFloat();// convert string to float 
      Serial2.println("num=");
      Serial2.println(num);
      laser_data[laser_index]= num;//meghdare laser ra dar yek derye in matrix gharar midahad
      laser_index ++;// ba har bar ejra meghdare laser dar derayeye badi gharar migirad
      if (laser_index > CNT-1) laser_index=0;//agar dadeha bishtar az meghdare CNT shod az avval
      for (n = 0  ; n < CNT ; n++)mng_laser += laser_data[n];//sum data 
      mng_laser = mng_laser / CNT;// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_laser += pow((mng_laser - laser_data[n]), 2);// variancer
      var_laser = var_laser / CNT;//var totally
      Serial.println("mng_laser=");
      Serial.println(mng_laser);
      Serial.println("var_laser=");
      Serial.println(var_laser);
      delay(50);
}
