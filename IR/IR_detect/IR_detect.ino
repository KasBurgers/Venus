// put your setup code here, to run once:
// define max voltage


int ir_detect_volt(char[2] pinName)
{
      int voltage_max=5000;
      int voltage_step=voltage_max/1024;
      int in=0;
      int in=analogRead(pinName);
      
      voltage_ir=ir*voltage_step;
      return voltage_ir;
}

int ir_detect_rock(char[2] pinName){

      inputVolt=ir_detect_volt(pinName)
      if (inputVolt>1e3){
        detect=1
      }
      else {detect=0;}
      return detect;
}

int ir_detect_border(char[2] pinName){

      inputVolt=ir_detect_volt(pinName)
      if inputVolt<600{
        detect=1
      }
      else {detect=0}
      return detect;
}

//for rocks:
//nothing 0.5v
//15cm 1V
//10cm 2V
//5cm 3.5V

//for ground
//black=0.5v
//white=2.5V
