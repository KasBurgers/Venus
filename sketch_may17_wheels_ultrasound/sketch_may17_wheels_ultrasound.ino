#include <Servo.h>

Servo myServo;              // for ultrasound servo
Servo leftW;                // left wheel
Servo rightW;               // right wheel
const int pingPin = 9;      // ultrasound pin provided
int flag = 0, n = 90;       // flag for the laert once obstacle encountered & n for angle turn
long T, cm;                 // time taken T & distance of obstacle

void setup() {
  myServo.attach(11);       // ultrasound servo attached
  myServo.write(90);
  leftW.attach(12);
  rightW.attach(13);
  Serial.begin(9600);               // initialise serial communication
}


  //////////////////////////////  CONVERTING MICROSECONDS TO CENTIMETERS  //////////////////////////////////////////
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

  /////////////////////////////   ULTRASOUND SIGNAL SENT, RECEIVED & DISPLAYED  /////////////////////////////////////
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
  Serial.print(cm);
  Serial.print("cm     ");
}

  ////////////////////////////  MOVING FORWARD  //////////////////////////////////////////////
void goF(){
  Serial.print("goF    ");
  leftW.write(120);
  rightW.write(60);  
}

  ////////////////////////////  MOVING BACKWARD  //////////////////////////////////////////////
void goB(){
  Serial.print("goB   ");
  leftW.write(60);
  rightW.write(120);
}

  ////////////////////////////  ALERTING SYSTEM ABOUT OBSTACLE  //////////////////////////////////////////////
int alert(int s){
  Chirp();
  if(s<=12)
  {
    Serial.print("alert      ");
    stop_5();
    flag = 1;
  }  
  else 
  flag=0;
 return flag;
}

  ////////////////////////////  STOPPING FOR 5 SECONDS  //////////////////////////////////////////////
void stop_5(){
  Serial.print("stop_5       ");
  leftW.write(90);
  rightW.write(90); 
  delay(5000);
}

  ////////////////////////////  TURNING LEFT  //////////////////////////////////////////////
void turnL(){
  Serial.print("in turn left     ");
 leftW.writeMicroseconds(1300);         // Left wheel clockwise
  rightW.writeMicroseconds(1300);        // Right wheel clockwise
  myServo.write(90);
  delay(600);                                // ...for 0.6 seconds
  
//      leftW.write(90);        
//      rightW.write(90); 
//      delay(2000); 
   goF();
}

  ////////////////////////////  TURNING RIGHT  //////////////////////////////////////////////
void turnR(){
  Serial.print("in turn right     ");
leftW.writeMicroseconds(1800);         // Left wheel counterclockwise
  rightW.writeMicroseconds(1800);        // Right wheel counterclockwise
  myServo.write(90);
  delay(600);                                // ...for 0.6 seconds
  
//      leftW.write(90);        
//      rightW.write(90);  
//      delay(2000);
   goF();
}

  ////////////////////////////  CHECKING OF OBSTACLES ON LEFT SIDE  //////////////////////////////////////////////
void checkL(){
  Serial.print("in checkL  flag is:");
  Serial.print(flag); Serial.print("    ");
  stop_5();
  if(flag==1)
  {
    myServo.write(180);
    alert(cm);
     Serial.print("in checkR_if flag is:");
  Serial.print(flag); Serial.print("    ");
  stop_5();
    delay(200);
  //  Chirp();
    if (flag==0)
   { turnL();       
   Serial.print("Turning left     ");
   //delay(2000);
//   break;
   }
   else{
//                                               { myServo.write(0);
//                                               Serial.print("turning right      ");
//                                               turnR();
checkR();
   }

   
    }
}


  ////////////////////////////  CHECKING OF OBSTACLES ON RIGHT SIDE  //////////////////////////////////////////////
void checkR(){
   Serial.print("in checkR  flag is:");
  Serial.print(flag); Serial.print("    ");
  stop_5();
  if(flag==1)
  {
    myServo.write(0);
   alert(cm);
    delay(200);
  //  Chirp();
   Serial.print("in checkR_if flag is:");
  Serial.print(flag); Serial.print("    ");
  stop_5();
    if (flag==0)
   { turnR();       Serial.print("Turning right in checkR     ");
   
 //  delay(2000);
//   break;
   }
   else
   { 
   checkL();
 
  }
}}


  ////////////////////////////  CHECKING OF OBSTACLES IN FRONT //////////////////////////////////////////////
void checkF(){
  Serial.print("in checkF  ");
  
  alert(cm);
  Serial.print("in checkF  flag is:");
  Serial.print(flag); Serial.print("    ");
  if(flag==1)
  {
    checkR();
//    break;
   }
   else{
        goF();
   }

  //  delay(2000);
    }


void loop() {
  flag = 0;
  goF();
  //stop_5();
  Chirp();
 // stop_5();
  checkF();
//  stop_5();
}
