/* In The Name Of ALLAH
IR CODE 
 */
//************************************************************************************* PreSetup
#define sensorPin 0
#define CNT 10
int ir_index = 0;int ir_data[CNT];
float proxSens = 0;
float volts = 0;
float cm;
long n = 0; float var_ir = 0, mng_ir = 0;
//************************************************************************************* Setup Function
void InfraRed_sensing_SetupFunction ();
{
 //initialize serial communications at 9600 bps
    Serial.begin(9600);
}

//*************************************************************************************Loop Function
void InfraRed_sensing_LoopFunction ()
{
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
      var_ir = var_ir / CNT;//var totally
      Serial.println("mng_ir=");
      Serial.println(mng_ir);
      Serial.println("var_ir=");
      Serial.println(var_ir);
      Serial.println(cm);
      Serial.println("\r\n");
      delay(50);

}

