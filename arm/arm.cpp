#include "arm.hpp"
#include "../servo/servo.hpp"
#include "calculations.hpp"

Arm::Arm(const int &len1, const int &len2, Servo &servo1, Servo &servo2, int servo1_Offset, int servo2_Offset):
    len1(len1),len2(len2),servo1(servo1),servo2(servo2),servo1_Offset(servo1_Offset),servo2_Offset(servo2_Offset){
        x_pos = 0;
        y_pos = 0;
    };

void Arm::setPos(const int &x , const int &y){
    int error = 0;
    float s2 = calc_servo2(len1,len2,x,y,error);
    if (error == 0){
        servo1_degrees = radianstodegrees(calc_servo1(len1,len2,x,y,s2));
        servo2_degrees = radianstodegrees(s2);
        if (servo1_degrees < 180){
            servo1.setServo(180-servo1_degrees);
        }
        if (servo2_degrees > 90){
            servo2.setServo(180 - (servo2_degrees-90));
        }

        x_pos = x;
        y_pos = y;
    }
}

void Arm::updateServos(){
    servo1.updateServo();
    servo2.updateServo();
}

int Arm::getX(){
    return x_pos;
}

int Arm::getY(){
    return x_pos;
}

void Arm::setOffsetServo1(const int &degrees){
    servo1_Offset = degrees;
}

void Arm::setOffsetServo2(const int &degrees){
    servo2_Offset = degrees;
}

int Arm::getServo1Degrees(){
    return servo1_degrees;
}

int Arm::getServo2Degrees(){
    return servo2_degrees;
}