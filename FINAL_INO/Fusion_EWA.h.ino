/* In The Name Of ALLAH
LASER CODE 
 */
//************************************************************************************* PreSetup

#define sensorPin 0

#define CNT 10
float cm,f;
float var_laser = 0, mng_laser = 0;
long n = 0; float var_ir = 0, mng_ir = 0;
float var_ultrasonic1 = 0, mng_ultrasonic1 = 0;
float var_ultrasonic2 = 0, mng_ultrasonic2 = 0;
float var_ultrasonic = 0, mng_ultrasonic = 0;
float num;
//************************************************************************************* Setup Function
void Fusion_EWA_SetupFunction ();
{
}

//*************************************************************************************Loop Function
void Fusion_EWA_LoopFunction ()
{
////state 1 for fusion by EWA
if (num < 100) {
  if (mu < 100) {
    f = pow((var_laser + var_ultrasonic),-1)*(var_laser*mu)+(var_ultrasonic*num);
    Serial.println("fusion_under100=");
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
          //f = (num*0.5)+(mu*0.35)+ ( cm*0.15);
          v_rel=(f-f_old)/50;
          TTC=f/v_rel;
          
          T_h=f/v_h
          Serial.println("fusion_under400=");
          Serial.println(f);
          f_old=f;
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
}

