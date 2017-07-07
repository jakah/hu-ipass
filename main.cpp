#include "hwlib.hpp"
#include "arm/calculations.hpp"
#include "servo/servo.hpp"
#include "arm/arm.hpp"
/// \file
/// \mainpage
/// This a project made as a school project. It consists of two library's, one for servo's 
/// and one for the whole robotarm. The servo library is in the servo folder, the robotarm is in the robotarm folder.
/// The robotarm uses the servo library, but another servo library can be used.
int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   namespace target = hwlib::target;


   // initialize servo pins
   auto servo1_pin = target::pin_out(target::pins::d13);
   auto servo2_pin = target::pin_out(target::pins::d12);

   Servo servo1(servo1_pin);
   Servo servo2(servo2_pin);
   
   int len_arm_1 = 170;
   int len_arm_2 = 100;
   
   Arm arm(len_arm_1,len_arm_2,servo1,servo2,30,20);
   int x = -50;
   int y = 150;
  for(;;){
    arm.setPos(x,y);
    arm.updateServos();
  };
};
