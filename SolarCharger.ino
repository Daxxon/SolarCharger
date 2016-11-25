#include <TimeLib.h>
int i = 0;

void setup() { 
  DDRB = 31; 
  PORTB = 0; 
  Serial.begin(9600); 
} 
 
void loop() { 
  checkTime();
} 
 
void chargeBatteryA(){ 
  dischargeBatteryB(); 
  PORTB |= 28; //xxx111xx 
} 
 
void chargeBatteryB(){ 
  dischargeBatteryA(); 
  PORTB &= ~28; //xxx000xx 
} 
 
void dischargeBatteryA(){ 
  PORTB &= ~2; //xxxxxx00 
  delay(100); 
  PORTB |= 1; //xxxxxx01 
} 
 
void dischargeBatteryB(){ 
  PORTB &= ~1; //xxxxxx00 
  delay(100); 
  PORTB |= 2; //xxxxxx10 
}

void checkTime(){
  if (now() % 15 == 0){
    Serial.println(now());
    Serial.println(i);
    i++;
    switchBattery();
  }
}

void switchBattery(){
  (i % 2 == 0) ? chargeBatteryA() : chargeBatteryB();
  delay(2000);
}
 
/* 
128.64.32.16.8.4.2.1 
*/ 
 
