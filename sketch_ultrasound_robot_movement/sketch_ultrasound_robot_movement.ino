#include <Servo.h>
#include <Sensors.h>
#include <Movement.h>

int dist;                       //distance of rover from the obstacle
int n = 90;                     //angle of the head
int theta = 0;                  //rotation of robot

void setup() {
 Serial.begin(9600);
 Move::head(n);
}

void save_obstacle_in_memory()
{
  Serial.print("      Entering saving obs     \n");
 Sensors::ultrasound();
 dist = Sensors::ultrasoundReturn;
 Serial.print(dist);
 delay(200);
//  dist = 12;
   
 if(dist<=12)                     //alerting system about approaching obstacle
     {
        Serial.print("        ALERT \n");
       if(n==90){
          n=n-90;
          Move::head(n);
       //   break;
        }
        else if(n<90){
          n=n+180;
          Move::head(n);
        //  break;
        }
        else if(n>90){
          n=n-180;
          Move::head(n);
         // break;
        }
      }
  else
  {
    if (n==90)
        Move::drive_c();
    else if (n<90)
        {
          rotate_left_90d();
          Move::drive_c();
        }
    else if (n>90)
        {
          rotate_right_90d();
          Move::drive_c();  
        }
  }
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
