/* In The Name Of ALLAH
ULTRASONICs CODE 
 */
//************************************************************************************* PreSetup
//#define CNT 10
long duration, distanceCm, distanceIn;
float cm,mu;
int ultrasonic1_index = 0;int ultrasonic1_data[CNT];
int ultrasonic2_index = 0;int ultrasonic2_data[CNT];

float var_ultrasonic1 = 0, mng_ultrasonic1 = 0;
float var_ultrasonic2 = 0, mng_ultrasonic2 = 0;
float var_ultrasonic = 0, mng_ultrasonic = 0;
////us parameters///
const byte pinTRIG = 3;///triger pin of 1st ultrasonic sensor
const byte pinECHO = 2;///echo pin of 1st ultrasonic sensor
const byte pinTRIG2 = 7;///triger pin of 2nd ultrasonic sensor
const byte pinECHO2 = 8;///echo pin of 2nd ultrasonic sensor

//      long duration, distanceCm, distanceIn;
//************************************************************************************* Setup Function
void UltraSonic_sensing_SetupFunction ()
{
 //initialize serial communications at 9600 bps
    Serial.begin(9600);

}

//*************************************************************************************Loop Function
void UltraSonic_sensing_LoopFunction ()
{

 
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
      var_ultrasonic1 = var_ultrasonic1 / CNT;//var totally
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
      var_ultrasonic2 = var_ultrasonic2 / CNT;//var totally
      Serial.println("mng_ultrasonic2=");
      Serial.println(mng_ultrasonic2);
      Serial.println("var_ultrasonic2=");
      Serial.println(var_ultrasonic2);
      delay(500);
      
      
      mu = (distanceCm+distanceCm2)/2 ;
      Serial.println("mu=");
      Serial.println(mu);
      var_ultrasonic=(0.5 * var_ultrasonic1)+(0.5*var_ultrasonic2);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
float microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29.0 / 2.0;
}
