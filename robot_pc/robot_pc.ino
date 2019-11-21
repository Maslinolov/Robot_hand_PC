#include <Servo.h>
#include <SoftwareSerial.h>

#define servo0 5
#define servo1 6
#define servo2 7
#define servo3 8
#define servo4 9
#define servo5 10

#define rxh 2
#define txh 3
SoftwareSerial HCSerial(rxh, txh);

Servo srv0, srv1, srv2, srv3, srv4, srv5;

int Pos0 = 90, Pos1 = 90, Pos2 = 90, Pos3 = 90, Pos4 = 90, Pos5 = 90;

char Cntrl;

void setup(){
  pinMode(rxh, INPUT);
  pinMode(txh, OUTPUT);
  HCSerial.begin(38400);
  Serial.begin(9600);
  
  srv0.attach(servo0);
  srv1.attach(servo1);
  srv2.attach(servo2);
  srv3.attach(servo3);
  srv4.attach(servo4);
  srv5.attach(servo5);
  
}

void loop(){
  //Управление модулем через сериал порт
  if(HCSerial.available()){
    char c = HCSerial.read(); 
    Serial.print(c);   
  }
  if(Serial.available()){
    char c = Serial.read();
    HCSerial.print(c);    
  }
  
  //Управление сервами с модуля
  if(HCSerial.available()){  
    char C = HCSerial.read();
    switch(C){
      case 'A':
        Cntrl = 'A';
        break;
      case 'B':
        Cntrl = 'B';
        break;
      case 'C':
        Cntrl = 'C';
        break;
      case 'D':
        Cntrl = 'D';
        break;
      case 'E':
        Cntrl = 'E';
        break;
      case 'F':
        Cntrl = 'F';
        break;
    }
    switch (Cntrl){
      case 'A':
        if(C == 0 && Pos0 >= 0)
          Pos0--;
        if(C == 2 && Pos0 <= 180)
          Pos0++;
        srv0.write(Pos0);
        break;
      case 'B':
        if(C == 0 && Pos1 >= 0)
          Pos1--;
        if(C == 2 && Pos1 <= 180)
          Pos1++;
        srv1.write(Pos1);
        break;
      case 'C':
        if(C == 0 && Pos2 >= 0)
          Pos2--;
        if(C == 2 && Pos2 <= 180)
          Pos2++;
        srv2.write(Pos2);
        break;
      case 'D':
        if(C == 0 && Pos3 >= 0)
          Pos3--;
        if(C == 2 && Pos3 <= 180)
          Pos3++;
        srv3.write(Pos3);
        break;
      case 'E':
        if(C == 0 && Pos4 >= 0)
          Pos4--;
        if(C == 2 && Pos4 <= 180)
          Pos4++;
        srv4.write(Pos4);
        break;
      case 'F':
        if(C == 0 && Pos5 >= 0)
          Pos5--;
        if(C == 2 && Pos5 <= 180)
          Pos5++;
        srv5.write(Pos5);
        break;
    }   
  }
}


