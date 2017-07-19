#include "hwlib.hpp"
#include "../servo/servo.hpp"

int main(void){
   WDT->WDT_MR = WDT_MR_WDDIS;
   namespace target = hwlib::target;

      auto servo1_pin = target::pin_out(target::pins::d13);

    Servo servo1(servo1_pin);

  for(;;){
      servo1.setServo(0);
  for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
      servo1.setServo(15);
   for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
  servo1.setServo(30);
   for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
   hwlib::wait_ms(1000);
         servo1.setServo(45);
   for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
  servo1.setServo(60);
   for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
         servo1.setServo(75);
   for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
  hwlib::wait_ms(1000);
  servo1.setServo(90);
   for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
     servo1.setServo(105);
   for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
     servo1.setServo(120);
   for (int i = 0; i < 1000; i++){
        servo1.updateServo();
        hwlib::wait_ms(1);
   }
}
}