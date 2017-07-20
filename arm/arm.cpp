#include "arm.hpp"
#include "../servo/servo.hpp"
#include "calculations.hpp"
#include "coordinate.hpp"
arm::arm(int &len1, int &len2):
    len1(len1),len2(len2){
        x_pos = 0;
        y_pos = 0;
        coordinate position(0,0);
    };
void arm::set_position(coordinate &position){
    int result = calc_positions(len1,len2,position,joint1_degrees,joint2_degrees);
    if (result == 0){
        set_joint1(joint1_degrees);
        if (joint2_degrees > 0){
            set_joint2(90 - joint2_degrees);
        }
        else if (joint2_degrees < 0){
            set_joint2(90 + joint2_degrees);
        }
        x_pos = position.get_x();
        y_pos = position.get_y();
        position = position;
    }
}

int arm::get_X(){
    return x_pos;
}

int arm::get_Y(){
    return y_pos;
}

coordinate arm::get_position(){
    return position;
}
uint16_t arm::get_joint1_degrees(){
    return joint1_degrees;
}
uint16_t arm::get_joint2_degrees(){
    return joint2_degrees;
}