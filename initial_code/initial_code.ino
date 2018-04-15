//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;


char x = 0b00001111;
int arr[5]= {x, 50, 44, 1, 2};
int arr2[5]= {10, 500, 342, 232, 4};
int counter = 0;
unsigned long previousMillis = 0;


void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
    
  
}

void loop() {
 
 
//  for (int i=0; i<5 ; i++){
//     digitalWrite(6, HIGH);
//    digitalWrite(7, LOW);
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, arr[i]);
//    digitalWrite(latchPin, HIGH);
//    
//  digitalWrite(6, LOW);
//  digitalWrite(7, HIGH);
// 
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin, clockPin, MSBFIRST, arr2[i]);
//    digitalWrite(latchPin, HIGH);
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 1000) {
      counter++;
      previousMillis = currentMillis;
    }
    if (counter >= 5) counter = 0;
//    for (int i=0; i<5 ; i++){
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, arr[counter]);
      digitalWrite(latchPin, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, arr2[counter]);
      digitalWrite(latchPin, HIGH);
      
//    }
    
    
    
  }



