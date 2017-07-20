#include "advancedservoarm.hpp"

advancedservoarm::advancedservoarm(int &len1, int &len2, Servo &servo1, Servo &servo2, int servo1_offset, int servo2_offset):
    servoarm(len1,len2,servo1,servo2),servo1_offset(servo1_offset),servo2_offset(servo2_offset){};

void advancedservoarm::set_joint1(const uint16_t &degrees){
    servo1.setServo(degrees-servo1_offset);
}
void advancedservoarm::set_joint2(const uint16_t &degrees){
    servo2.setServo(degrees-servo2_offset);
}

void advancedservoarm::set_offset_servo1(uint16_t &degrees){
    servo1_offset = degrees;
}

void advancedservoarm::set_offset_servo2(uint16_t &degrees){
    servo2_offset = degrees;
}