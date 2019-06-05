#include <Servo.h>
#include <Sensors.h>
#include <Movement.h>

int dist;                       //distance of rover from the obstacle

void setup() {
 Serial.begin(9600);
// Sensors::ultrasound();
 Move::head(90);
// Move::drive_c();
// delay(500);
// Move::stop_drive();
}

void save_obstacle_in_memory()
{
  Serial.print("      Entering saving obs     \n");
 Sensors::ultrasound();
 dist = Sensors::ultrasoundReturn;
 Serial.print(dist);
 delay(200);

 if(dist<=12)                     //alerting system about approaching obstacle
     {
        Move::drive(0);
        //delay(200);
        Serial.print("      ALERT");
        delay(200);
        Move::head(0);
        Sensors::ultrasound();
       if(dist<=12)                     //alerting system about approaching obstacle ON LEFT
       {
            Serial.print("      ALERT LEFT");
            delay(200);
            rotate_right_90d();
            Move::head(90);
            Move::drive_c();
        }
        else
        {
              Serial.print("      RIGHT");
            delay(200);
              rotate_left_90d();
              Move::head(90);
              Move::drive_c();
          }
      }
  else
  Move::drive_c();
}

void rotate_left_90d()
{
  Move::turn(-90);
}

void rotate_right_90d()
{
  Move::turn(90);
}

void loop() {
  save_obstacle_in_memory();
}
