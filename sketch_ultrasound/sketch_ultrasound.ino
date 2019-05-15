#include <Servo.h> 
#include <NewPing.h> 

int UltraSound = 9;
int cm;
NewPing sonar(9,9,200);

void setup() {
  Serial.begin(9600);
  
  
}

void loop() {
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
  delay(100);

}
