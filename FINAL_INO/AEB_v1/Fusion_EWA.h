/* In The Name Of ALLAH
FUSION CODE 
 */
//************************************************************************************* PreSetup
float v_rel,TTC,T_h,f_old;
#define sensorPin 0

#define CNT 10
//************************************************************************************* Setup Function
void Fusion_EWA_SetupFunction ()
{
}

//*************************************************************************************Loop Function
void Fusion_EWA_LoopFunction ()
{
////state 1 for fusion by EWA
if (num < 100) {
  if (mu1 < 100) {
    f = pow((var_laser + var_ultrasonic1),-1)*(var_laser*mu1)+(var_ultrasonic1*num);
    Serial.println("fusion_under100=");
    Serial.println(f);
                }
               }
////state 2
 if (num < 500){
  if (mu1 < 500 ){
   if (cm < 500 ){
    if ( num > 100){
      if ( mu1 > 100){
        if( cm > 100){
          f = pow((var_laser + var_ultrasonic1),-1)*(var_laser*mu1)+(var_ultrasonic1*num);
          //f = (num*0.5)+(mu*0.35)+ ( cm*0.15);
          v_rel=(f-f_old)/50;
          TTC=f/v_rel;
          
          T_h=f/v_h;
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
  if ( mu1 < 100 ){
    if ( cm > 100){
      f = (num*0.6)+(mu1*0.4);
      Serial.println("f");
      Serial.println(f);
                  }
                 }
                } 
////
else f = num;
Serial.println(f);
}
