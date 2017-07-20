#include "servoarm.hpp"

servoarm::servoarm(int &len1, int &len2, Servo &servo1, Servo &servo2):
        arm(len1,len2),servo1(servo1),servo2(servo2){};

void servoarm::set_joint1(const uint16_t &degrees){
    servo1.setServo(degrees);
}

void servoarm::set_joint2(const uint16_t &degrees){
    servo2.setServo(degrees);
}
