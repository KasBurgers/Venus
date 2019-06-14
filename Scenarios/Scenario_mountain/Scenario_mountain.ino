#include <Servo.h>
#include <Sensors.h>
#include <Movement.h>

int dist;                       //distance of rover from the obstacle
int n = 90;                     //angle of the head

void setup() {
 Serial.begin(9600);
 delay(100);
}

void save_obstacle_in_memory()
{
 dist =  Sensors::ultrasound();
 delay(200);

 if(dist<=20)                     //alerting system about approaching obstacle
     {
        Move::stop_drive();
        Move::head(45);
        dist = Sensors::ultrasound();
        delay(200);
        if(dist<=20)                     //alerting system about approaching obstacle ON LEFT
        {
            Move::turn(-90);
            Move::head(90);
            Move::drive_c();
        }
        else
        {
              Move::turn(90);
              Move::head(90);
              Move::drive_c();
          }
      }
  else
  Move::drive_c();
}


void loop() {
  save_obstacle_in_memory();
}
