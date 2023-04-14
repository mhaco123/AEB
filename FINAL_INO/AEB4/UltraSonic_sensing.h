/* In The Name Of ALLAH
ULTRASONICs CODE 
 */
//************************************************************************************* PreSetup
#define CNT 10
int ultrasonic1_index = 0;float ultrasonic1_data[CNT];
float var_ultrasonic1 = 0, mng_ultrasonic1 = 0;
////us parameters///
const byte pinTRIG = 5;///triger pin of 1st ultrasonic sensor
const byte pinECHO = 4;///echo pin of 1st ultrasonic sensor
float mu1;
long duration, distanceIn;
float t1u,t2u,tu;
float temp = 20;
float volts2,proxSens2,V;
//************************************************************************************* Setup Function
void UltraSonic_sensing_SetupFunction ()
{
    Serial.begin(115200);
    pinMode(5,OUTPUT);
    pinMode(4,INPUT);
}

//*************************************************************************************Loop Function
void UltraSonic_sensing_LoopFunction ()
{
  
  proxSens2 = analogRead(1);
  analogReadResolution(12);
  volts2 = ((float)proxSens2 * 3.3) /4095;
  temp = volts2 * 100;
  Serial.println("temp=");
  Serial.println(temp);

  t1u = millis();
  Serial.println("t1u=");
  Serial.println(t1u);
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(5, LOW);
  delayMicroseconds(10);
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);
  duration = pulseIn(4, HIGH);
  Serial.println("duration=");
  Serial.println(duration);
  // convert the time into a distance
  if (abs(temp - 20) < 35) {
    //mu1 = duration / 29.1 / 2 ;
    mu1=(duration * 352) / (2*10000);
  }
  else
  {
    V = (0.6 * temp) + 331 ;
    mu1 = (duration * V ) / (2*10000);
    Serial.println("different temp");
  }

  if (mu1  <= 0) {
    Serial.println("Out of range");
  }
  else {
    Serial.println("mu1=");
    Serial.println(mu1);
  }
  ultrasonic1_data[ultrasonic1_index] = mu1; //meghdare ultrasonic1 ra dar yek derye in matrix gharar midahad
  ultrasonic1_index ++;// ba har bar ejra meghdare ultrasonic1 dar derayeye badi gharar migirad
  if (ultrasonic1_index > CNT - 1) ultrasonic1_index = 0; //agar dadeha bishtar az meghdare CNT shod az avval
  for (n = 0  ; n < CNT ; n++)mng_ultrasonic1 += ultrasonic1_data[n];//sum data
  mng_ultrasonic1 = mng_ultrasonic1 / CNT;// devide to cnt
  for (n = 0  ; n < CNT ; n++)var_ultrasonic1 += pow((mng_ultrasonic1 - ultrasonic1_data[n]), 2);// variancer
  var_ultrasonic1 = var_ultrasonic1 / CNT;//var totally
  Serial.println("mng_ultrasonic1=");
  Serial.println(mng_ultrasonic1);
  Serial.println("var_ultrasonic1=");
  Serial.println(var_ultrasonic1);
  t2u = millis();
  Serial.println("t2u=");
  Serial.println(t2u);
  tu = t2u - t1u;
  Serial.println("tu=");
  Serial.println(tu);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
float microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29.0 / 2.0;
}
