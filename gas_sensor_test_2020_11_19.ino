int GasPin0 = A0;   // 가스센서 입력을 위한 아날로그 핀
/*int GasPin1 = A1;
int GasPin2 = A2;
int GasPin3 = A3;
int GasPin4 = A4;
int GasPin5 = A5;

 */
void setup() {
 
  pinMode(GasPin0 ,INPUT);   // 아날로그 핀 A0를 입력모드로 설정
  /*pinMode(GasPin1 ,INPUT);
  pinMode(GasPin2 ,INPUT);
  pinMode(GasPin3 ,INPUT);
  pinMode(GasPin4 ,INPUT);
  pinMode(GasPin5 ,INPUT);*/
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Numberx`,Gas"); 
  Serial.begin(115200);
 
}
 
 
void loop() {
  int value = 0;
  Serial.print("Data,");
  Serial.print("6,");
  Serial.print(analogRead(GasPin0));
  delay(50);
  
  /*Serial.print("Data,");
  Serial.print("13,");
  Serial.println(analogRead(GasPin1));
  delay(200);
  
  Serial.print("Data,");
  Serial.print("11,");
  Serial.println(analogRead(GasPin2));
  delay(200);
  
  Serial.print("Data,");
  Serial.print("10,");
  Serial.println(analogRead(GasPin3));
  delay(200);
  
  Serial.print("Data,");
  Serial.print("9,");
  Serial.println(analogRead(GasPin4));
  delay(200);

  
  Serial.print("Data,");
  Serial.print("8,");
  Serial.println(analogRead(GasPin5));
  delay(200);  

*/

 Serial.println();
  // 가스센서로부터 아날로그 데이터를 받아와 시리얼 모니터로 출력함
  delay(2000);  // 3s 대기
 
} 
