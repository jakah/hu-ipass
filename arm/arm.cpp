#include "arm.hpp"
#include "../servo/servo.hpp"
#include "calculations.hpp"

Arm::Arm(int &len1, int &len2, Servo &servo1, Servo &servo2, int servo1_Offset, int servo2_Offset):
    len1(len1),len2(len2),servo1(servo1),servo2(servo2),servo1_Offset(servo1_Offset),servo2_Offset(servo2_Offset){
        x_pos = 0;
        y_pos = 0;
    };

void Arm::setPos(int &x, int &y){
    uint16_t s1_degrees = 0;
    uint16_t s2_degrees = 0;

    int result = calc_positions(len1,len2,x,y,s1_degrees,s2_degrees);
    if (result == 0){
        servo1_degrees = (s1_degrees -servo1_Offset);
            servo1.setServo(servo1_degrees);
            if (s2_degrees > 0){
                servo2_degrees = (90-s2_degrees);
                servo2.setServo(servo2_degrees);
            }
            else if (s2_degrees < 0){
                servo2_degrees  = 90+ s2_degrees;
                servo2.setServo(servo2_degrees);
            }
            x_pos = x;
            y_pos = y;
    }
}

int Arm::getX(){
    return x_pos;
}

int Arm::getY(){
    return y_pos;
}

void Arm::setOffsetServo1(uint16_t &degrees){
    servo1_Offset = degrees;
}

void Arm::setOffsetServo2(uint16_t &degrees){
    servo2_Offset = degrees;
}

int Arm::getServo1Degrees(){
    return servo1_degrees;
}

int Arm::getServo2Degrees(){
    return servo2_degrees;
}