#include "hwlib.hpp"
#include "arm/calculations.hpp"
#include "servo/servo.hpp"
#include "arm/arm.hpp"
#include "arm/vector.hpp"
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
   
   Arm arm(len_arm_1,len_arm_2,servo1,servo2,0,0);

   auto potx = target::pin_adc(target::ad_pins::a0);
   auto poty = target::pin_adc(target::ad_pins::a1);
   
   joystick joystick(potx,poty);

   
   int x = 170;
   int y = 170;
   arm.setPos(x,y);
   display << "\fX:" << arm.getX() << "\nY: " << arm.getY() << "\nS1:" << arm.getServo1Degrees() << "\nS2:" << arm.getServo2Degrees() << hwlib::flush;

   // keep checking if the user moved the joystick and if that is the case, move the arm a bit and update the display
  for(;;){
    if (joystick.left()){
        x -= 10;
        arm.setPos(x,y);
        display << "\fX:" << arm.getX() << "\nY: " << arm.getY() << "\nS1:" << arm.getServo1Degrees() << "\nS2:" << arm.getServo2Degrees() << hwlib::flush;
    }
    else if (joystick.right()){
        x+=10;
        arm.setPos(x,y);
        display << "\fX:" << arm.getX() << "\nY: " << arm.getY() << "\nS1:" << arm.getServo1Degrees() << "\nS2:" << arm.getServo2Degrees() << hwlib::flush;
    }
    if (joystick.up()){
        y += 10;
        arm.setPos(x,y);
        display << "\fX:" << arm.getX() << "\nY: " << arm.getY() << "\nS1:" << arm.getServo1Degrees() << "\nS2:" << arm.getServo2Degrees() << hwlib::flush;
    }
    else if (joystick.down()){
        y-=10;
        arm.setPos(x,y);
        display << "\fX:" << arm.getX() << "\nY: " << arm.getY() << "\nS1:" << arm.getServo1Degrees() << "\nS2:" << arm.getServo2Degrees() << hwlib::flush;
    }

  };
};
