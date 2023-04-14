/* In The Name Of ALLAH
LASER CODE 
 */
//************************************************************************************* PreSetup
#define CNT 10
int laser_index = 0;float laser_data[CNT];
float f;long n = 0;
float var_laser = 0, mng_laser = 0;
float num;
float t1l,t2l,tl;
float TTC,num_old;
//************************************************************************************* Setup Function
void Laser_sensing_SetupFunction ()
{
    Serial.begin(115200);
    Serial2.begin(115200); //Opens the virtual serial port with a baud of 115200
    delay(100);
    Serial2.write("C");
    delay(100);
    Serial2.write("O");
    delay(100);
    Serial2.write("V");
    delay(100);
}

//*************************************************************************************Loop Function
void Laser_sensing_LoopFunction ()
{
      t1l=millis();
      String laserOut = "";
      
      char buffer;
      int i;
      float tl;
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
      Serial.println("num=");
      Serial.println(num);
      laser_data[laser_index]= num;//meghdare laser ra dar yek derye in matrix gharar midahad
      laser_index ++;// ba har bar ejra meghdare laser dar derayeye badi gharar migirad
      if (laser_index > CNT-1) laser_index=0;//agar dadeha bishtar az meghdare CNT shod az avval
      for (n = 0  ; n < CNT ; n++)mng_laser += laser_data[n];//sum data 
      mng_laser = (mng_laser) / (CNT);// devide to cnt
      for (n = 0  ; n < CNT ; n++)var_laser += pow((mng_laser - laser_data[n]), 2);// variancer
      var_laser = var_laser / (CNT);//var totally
//      Serial.println("mng_laser=");
//      Serial.println(mng_laser);
//      Serial.println("var_laser=");
//      Serial.println(var_laser);
//      delay(1000);
//      t2l=millis();
//      tl=t2l-t1l;
//      Serial.println("tl=");
//      Serial.println(tl);
//      TTC=(abs(num-num_old))/(0.027688);
//      num_old=num;

}
