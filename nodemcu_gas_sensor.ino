int GasPin0 = A0;   // 가스센서 입력을 위한 아날로그 핀
int DigitalPin = 16;

 
void setup() {
 
  pinMode(GasPin0 ,INPUT);   // 아날로그 핀 A0를 입력모드로 설정

  Serial.println("CLEARDATA");
  Serial.println("LABEL,Number,Gas, Digital"); 
  Serial.begin(115200);
 
}
 
 
void loop() {
  int value = 0;
  Serial.print("Data,");
  Serial.print("6,");
  Serial.print(analogRead(GasPin0));
  Serial.print(",");
  Serial.print(digitalRead(DigitalPin));
  Serial.println();
 
  delay(2000);  // 3s 대기
 
} 
