/************************** Configuration ***********************************/

/* edit the config.h tab and enter your Adafruit IO credentials
 and any additional configuration needed for WiFi, cellular,
 or ethernet clients.*/
#include "config.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LedControl.h> 

int CS =  5;
int CLK = 4;

int smoke_flag=0;
int fire_flag = 0;

int originSmoke;
float originFire;

int DIN = 16;  //LED 핀
const int oneWireBus = 12;  //온도센서 핀   
int smokeA0 = A0;  //연기센서 핀

unsigned short tempL = 0;
unsigned short tempH = 0;

/* LED 방향 표시용 */
byte arrow_EXIT[8] = {0x18,0x58,0x7E,0x1A,0x18,0x3C,0x67,0x40};
byte arrow_FBLR[8] = {0x3C,0x18,0x99,0xFF,0xFF,0x99,0x18,0x3C};
  
  //three-way Arrow
byte arrow_BLR[8] = {0x00,0x00,0x81,0xFF,0xFF,0x99,0x18,0x3C};
byte arrow_FLR[8] = {0x3C,0x18,0x99,0xFF,0xFF,0x81,0x00,0x00};
byte arrow_FBR[8] = {0x3C,0x18,0x19,0x1F,0x1F,0x19,0x18,0x3C};
byte arrow_FBL[8] = {0x3C,0x18,0x98,0xF8,0xF8,0x98,0x18,0x3C};
 
 //two-way Arrow
byte arrow_BR[8] = {0x00,0x00,0x01,0x1F,0x1F,0x19,0x18,0x3C};
byte arrow_LR[8] = {0x00,0x00,0x81,0xFF,0xFF,0x81,0x00,0x00};
byte arrow_BL[8] = {0x00,0x00,0x80,0xF8,0xF8,0x98,0x18,0x3C};
byte arrow_FR[8] = {0x3C,0x18,0x19,0x1F,0x1F,0x01,0x00,0x00};
byte arrow_FB[8] = {0x3C,0x18,0x18,0x18,0x18,0x18,0x18,0x3C};
byte arrow_FL[8] = {0x3C,0x18,0x98,0xF8,0xF8,0x80,0x00,0x00};

 //one-way Arrow
byte arrow_F[8]= {0x18,0x3C,0x7E,0xFF,0x18,0x18,0x18,0x18};
byte arrow_B[8]= {0x18,0x18,0x18,0x18,0xFF,0x7E,0x3C,0x18};
byte arrow_L[8] = {0x10,0x30,0x70,0xFF,0xFF,0x70,0x30,0x10};
byte arrow_R[8] = {0x08,0x0C,0x0E,0xFF,0xFF,0x0E,0x0C,0x08};

 //Up Arrow
byte arrow_UFBLR[8] = {0xBD,0x5A,0xBD,0xFF,0xFF,0x99,0x18,0x3C};
byte arrow_UFBL[8] = {0xBD,0x5A,0xBC,0xF8,0xF8,0x98,0x18,0x3C};
byte arrow_UFBR[8] = {0xBD,0x5A,0x3D,0x1F,0x1F,0x19,0x18,0x3C};
byte arrow_UFLR[8] = {0xBD,0x5A,0xBD,0xFF,0xFF,0x81,0x00,0x00};
byte arrow_UBLR[8] = {0x81,0x42,0xA5,0xFF,0xFF,0x99,0x18,0x3C};
byte arrow_UFB[8] = {0xBD,0x5A,0x3C,0x18,0x18,0x18,0x18,0x3C};
byte arrow_UFR[8] = {0xBD,0x5A,0x3D,0x1F,0x1F,0x01,0x00,0x00};
byte arrow_ULR[8] = {0x81,0x42,0xA5,0xFF,0xFF,0x81,0x00,0x00};
byte arrow_UFL[8] = {0xBD,0x5A,0xBC,0xF8,0xF8,0x80,0x00,0x00};
byte arrow_UBL[8] = {0x81,0x42,0xA4,0xF8,0xF8,0x98,0x18,0x3C};
byte arrow_UBR[8] = {0x81,0x42,0x25,0x1F,0x1F,0x19,0x18,0x3C};
byte arrow_UF[8] = {0xBD,0x5A,0x3C,0x18,0x18,0x00,0x00,0x00};
byte arrow_UB[8] = {0x81,0x42,0x24,0x18,0x18,0x18,0x18,0x3C};
byte arrow_UL[8] = {0x81,0x42,0xA4,0xF8,0xF8,0x80,0x00,0x00};
byte arrow_UR[8] = {0x81,0x42,0x25,0x1F,0x1F,0x01,0x00,0x00};
byte arrow_U[8] = {0x81,0x42,0x24,0x18,0x18,0x00,0x00,0x00};


 //Down Arrow
byte arrow_DFBLR[8] = {0x3C,0x18,0x99,0xFF,0xFF,0xBD,0x5A,0xBD};
byte arrow_DFBL[8] = {0x3C,0x18,0x98,0xF8,0xF8,0xBC,0x5A,0xBD};
byte arrow_DFBR[8] = {0x3C,0x18,0x19,0x1F,0x1F,0x3D,0x5A,0xBD};
byte arrow_DFLR[8] = {0x3C,0x18,0x99,0xFF,0xFF,0xA5,0x42,0x81};
byte arrow_DBLR[8] = {0x00,0x00,0x81,0xFF,0xFF,0xBD,0x5A,0xBD};
byte arrow_DFB[8] = {0x3C,0x18,0x18,0x18,0x18,0x3C,0x5A,0xBD};
byte arrow_DFR[8] = {0x3C,0x18,0x19,0x1F,0x1F,0x25,0x42,0x81};
byte arrow_DLR[8] = {0x00,0x00,0x81,0xFF,0xFF,0xA5,0x42,0x81};
byte arrow_DFL[8] = {0x3C,0x18,0x98,0xF8,0xF8,0xA4,0x42,0x81};
byte arrow_DBL[8] = {0x00,0x00,0x80,0xF8,0xF8,0xBC,0x5A,0xBD};
byte arrow_DBR[8] = {0x00,0x00,0x01,0x1F,0x1F,0x3D,0x5A,0xBD};
byte arrow_DF[8] = {0x3C,0x18,0x18,0x18,0x18,0x24,0x42,0x81};
byte arrow_DB[8] = {0x00,0x00,0x00,0x18,0x18,0x3C,0x5A,0xBD};
byte arrow_DL[8] = {0x00,0x00,0x80,0xF8,0xF8,0xA4,0x42,0x81};
byte arrow_DR[8] = {0x00,0x00,0x01,0x1F,0x1F,0x25,0x42,0x81};
byte arrow_D[8] = {0x00,0x00,0x00,0x18,0x18,0x24,0x42,0x81};

//UP DOWN Arrow
byte arrow_UDFBLR[8] = {0xBD,0x5A,0xBD,0xFF,0xFF,0xBD,0x5A,0xBD};
byte arrow_UDFBL[8] = {0xBD,0x5A,0xBC,0xF8,0xF8,0xBC,0x5A,0xBD};
byte arrow_UDFBR[8] = {0xBD,0x5A,0x3D,0x1F,0x1F,0x3D,0x5A,0xBD};
byte arrow_UDFLR[8] = {0xBD,0x5A,0xBD,0xFF,0xFF,0xA5,0x42,0x81};
byte arrow_UDBLR[8] = {0x81,0x42,0xA5,0xFF,0xFF,0xBD,0x5A,0xBD};
byte arrow_UDFB[8] = {0xBD,0x5A,0x3C,0x18,0x18,0x3C,0x5A,0xBD};
byte arrow_UDFR[8] = {0xBD,0x5A,0x3D,0x1F,0x1F,0x25,0x42,0x81};
byte arrow_UDLR[8] = {0x81,0x42,0xA5,0xFF,0xFF,0xA5,0x42,0x81};
byte arrow_UDFL[8] = {0xBD,0x5A,0xBC,0xF8,0xF8,0xA4,0x42,0x81};
byte arrow_UDBL[8] = {0x81,0x42,0xA4,0xF8,0xF8,0xBC,0x5A,0xBD};
byte arrow_UDBR[8] = {0x81,0x42,0x25,0x1F,0x1F,0x3D,0x5A,0xBD};
byte arrow_UDF[8] = {0xBD,0x5A,0x3C,0x18,0x18,0x24,0x42,0x81};
byte arrow_UDB[8] = {0x81,0x42,0x24,0x18,0x18,0x3C,0x5A,0xBD};
byte arrow_UDL[8] = {0x81,0x42,0xA4,0xF8,0xF8,0xA4,0x42,0x81};
byte arrow_UDR[8] = {0x81,0x42,0x25,0x1F,0x1F,0x25,0x42,0x81};
byte arrow_UD[8] = {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};


/*set up the feed*/
AdafruitIO_Feed *Led = io.feed("node00.led00"); //FeedName 보드마다 노드별로 매칭
AdafruitIO_Feed *Fire = io.feed("node00.fire00");
AdafruitIO_Feed *Smoke = io.feed("node00.smoke00");

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup() {

  // start the serial connection
  Serial.begin(115200);
  sensors.begin();
  pinMode(4,OUTPUT);
  pinMode(smokeA0, INPUT);

  // 초기값 저장
  originSmoke = analogRead(smokeA0); 
  originFire = sensors.getTempCByIndex(0);

  // wait for serial monitor to open  
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // start MQTT connection to io.adafruit.com
  io.connect();

  /*set up a message handler for the feed.
   the handleMessage function (defined below)
   will be called whenever a message is
   received from adafruit io. */
  Led->get();
  Led->onMessage(handleMessage);
 
  /* wait for an MQTT connection
   NOTE: when blending the HTTP and MQTT API, always use the mqttStatus
   method to check on MQTT connection status specifically */
  while(io.mqttStatus() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  /* Because Adafruit IO doesn't support the MQTT retain flag, we can use the
   get() function to ask IO to resend the last value for this feed to just
   this MQTT client after the io client is connected. */
 
  
  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  
  lc.shutdown(0,false);       
  lc.setIntensity(0,15); //Adjust the brightness maximum is 15
  lc.clearDisplay(0);  
  
}

void loop() {
  
  sensors.requestTemperatures(); 
  float analogFire = sensors.getTempCByIndex(0);
  int analogSmoke = analogRead(smokeA0);

  Serial.print(analogFire);
  Serial.println("ºC");
  Serial.print("Pin A0: ");
  Serial.println(analogSmoke);
  
  io.run();

  /*가스 값이 초기값 보다 50 이상 클 경우, 화재라고 판단 -> adafruit에 값 전송*/
  if (((originSmoke + 50) < analogSmoke) && smoke_flag==0)
  {
     smoke_flag =1;
     Smoke->save(analogSmoke);
     Serial.println("Data sent");
  }

  /*화재 판단 이후, 가스 값이 초기값 보다 30 이상 작을 경우, 화재 진압 완료 상태라고 판단 -> adafruit에 값 전송*/
  else if(((originSmoke + 30) > analogSmoke) && smoke_flag ==1){
    smoke_flag=0;
    Smoke->save(analogSmoke);
    Serial.println("Data sent");
  }

  /*온도가 65도 보다 높은 경우, 화재라고 판단 -> adafruit에 값 전송*/
  if (analogFire > 65 && fire_flag==0)
  {
     fire_flag =1;
     Fire->save(analogFire);
     Serial.println("Data sent");
  }

  /*화재 판단 이후, 온도가 40도 보다 낮을 경우, 화재 진압 완료 상태라고 판단 -> adafruit에 값 전송*/
  else if(analogFire < 40 && fire_flag ==1){
    fire_flag=0;
    Fire->save(analogFire);
    Serial.println("Data sent");
  }

 
  delay(5000);
  

}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

/* this function is called whenever a 'LED' message
 is received from Adafruit IO. it was attached to
 the led feed in the setup() function above.*/
void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");
  Serial.println(data->value());
  int state = data->toInt();
  
  if(state==0){
    printByte(arrow_EXIT);
  }
  if(state==1){
    printByte(arrow_D);
  }
  if(state==2)
  {
    printByte(arrow_U);
  }
  if(state==3){
    printByte(arrow_UD);
    
  }
  if(state==4){
    printByte(arrow_R);
    
  }
  if(state==5){
    printByte(arrow_DR);
    
  }
  if(state==6){
    printByte(arrow_UR);
    
  }
  if(state==7){
    printByte(arrow_UDR);
    
  }
  if(state==8){
    printByte(arrow_L);
    
  }
  if(state==9){
    printByte(arrow_DL);
    
  }
  if(state==10){
    printByte(arrow_UL);
    
  }
  if(state==11){
    printByte(arrow_UDL);
    
  }
  if(state==12){
    printByte(arrow_LR);
    
  }
  if(state==13){
    printByte(arrow_DLR);
    
  }
  if(state==14){
    printByte(arrow_ULR);
    
  }
  if(state==15){
    printByte(arrow_UDLR);
    
  }
  if(state==16){
    printByte(arrow_B);
    
  }
  if(state==17){
    printByte(arrow_DB);   
  }
  if(state==18){
    printByte(arrow_UB);
  }
  if(state==19){
    printByte(arrow_UDB);
  }
  if(state==20){
    printByte(arrow_BR);
  }
  if(state==21){
   printByte(arrow_DBR);
  }
  if(state==22){
    printByte(arrow_UBR);
  }
  if(state==23){
    printByte(arrow_UDBR); 
  }
  if(state==24){
    printByte(arrow_BL);
  }
  if(state==25){
    printByte(arrow_DBL);
  }
  if(state==26){
    printByte(arrow_UBL);
  }
  if(state==27){
    printByte(arrow_UDBL);
  }
  if(state==28){
    printByte(arrow_BLR);
  }
  if(state==29){
    printByte(arrow_DBLR);
  }
  if(state==30){
    printByte(arrow_UBLR);
  }
  if(state==31){
    printByte(arrow_UDBLR); 
  }
  if(state==32){
    printByte(arrow_F);
  }
  if(state==33){
    printByte(arrow_DF);
  }
  if(state==34){
    printByte(arrow_UF);
  }
  if(state==35){
    printByte(arrow_UDF);
  }
  if(state==36){
    printByte(arrow_FR);
  }
  if(state==37){
    printByte(arrow_DFR);
  }
  if(state==38){
    printByte(arrow_UFR);
  }
  if(state==39){
   printByte(arrow_UDFR);
  }
  if(state==40){
    printByte(arrow_FL);
  }
  if(state==41){
    printByte(arrow_DFL);
  }
  if(state==42){
    printByte(arrow_UFL);
  }
  if(state==43){
    printByte(arrow_UDFL);
  }
  if(state==44){
    printByte(arrow_FLR);
  }
  if(state==45){
    printByte(arrow_DFLR);
  }
  if(state==46){
    printByte(arrow_UFLR);
  }
  if(state==47){
    printByte(arrow_UDFLR);
  }
  if(state==48){
    printByte(arrow_FB);
  }
  if(state==49){
   printByte(arrow_DFB);
  }
  if(state==50){
    printByte(arrow_UFB);
  }
  if(state==51){
    printByte(arrow_UDFB);
  }
  if(state==52){
    printByte(arrow_FBR);
  }
  if(state==53){
    printByte(arrow_DFBR);
  }
  if(state==54){
    printByte(arrow_UFBR);
  }
  if(state==55){
    printByte(arrow_UDFBR);
  }
  if(state==56){
    printByte(arrow_FBL);
  }
  if(state==57){
    printByte(arrow_DFBL);
  }
  if(state==58){
    printByte(arrow_UFBL);
  }
  if(state==59){
    printByte(arrow_UDFBL);
  }
  if(state==60){
    printByte(arrow_FBLR);
  }
  if(state==61){
    printByte(arrow_DFBLR);
  }
  if(state==62){
    printByte(arrow_UFBLR);
  }
  if(state==63){
    printByte(arrow_UDFBLR);
  }
                          
   
}
