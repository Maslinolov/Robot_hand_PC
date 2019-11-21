#include <SoftwareSerial.h>

#define rxh 2
#define txh 3
#define ChsServ A0
#define CngPos A1

int Pos = 0;
int Srv = 0;

SoftwareSerial HCSerial(rxh, txh);

void setup(){
  pinMode(rxh, INPUT);
  pinMode(txh, OUTPUT);
  HCSerial.begin(38400);
  Serial.begin(9600);  
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
  Srv = analogRead(ChsServ); 
  Pos = analogRead(CngPos);
  //Изменение координаты сервы
  if(Pos >= 205 && Pos <= 510){
    HCSerial.write('0');
  }
  if(Pos >= 715 && Pos <= 920){
    HCSerial.write('2');
  }
  if(Pos > 510 && Pos < 715){
    HCSerial.write('1');
  }
  
  //выбор сервы
  if(Srv > 300 && Srv < 400){
     HCSerial.write('A');
  }
  if(Srv > 400 && Srv < 500){
     HCSerial.write('B');
  }
  if(Srv > 500 && Srv < 600){
     HCSerial.write('C');
  }
  if(Srv > 600 && Srv < 700){
     HCSerial.write('D');
  }
  if(Srv > 700 && Srv < 800){
     HCSerial.write('E');
  }
  if(Srv > 800 && Srv < 900){
     HCSerial.write('F');
  }
  
}
