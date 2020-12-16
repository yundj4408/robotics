//Viral Science  www.viralsciencecreativity.com  www.youtube.com/c/viralscience
//LED 8x8 Matrix Display DEMO
//3.3v not work, must be 5V

#include <LedControl.h> //sketch -> add library ledcontrol.h
int DIN = 14;
int CS =  5;
int CLK = 4;

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       
 lc.setIntensity(0,15);      //Adjust the brightness maximum is 15
 lc.clearDisplay(0);    
}

void loop(){ 
    
   
    //Arrow
    //byte arrow_allway[8] = {0x18,0x3C,0x5A,0xFF,0xFF,0x5A,0x3C,0x18};
    byte arrow_allway[8] = {0x3C,0x18,0x99,0xFF,0xFF,0x99,0x18,0x3C};
    
    //three-way Arrow
    byte arrow_LBR[8] = {0x00,0x00,0x81,0xFF,0xFF,0x99,0x18,0x3C};
    byte arrow_FLR[8] = {0x3C,0x18,0x99,0xFF,0xFF,0x81,0x00,0x00};
    byte arrow_FBR[8] = {0x3C,0x18,0x19,0x1F,0x1F,0x19,0x18,0x3C};
    byte arrow_FLB[8] = {0x3C,0x18,0x98,0xF8,0xF8,0x98,0x18,0x3C};

       //two-way Arrow
    byte arrow_BR[8] = {0x00,0x00,0x01,0x1F,0x1F,0x19,0x18,0x3C};
    byte arrow_LR[8] = {0x00,0x00,0x81,0xFF,0xFF,0x81,0x00,0x00};
    byte arrow_LB[8] = {0x00,0x00,0x80,0xF8,0xF8,0x98,0x18,0x3C};
    byte arrow_FR[8] = {0x3C,0x18,0x19,0x1F,0x1F,0x01,0x00,0x00};
    byte arrow_FB[8] = {0x3C,0x18,0x18,0x18,0x18,0x18,0x18,0x3C};
    byte arrow_FL[8] = {0x3C,0x18,0x98,0xF8,0xF8,0x80,0x00,0x00};

    //one-way Arrow
    byte arrow_Forward[8]= {0x18,0x3C,0x7E,0xFF,0x18,0x18,0x18,0x18};
    byte arrow_Backward[8]= {0x18,0x18,0x18,0x18,0xFF,0x7E,0x3C,0x18};
    byte arrow_Left[8] = {0x10,0x30,0x70,0xFF,0xFF,0x70,0x30,0x10};
    byte arrow_Right[8] = {0x08,0x0C,0x0E,0xFF,0xFF,0x0E,0x0C,0x08};
    
    byte arrow_Up[8] = {0x00,0xAF,0xA9,0xA9,0xAF,0xE8,0x08,0x00};
    byte arrow_Down[8] = {0xC6,0xA9,0xA9,0xC6,0x00,0xAF,0xAD,0x75};
    byte ya[8] = {0x08,0x68,0x9F,0x98,0x9F,0x98,0x68,0x08};
    byte ho[8] = {0x18,0x7E,0x3C,0x42,0x42,0x3C,0x18,0xFF};

//Arrow
  /* printByte(arrow_allway);
   delay(1000);

   //three-way
   printByte(arrow_LBR);
   delay(1000);
   printByte(arrow_FLR);
   delay(1000);
   printByte(arrow_FBR);
   delay(1000);
   printByte(arrow_FLB);
   delay(1000);

   //two-way
   printByte(arrow_BR);
   delay(1000);
   printByte(arrow_LR);
   delay(1000);
   printByte(arrow_LB);
   delay(1000);
   printByte(arrow_FR);
   delay(1000);
   printByte(arrow_FB);
   delay(1000);
   printByte(arrow_FL);
   delay(1000);

   //one-way
   printByte(arrow_Forward);
   delay(1000);
   printByte(arrow_Backward);
   delay(1000);
   printByte(arrow_Left);
   delay(1000);
   printByte(arrow_Right);
   delay(1000);*/

    printByte(arrow_allway);
    delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);

    printByte(arrow_Backward);
    delay(600);
    printByte(arrow_Forward);
delay(600);
    printByte(arrow_FB);
    delay(600);
    printByte(arrow_Right);
    delay(600);

    printByte(arrow_BR);
    delay(600);

    printByte(arrow_FB);
    delay(600);

    printByte(arrow_FBR);
    delay(600);

    printByte(arrow_Left);
    delay(600);

    printByte(arrow_LB);
    delay(600);
 
    printByte(arrow_FL);
    delay(600);
  
    printByte(arrow_FLB);
    delay(600);
  
    printByte(arrow_LR);
    delay(600);
  
    printByte(arrow_LBR);
    delay(600);

    printByte(arrow_FLR);
    delay(600);

    printByte(arrow_allway);
    delay(600);

    printByte(arrow_Backward);
    delay(600);

    printByte(arrow_Backward);
    delay(600);
    
    printByte(arrow_Down);    
    delay(600);
    
    printByte(arrow_Forward);
    delay(600);
    
    printByte(arrow_Down); 
    delay(600);
    
    printByte(arrow_FB);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_Right);
    delay(600);
    
    printByte(arrow_Down); 
    delay(600);
    
    printByte(arrow_BR);
    delay(600);
    
    printByte(arrow_Down); 
    delay(600);
    
    printByte(arrow_FR);
    delay(600);
    
    printByte(arrow_Down); 
    delay(600);

    printByte(arrow_FBR);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_Left);
    delay(600);
    
    printByte(arrow_Down); 
    delay(600);
    
    printByte(arrow_LB);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_FL);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_FLB);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_LR);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_LBR);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_FLR);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_allway);
    delay(600);
    
    printByte(arrow_Down);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_Backward);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_Forward);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_FB);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_Right);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_BR);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_FR);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_FBR);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_Right);
    delay(600);
    
    printByte(arrow_Up);
    delay(600);
    
    printByte(arrow_LB);
    delay(600);
    printByte(arrow_Up);
delay(600);
    printByte(arrow_FL);
    delay(600);
    printByte(arrow_Up);
delay(600);
    printByte(arrow_FLB);
    delay(600);
    printByte(arrow_Up);
delay(600);
    printByte(arrow_LR);
    delay(600);
    printByte(arrow_Up);
delay(600);
    printByte(arrow_LBR);
    delay(600);
    printByte(arrow_Up);
delay(600);
    printByte(arrow_FLR);
    delay(600);
    printByte(arrow_Up);
delay(600);
    printByte(arrow_allway);
    delay(600);
    printByte(arrow_Up);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_Backward);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_Forward);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_FB);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_Right);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_BR);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_FR);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_FBR);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_Left);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_LB);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_FL);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_FLB);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_LR);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_LBR);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_FLR);
delay(600);
    printByte(arrow_Up);
    delay(600);
    printByte(arrow_Down);
    delay(600);
    printByte(arrow_allway);
}


void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
