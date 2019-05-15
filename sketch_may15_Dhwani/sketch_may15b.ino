#include <Servo.h>

Servo myServo;              // for ultrasound servo
Servo leftW;                // left wheel
Servo rightW;               // right wheel
const int pingPin = 9;      // ultrasound pin provided
int flag = 0, n = 90, i;       // flag for the laert once obstacle encountered & n for angle turn
long T, cm, state1, state2;                 // time taken T & distance of obstacle

void setup() {
  myServo.attach(11);       // ultrasound servo attached
  myServo.write(90);
  leftW.attach(12);
  rightW.attach(13);
  Serial.begin(9600);               // initialise serial communication
}

void Chirp ()                 // send ultrasound chirp & receive too
{
  pinMode(pingPin, OUTPUT);           // The PING))) is triggered by a HIGH pulse of 2 or more microseconds. Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);

  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  
  pinMode(pingPin, INPUT);            // The same pin is used to read the signal from the PING))): a HIGH pulse whose duration is the time (in microseconds)
  T = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(T);
}
  
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void goF(){
  Serial.print("goF    ");
  leftW.write(120);
  rightW.write(60);  
}

void goB(){
  Serial.print("goB   ");
  leftW.write(60);
  rightW.write(120);
}

int alert(int s){
  if(s<=12)
  {
    Serial.print("alert      ");
//    leftW.write(90);
//    rightW.write(90); 
    stop_5();
    flag = 1;
  }  
 return flag;
}

void stop_5(){
  Serial.print("stop_5       ");
  leftW.write(90);
  rightW.write(90); 
  delay(5000);
}

void check(int flag){
  if(flag==1)
  {
    myServo.write(0);
    Chirp();
    alert(cm);
    delay(200);
  //  Chirp();
    if (flag==0)
   { turnL();       Serial.print("Turning left     ");
   }
   else
   { myServo.write(180);
   turnR();
//    Chirp();
//    alert(cm);
loop();
    delay(200);}
  }
}

void turnL(){
 leftW.writeMicroseconds(1300);     // Left wheel clockwise
 rightW.writeMicroseconds(1500);    // Right wheel stop
delay(2000);
  
      leftW.write(90);        
      rightW.write(90);  
   
}

void turnR(){
 leftW.writeMicroseconds(1500);     // Left wheel clockwise
 rightW.writeMicroseconds(1700);    // Right wheel stop
delay(2000);
  
      leftW.write(90);        
      rightW.write(90);  
   
}

void loop() {
  flag = 0;
  goF();

   Chirp();
   alert(cm);
  Serial.print(cm);
  Serial.print("cm     ");
  check(flag);
 // alert(cm);
 // check(flag);
  Serial.println();

 delay (200);
}
