
int pinCountDAC = 12;         // The number of DAC pins (i.e. the length of the array)
int pinCountDo = 13;         // The number of Digital pins Digital Output (i.e. the length of the array)
int pinCountDI = 33;         // The number of Digital pins Digital Input (i.e. the length of the array)
int pinCountCS = 10;         // The number of Digital pins Digital Input (i.e. the length of the array) 
int DIPins[] = {0,1,2,3, 4,5,6,7,8, 9,10,11,13,14, 15,16,17,18,19, 20,21,22,23,24, 25,26,27,28,29, 30,31,32,33};  // An array of pin numbers to which Digital Outputs are attached
int DOPins[] = {53,52,51,50,49, 48,47,46,45,44, 43,42,41};  // An array of pin numbers to which Digital Inputs are attached
int AIPins[] = {A0,A1,A2,A3,A4, A5,A6,A7,A8,A9};  // An array of pin numbers to which Digital Inputs are attached
int sensorValue[] = {0,0,0,0,0, 0,0,0,0,0};
//int outputValue[] = {0,0,0,0,0, 0,0,0,0,0};
bool senDI=false;
bool senAI=false;   
char DataS[4]={0x00,0x08,0x00,0x00};
/////////////////////////////////////////////////////////////   
void setup()
{
   Serial.begin(115200);
   for (int thisPin = 0; thisPin < pinCountDo; thisPin++)  
   {
    pinMode(DOPins[thisPin], OUTPUT);
    digitalWrite(DOPins[thisPin], LOW);
   }  
   for (int thisPin = 0; thisPin < pinCountDI; thisPin++)
    pinMode(DIPins[thisPin], INPUT_PULLUP);
}
////////////////////////////////////////////////////////////
void loop() {
  if (Serial.available() > 0) 
{
    int availableBytes=Serial.available();
    for(int n=0; n<availableBytes; n++)DataS[n] = Serial.read();
    if(DataS[0]==0xF1)
    {
      if(DataS[3]==0xF1)senDI=true;///
      if(DataS[3]==0xF2)senAI=true;///
    }
    if(DataS[0]==0x1F)
    {
      if(DataS[3]==0x1F)
      {
      DigitalOutput1(DataS[1]);
      DigitalOutput2(DataS[2]);  
      }
    }
    if(senDI==true)
    {
      DigitalInput();  
      senDI=false;
    }
    if(senAI==true)
    {
      AnalogInput();
      senAI=false;
    }
}  
}
///////////////////////////////////////////////////////////////
void DigitalInput()
{
  char Data[7]={0xF1,0x00,0x00,0x00,0x00,0x00,0xF1};
  for(int i=0; i<8 ;i++)Data[1]=(digitalRead(DIPins[i])<<  i )+Data[1] ;
  for(int i=8; i<15;i++)Data[2]=(digitalRead(DIPins[i])<< 8-i)+Data[2] ;
  for(int i=15;i<23;i++)Data[3]=(digitalRead(DIPins[i])<<15-i)+Data[3] ;
  for(int i=23;i<31;i++)Data[4]=(digitalRead(DIPins[i])<<23-i)+Data[4] ;
  for(int i=31;i<33;i++)Data[5]=(digitalRead(DIPins[i])<<31-i)+Data[5] ;
  Serial.write(Data[0]);
  Serial.write(Data[1]);
  Serial.write(Data[2]);
  Serial.write(Data[3]);
  Serial.write(Data[4]);
  Serial.write(Data[5]);
  Serial.write(Data[6]);
}
//////////////////////////////////////////////////////////////
void DigitalOutput1(char data)
{
  for(int i=0;i<8;i++)digitalWrite(DOPins[i],(data>>i&1));
}
void DigitalOutput2(char data)
{
  for(int i=8;i<13;i++)digitalWrite(DOPins[i],(data>>8-i&1));
}

//////////////////////////////////////////////////////////////
void AnalogInput()
{
  char Data[12]={0xF3,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0xF3};
  for(int j=0; j<10 ; j++)
  {
    sensorValue[j] = analogRead(AIPins[j]);
    Data[j+1] = map(sensorValue[j], 0, 4095, 0, 255);
  }
  Serial.write(Data[0]);
  Serial.write(Data[1]);
  Serial.write(Data[2]);
  Serial.write(Data[3]);
  Serial.write(Data[4]);
  Serial.write(Data[5]);
  Serial.write(Data[6]);
  Serial.write(Data[7]);
  Serial.write(Data[8]);
  Serial.write(Data[9]);
  Serial.write(Data[10]);
  Serial.write(Data[11]);
  Serial.write(Data[12]);
   }

