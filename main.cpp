#include "hwlib.hpp"
#include "servo/servo.hpp"
#include "arm/advancedservoarm.hpp"
#include "arm/coordinate.hpp"
#include "joystick/joystick.hpp"
/// \file
/// \mainpage
/// This a project made as a school project. It consists of two library's, one for servo's 
/// and one for the whole robotarm. The servo library is in the servo folder, the robotarm is in the robotarm folder.
/// The robotarm uses the servo library, but another servo library can be used.

/// \brief
/// main function of the demo application
/// \details
/// The main function of a demo application that uses a robotarm with servo motor's and a joystick.
int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   namespace target = hwlib::target;
   // initialze display 
   auto scl     = target::pin_oc( target::pins::scl );
   auto sda     = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c );

   auto font    = hwlib::font_default_16x16();
   auto display = hwlib::window_ostream( oled, font );

   // initialize servo pins
   auto servo1_pin = target::pin_out(target::pins::d13);
   auto servo2_pin = target::pin_out(target::pins::d12);

   Servo servo1(servo1_pin);
   Servo servo2(servo2_pin);
   
   int len_arm_1 = 170;
   int len_arm_2 = 100;
   
   advancedservoarm arm(len_arm_1,len_arm_2,servo1,servo2,0,-5);

   // initialize the joystick
   auto potx = target::pin_adc(target::ad_pins::a0);
   auto poty = target::pin_adc(target::ad_pins::a1);
   
   joystick joystick(potx,poty);

   // set a start position
   coordinate position (170,170);
   arm.set_position(position);
   display << "\fX:" << arm.get_X() << "\nY:" << arm.get_Y() << "\nS1:" << arm.get_joint1_degrees() << "\nS2:" << arm.get_joint2_degrees() << hwlib::flush;

   // keep checking if the user moved the joystick and if that is the case, move the arm a bit and update the display
  for(;;){
    if (joystick.left()){
        position -= coordinate (10,0);
        arm.set_position(position);
        display << "\fX:" << arm.get_X() << "\nY:" << arm.get_Y() << "\nS1:" << arm.get_joint1_degrees() << "\nS2:" << arm.get_joint2_degrees() << hwlib::flush;
    }
    else if (joystick.right()){
        position += coordinate(10,0);
        arm.set_position(position);
        display << "\fX:" << arm.get_X() << "\nY:" << arm.get_Y() << "\nS1:" << arm.get_joint1_degrees() << "\nS2:" << arm.get_joint2_degrees() << hwlib::flush;
    }
    if (joystick.up()){
        position += coordinate (0,10); 
        arm.set_position(position);
        display << "\fX:" << arm.get_X() << "\nY:" << arm.get_Y() << "\nS1:" << arm.get_joint1_degrees() << "\nS2:" << arm.get_joint2_degrees() << hwlib::flush;
    }
    else if (joystick.down()){
        position -= coordinate (0,10); 
        arm.set_position(position);
        display << "\fX:" << arm.get_X() << "\nY:" << arm.get_Y() << "\nS1:" << arm.get_joint1_degrees() << "\nS2:" << arm.get_joint2_degrees() << hwlib::flush;
    }
  };
};
