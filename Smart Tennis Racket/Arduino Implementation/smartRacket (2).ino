#include <SoftwareSerial.h>

int tre = 30;
SoftwareSerial hc06(2,3);

int analogPin1 = 0; //TOP
int analogPin2 = 1; //BOTTOM
int analogPin3 = 2; //LEFT
int analogPin4 = 3; //RIGHT

int val1 = 0; 
int val2 = 0;
int val3 = 0; 
int val4 = 0;

int maxi1 = 0;
int maxi2 = 0;
int maxi3 = 0;
int maxi4 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val1 = analogRead(analogPin1); 
  val2 = analogRead(analogPin2); 
  val3 = analogRead(analogPin3); 
  val4 = analogRead(analogPin4); 

  if (millis() % 1000 == 0){
      Serial.print(maxi1);    //TOP
      Serial.print("\t");
      Serial.print(maxi2);    //BOTTOM
      Serial.print("\t");
      Serial.print(maxi3);    //LEFT
      Serial.print("\t");
      Serial.println(maxi4);  //RIGHT*/
      
      maxi1 = 0;
      maxi2 = 0;
      maxi3 = 0;
      maxi4 = 0;
  }

  if (hc06.available()){
    Serial.print(hc06.read());
  }
  
  // There is noise, therefore if it below 10/1023 volts is not taken in account
  if (val1>tre){ 
    if (val1 > maxi1){
      maxi1 = val1;
    }
  }
  if (val2>tre){ 
    if (val2 > maxi2){
      maxi2 = val2;
    }
  }
  if (val3>tre){ 
    if (val3 > maxi3){
      maxi3 = val3;
    }
  }
  if (val4>tre){ 
    if (val4 > maxi4){
      maxi4 = val4;
    }
  }
}
