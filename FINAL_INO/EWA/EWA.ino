/////* IN THE NAME OF ALLAH THE BENEFICENT THE MERCIFUL */////
//// ** INTEGRATION 3 SENSOR FOR DISTANCE MESSURING ** /////
/// *** BY Mohammad hasan Aghanoori _ 9302274 *** ///
// **** CREATED  1395.8.10 ****//

//////Inferared sensor code\\\\\\
#define sensorPin 0
#define CNT 10
int laser_index = 0;int laser_data[CNT];
int ultrasonic1_index = 0;int ultrasonic1_data[CNT];
int ultrasonic2_index = 0;int ultrasonic2_data[CNT];
int ir_index = 0;int ir_data[CNT];
 
float proxSens = 0;
float volts = 0;
float cm,f;long n ;
float var_laser,var_ir,var_ultrasonic;
float mng_laser;
////us parameters///
const byte pinTRIG = 3;///triger pin of 1st ultrasonic sensor
const byte pinECHO = 2;///echo pin of 1st ultrasonic sensor
const byte pinTRIG2 = 7;///triger pin of 2nd ultrasonic sensor
const byte pinECHO2 = 8;///echo pin of 2nd ultrasonic sensor
volatile unsigned long HighTime =1500;
float num;
void setup() {
 //initialize serial communications at 9600 bps

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
//////////////////////////////////////////////
//////LASER L-S01 sensor code\\\\\\
////int S[3]={1 , 2 , 3};
// a[29]=4;
void loop()
{
      String laserOut = "";
      char buffer;
      int i;
      float num;
      
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
      ///Serial.print(num);
      laser_data[laser_index]= num;//meghdare laser ra dar yek derye in matrix gharar midahad
      laser_index ++;// ba har bar ejra meghdare laser dar derayeye badi gharar migirad
      if (laser_index > CNT-1) laser_index=0;//agar dadeha bishtar az meghdare CNT shod az avval
      n = 0;var_laser = 0 ; mng_laser = 0;
      for (n = 0  ; n < CNT ; n++)mng_laser += laser_data[n];//sum data 
      mng_laser = mng_laser / CNT;// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_laser += pow((mng_laser - laser_data[n]), 2);// variancer
      var_laser = var_laser / n;//var totally
      Serial.println("mng_laser=");
      Serial.println(mng_laser);
      Serial.println("var_laser=");
      Serial.println(var_laser);
////state 1 for fusion by CLT
if (num < 100) {
  if (mu < 100) {
    f = pow((var_laser + var_ultrasonic),-1)*(var_laser*mu)+(var_ultrasonic*num);
    Serial.println(f);
    loop2();
    loop3();
                }
               }
////state 2
 if (num < 500){
  if (mu < 500 ){
   if (cm < 500 ){
    if ( num > 100){
      if ( mu > 100){
        if( cm > 100){
          float var_laser = 0, mng_laser = 0;
          f = pow((var_laser + var_ultrasonic),-1)*(var_laser*mu)+(var_ultrasonic*num);
          f = (num*0.5)+(mu*0.35)+ ( cm*0.15);
          Serial.println("f");
          Serial.println(f);
                     }
                    }
                   }
                  }
                 }
                } 
//// state 3
if ( num > 500 ){
   if( cm > 400 ){
     f = (num*0.9)+( cm*0.1);
     Serial.println("f");
     Serial.println(f);
                 }
                } 
//// state 4
if ( num < 100 ){
  if ( mu < 100 ){
    if ( cm > 100){
      f = (num*0.6)+(mu*0.4);
      Serial.println("f");
      Serial.println(f);
                  }
                 }
                } 
////
else f = num;
Serial.println(f);
}
      
      loop2();
      //loop3();
      //delay(40);
}

/////////////////////////////////////////////////////////////
//////Ultrasonic sensor SRF05 code\\\\\\

void loop2()
      {
      // establish variables for duration of the ping,
      // and the distance result in inches and centimeters:
      long duration1 ,  duration2;
      float m1,m2,mu1,mu2,mu;
      
      
      digitalWrite(pinTRIG, HIGH);
      delayMicroseconds(10);
      digitalWrite(pinTRIG, LOW);
      
      
      digitalWrite(pinTRIG2, HIGH);
      delayMicroseconds(10);
      digitalWrite(pinTRIG2, LOW);
      
      duration1 = pulseIn(pinTRIG, HIGH);
      duration1 = HighTime;
      
      duration2 = pulseIn(pinTRIG2, HIGH);
      duration2 = HighTime;
      
      // convert the time into a distance
      m1 = microsecondsToCentimeters(duration1);
      m2 = microsecondsToCentimeters(duration2);
      //  Serial.print("in, ");
      mu1= m1*0.01;
      ultrasonic1_data[ultrasonic1_index]= mu1;//meghdare ultrasonic1 ra dar yek derye in matrix gharar midahad
      ultrasonic1_index ++;// ba har bar ejra meghdare ultrasonic1 dar derayeye badi gharar migirad
      if (ultrasonic1_index > CNT-1) ultrasonic1_index=0;//agar dadeha bishtar az meghdare CNT shod az avval
      long n = 0; float var_ultrasonic1 = 0, mng_ultrasonic1 = 0;
      for (n = 0  ; n < CNT ; n++)mng_ultrasonic1 += ultrasonic1_data[n];//sum data 
      mng_ultrasonic1 = mng_ultrasonic1 / CNT;// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_ultrasonic1 += pow((mng_ultrasonic1 - ultrasonic1_data[n]), 2);// variancer
      var_ultrasonic1 = var_ultrasonic1 / CNT;//var totally
      Serial.println("mng_ultrasonic1=");
      Serial.println(mng_ultrasonic1);
      Serial.println("var_ultrasonic1=");
      Serial.println(var_ultrasonic1);
      Serial.print(m1*0.01);
///  for 2nd ultrasonic sensor 
      mu2= m2*0.01;
      Serial.println("mu2=");
      Serial.println(mu2);
      ultrasonic2_data[ultrasonic2_index]= mu2;//meghdare ultrasonic2 ra dar yek derye in matrix gharar midahad
      ultrasonic2_index ++;// ba har bar ejra meghdare ultrasonic2 dar derayeye badi gharar migirad
      if (ultrasonic2_index > CNT-1) ultrasonic2_index=0;//agar dadeha bishtar az meghdare CNT shod az avval
      float var_ultrasonic2 = 0, mng_ultrasonic2 = 0;
      for (n = 0  ; n < CNT ; n++)mng_ultrasonic2 += ultrasonic2_data[n];//sum data 
      mng_ultrasonic2 = mng_ultrasonic2 / CNT;// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_ultrasonic2 += pow((mng_ultrasonic2 - ultrasonic2_data[n]), 2);// variancer
      var_ultrasonic2 = var_ultrasonic2 / CNT;//var totally
      Serial.println("mng_ultrasonic2=");
      Serial.println(mng_ultrasonic2);
      Serial.println("var_ultrasonic2=");
      Serial.println(var_ultrasonic2);
      Serial.print(mu2);
      delay(500);
      
      float var_ultrasonic = 0, mng_ultrasonic = 0;
      mu = (m1+m2)/2 ;
      Serial.println("mu");
      Serial.println(mu);
      var_ultrasonic=(0.5 * var_ultrasonic1)+(0.5*var_ultrasonic2);
////state 1 for fusion by CLT
if (num < 100) {
  if (mu < 100) {
    float var_laser = 0, mng_laser = 0;
    f = pow((var_laser + var_ultrasonic),-1)*(var_laser*mu)+(var_ultrasonic*num);
    Serial.println(f);
                }
               }
////state 2
 if (num < 500){
  if (mu < 500 ){
   if (cm < 500 ){
    if ( num > 100){
      if ( mu > 100){
        if( cm > 100){
          f = pow((var_laser + var_ultrasonic),-1)*(var_laser*mu)+(var_ultrasonic*num);
          f = (num*0.5)+(mu*0.35)+ ( cm*0.15);
          Serial.println("f");
          Serial.println(f);
                     }
                    }
                   }
                  }
                 }
                } 
//// state 3
if ( num > 500 ){
   if( cm > 400 ){
     f = (num*0.9)+( cm*0.1);
     Serial.println("f");
     Serial.println(f);
                 }
                } 
//// state 4
if ( num < 100 ){
  if ( mu < 100 ){
    if ( cm > 100){
      f = (num*0.6)+(mu*0.4);
      Serial.println("f");
      Serial.println(f);
                  }
                 }
                } 
////
else f = num;
Serial.println(f);
}
float microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29.0 / 2.0;
  loop3();
}

//// ir void loop
void loop3() {
      proxSens = analogRead(0);
      volts = (float)proxSens /4095 * 5;
      analogReadResolution(12);
      proxSens = analogRead(0);
      volts = ((float)proxSens * 5) /4095;
      cm=(1000/7)*(1/(volts-(15/14)));
      ir_data[ir_index]= cm;//meghdare ir ra dar yek derye in matrix gharar midahad
      ir_index ++;// ba har bar ejra meghdare ir dar derayeye badi gharar migirad
      if (ir_index > CNT-1) ir_index=0;//agar dadeha bishtar az meghdare CNT shod az avval
      long n = 0; float var_ir = 0, mng_ir = 0;
      for (n = 0  ; n < CNT ; n++)mng_ir += ir_data[n];//sum data 
      mng_ir = mng_ir / CNT;// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_ir += pow((mng_ir - ir_data[n]), 2);// variancer
      var_ir = var_ir / CNT;//var totally
      Serial.println("mng_ir=");
      Serial.println(mng_ir);
      Serial.println("var_ir=");
      Serial.println(var_ir);
      Serial.print(cm);
      Serial.print("\r\n");
      delay(500);

}
        /////////////////////FUSION \\\\\\\\\\\\\\\\\
/// cm= ir measurment; m1,m2 = us measurment;  num = laser measurment;
/// 1st state =    num,m2,m1 < 100          ==> fuse us & laser under 100 cm
// (LASER*5 + (m1 * 2.5) + (m2*2.5))/10
/// 2nd state =    500 > num,m1,m2,cm > 100 ==> fuse all after weightening
/// 3rd state =    num,cm > 500             ==> fuse ir & laser up to 500 cm
/// 4th state =    num>500,cm<500           ==> only laser should be read
/// 5th state =    m1,m2,laser > 100,cm<100 ==> fuse us & laser 


