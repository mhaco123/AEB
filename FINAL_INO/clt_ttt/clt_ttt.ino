
/////* IN THE NAME OF ALLAH THE BENEFICENT THE MERCIFUL */////
//// ** INTEGRATION 3 SENSOR FOR DISTANCE MESSURING ** /////
/// *** BY Mohammad hasan Aghanoori _ 9302274 *** ///
// **** CREATED  1395.8.10 ****//

//////Inferared sensor code\\\\\\

#define CNT 10
int laser_index = 0;float laser_data[CNT];
int ultrasonic1_index = 0;float ultrasonic1_data[CNT];
int ultrasonic2_index = 0;float ultrasonic2_data[CNT];
int ir_index = 0;float ir_data[CNT];
float num; 
float proxSens = 0;
float volts = 0;
float cm,f,mu;

float var_laser = 0, mng_laser = 0;
long n = 0; float var_ir = 0, mng_ir = 0;
float var_ultrasonic1 = 0, mng_ultrasonic1 = 0;
float var_ultrasonic2 = 0, mng_ultrasonic2 = 0;
float var_ultrasonic = 0, mng_ultrasonic = 0;
////us parameters///
const byte pinTRIG = 3;///triger pin of 1st ultrasonic sensor
const byte pinECHO = 2;///echo pin of 1st ultrasonic sensor
const byte pinTRIG2 = 7;///triger pin of 2nd ultrasonic sensor
const byte pinECHO2 = 8;///echo pin of 2nd ultrasonic sensor
//////

void setup() {
 //initialize serial communications at 9600 bps

    Serial.begin(9600);
       
    pinMode(3,OUTPUT);
    pinMode(2,INPUT);
    
    pinMode(8,OUTPUT);
    pinMode(7,INPUT);
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

/////////////////////////////////////////////////////////////
//////Ultrasonic sensor SRF05 code\\\\\\

void loop2()
      {
      // establish variables for duration of the ping,
      // and the distance result in inches and centimeters:
 long duration, distanceCm, distanceIn;
 
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
  duration = pulseIn(2,HIGH);
 
  // convert the time into a distance
  distanceCm = duration / 29.1 / 2 ;

   long duration2, distanceCm2, distanceIn2;
 
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);
  duration = pulseIn(7,HIGH);
 
  // convert the time into a distance
  distanceCm2 = duration / 29.1 / 2 ;
   
  if (distanceCm & distanceCm2 <= 0){
    
    Serial.println("Out of range");
  }
  else {
    
    Serial.println("mu1=");
    Serial.println(distanceCm);
    
  
    Serial.println("mu2=");
    Serial.println(distanceCm2);
  
  
  }
      ultrasonic1_data[ultrasonic1_index]= distanceCm;//meghdare ultrasonic1 ra dar yek derye in matrix gharar midahad
      ultrasonic1_index ++;// ba har bar ejra meghdare ultrasonic1 dar derayeye badi gharar migirad
      if (ultrasonic1_index > CNT-1) ultrasonic1_index=0;//agar dadeha bishtar az meghdare CNT shod az avval
      
      for (n = 0  ; n < CNT ; n++)mng_ultrasonic1 += ultrasonic1_data[n];//sum data 
      mng_ultrasonic1 = mng_ultrasonic1 / CNT;// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_ultrasonic1 += pow((mng_ultrasonic1 - ultrasonic1_data[n]), 2);// variancer
      var_ultrasonic1 = var_ultrasonic1 / 100;//var totally
      Serial.println("mng_ultrasonic1=");
      Serial.println(mng_ultrasonic1);
      Serial.println("var_ultrasonic1=");
      Serial.println(var_ultrasonic1);
//      Serial.println("m1=");
//      Serial.println(m1*0.01);
///  for 2nd ultrasonic sensor 

      ultrasonic2_data[ultrasonic2_index]= distanceCm2;//meghdare ultrasonic2 ra dar yek derye in matrix gharar midahad
      ultrasonic2_index ++;// ba har bar ejra meghdare ultrasonic2 dar derayeye badi gharar migirad
      if (ultrasonic2_index > CNT-1) ultrasonic2_index=0;//agar dadeha bishtar az meghdare CNT shod az avval

      for (n = 0  ; n < CNT ; n++)mng_ultrasonic2 += ultrasonic2_data[n];//sum data 
      mng_ultrasonic2 = mng_ultrasonic2 / CNT;// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_ultrasonic2 += pow((mng_ultrasonic2 - ultrasonic2_data[n]), 2);// variancer
      var_ultrasonic2 = var_ultrasonic2 / 100;//var totally
      Serial.println("mng_ultrasonic2=");
      Serial.println(mng_ultrasonic2);
      Serial.println("var_ultrasonic2=");
      Serial.println(var_ultrasonic2);
      delay(500);
      
      
      mu = (distanceCm+distanceCm2)/2 ;
      Serial.println("mu=");
      Serial.println(mu);
      var_ultrasonic=(0.5 * var_ultrasonic1)+(0.5*var_ultrasonic2);
////state 1 for fusion by CLT
if (num < 100) {
  if (distanceCm < 100) {
    f = pow((var_laser + var_ultrasonic1),-1)*(var_laser*distanceCm)+(var_ultrasonic1*num);
    Serial.println("fusion_under100=");
    Serial.println(f);
                }
               }
////state 2
 if (num < 500){
  if (distanceCm < 500 ){
   if (cm < 500 ){
    if ( num > 100){
      if ( distanceCm > 100){
        if( cm > 100){
          f = pow((var_laser + var_ultrasonic1),-1)*(var_laser*distanceCm)+(var_ultrasonic1*num);
          f = (num*0.5)+(distanceCm*0.35)+ ( cm*0.15);
          Serial.println("fusion_under400=");
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
  if ( distanceCm < 100 ){
    if ( cm > 100){
      f = (num*0.6)+(distanceCm*0.4);
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
  //loop3();
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

      for (n = 0  ; n < CNT ; n++)mng_ir += ir_data[n];//sum data 
      mng_ir = mng_ir / CNT;// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_ir += pow((mng_ir - ir_data[n]), 2);// variancer
      var_ir = var_ir / 100;//var totally
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


//////LASER L-S01 sensor code\\\\\\
////int S[3]={1 , 2 , 3};
// a[29]=4;
void loop()
{
      
      loop2();
      loop3();
      //delay(40);
}


