
#define CNT 5
int s[CNT] = {1, 5, 2, 4, 1};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  long n = 0; float var = 0, mng = 0;
  for (n = 0  ; n < CNT ; n++)mng += s[n];
  mng = mng / CNT;
  for (n = 0  ; n < CNT ; n++)var += pow((mng - s[n]), 2);
  var = var / CNT;
  Serial.println("mng=");
  
  Serial.println(mng);
  Serial.println("var=");
  Serial.println(var);
  delay(1000);
}
