//Code written by Alanna Predko, 2439008
//Code adaptation from http://www.instructables.com/member/Enjoying+Electronics/
//As well as the Arduino refferences online

const int redLED = 12;
const int greenLED = 13;

const int combo1 = A0;
const int combo2 = A1;
const int combo3 = A2;
const int combo4 = A3;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorMin = 1023;     
int sensorMax = 0;   

void setup(){
Serial.begin(9600);
pinMode(redLED, OUTPUT);
pinMode(greenLED, OUTPUT);  

while (millis() < 5000) {
    sensorValue1 = analogRead(combo1);

    // record the maximum sensor value
    if (sensorValue1 > sensorMax) {
      sensorMax = sensorValue1;
    }

    // record the minimum sensor value
    if (sensorValue1 < sensorMin) {
      sensorMin = sensorValue1;
    }
  }
}

void loop (){
sensorValue1 = analogRead(combo1);
sensorValue1 = map(sensorValue1, sensorMin, sensorMax, 0, 9);

sensorValue2 = analogRead(combo2);
sensorValue2 = map(sensorValue2, sensorMin, sensorMax, 0, 9);

sensorValue3 = analogRead(combo3);
sensorValue3 = map(sensorValue3, sensorMin, sensorMax, 0, 9);

sensorValue4 = analogRead(combo4);
sensorValue4 = map(sensorValue4, sensorMin, sensorMax, 0, 9);


if (sensorValue1 == 3 && sensorValue2 == 7 &&
    sensorValue3 == 2 && sensorValue4 == 2)
 {
   digitalWrite(greenLED, HIGH);
   digitalWrite(redLED, LOW);
 }

else
 {
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
 }
 
Serial.print(sensorValue1);
Serial.print(sensorValue2);
Serial.print(sensorValue3);
Serial.print(sensorValue4);
Serial.println(); 

}
