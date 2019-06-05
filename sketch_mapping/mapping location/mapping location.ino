#include <Servo.h>;
Servo wheel_left;
Servo wheel_right;
int pin_wheel_left = 12;
int pin_wheel_right = 13;



int coor[] = {0,0,0}; //{x, y, dir}
int count1 = 0;
int count2 = 0;
int enc_pin_left = 7;
int enc_pin_right = 8;
int dir = 0;
int prev_value1;
int prev_value2;
int value_now1;
int value_now2;
int Degrees = 0;

void setup() {
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  prev_value1 = digitalRead(enc_pin_left);
  prev_value2 = digitalRead(enc_pin_right);
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  wheel_left.attach(pin_wheel_left);
  wheel_right.attach(pin_wheel_right);
  wheel_left.write(1700);   //drive forwards
  wheel_right.write(1300);  //drive backwards
}

void loop() {
  //determine location:
  value_now1 = digitalRead(enc_pin_left);
  value_now2 = digitalRead(enc_pin_right);

  if (value_now1 != prev_value1) {
    count1++;
    prev_value1 = value_now1;
  }
  if (value_now2 != prev_value2) {
    count2++;
    prev_value2 = value_now2;
  }
  if ((count1 >= 20) and (count2 >= 20)) {
    if (coor[2]==0) {  //north
      coor[1]++;
    }
    if (coor[2]==90) { //east
      coor[0]++;
    }
    if (coor[2]==180) {  //south
      coor[1]--;
    }
    if (coor[2]==270) {  //west
      coor[0]--;
    }
    count1=0;
    count2=0;
  }
  
  //determine direction:
  int DegreesINT = (int) Degrees;
  dir = dir + DegreesINT;
  if (dir >= 360) {
     dir = dir%360;
  }
  else if (dir <= -360) {
     dir = dir%(-360);
  }
}
