int Fire = A0;
int Firedig = 2;

void setup()
{
 Serial.begin(9600);
 pinMode(Firedig, OUTPUT); 
}


void loop()
{
 int value1 = analogRead(Fire);
  //Serial.println(value1);
  //Serial.println(value2)
  Serial.println(value1);
  Serial.println(" ");
  
  
 
 //Serial.println(value3);
 if (value1 < 400)
 {
  digitalWrite(Firedig, HIGH);
 }
 if (value1 > 600 )
  {
   digitalWrite(Firedig, LOW);
  }
 
}
 /*
 led(RightGas, LeftLed, RightLed, UpLed, DownLed);
 led(UpGas, LeftLed, RightLed, UpLed, DownLed);
 led(DownGas, LeftLed, RightLed, UpLed, DownLed);
 감지되고 있으면 대충 400
 감지 안되면 670~700
 1cm정도는 십의자리 40~`100
 10cm정도는 400정도?
 아두이노에서 적외선 나오니 조심!!!!!!!!!!!!!!!!!!!!!!!!!

첫번째꺼 700정도
두번째꺼 560~590
 
*/
 
