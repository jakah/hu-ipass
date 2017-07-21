#include "testarm.hpp"

testarm::testarm(int &len1, int &len2, int &servo1, int &servo2):
        arm(len1,len2),servo1(servo1),servo2(servo2){};

void testarm::set_joint1(const uint16_t &degrees){
    ;
}

void testarm::set_joint2(const uint16_t &degrees){
    ;
}
