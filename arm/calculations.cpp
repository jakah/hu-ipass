#include "math.h"
#include "calculations.hpp"
#include "coordinate.hpp"
/// \file
/// calculations arm based on this document <a href="http:://www.hessmer.org/uploads/RobotArm/Inverse%2520Kinematics%2520for%2520Robot%2520Arm.pdf"> www.hessmer.org/uploads/RobotArm/Inverse%2520Kinematics%2520for%2520Robot%2520Arm.pdf</a>
int calc_positions(int &len1,int &len2,coordinate &position,uint16_t &servo1, uint16_t &servo2){
    int x = position.get_x();
    int y = position.get_y();
    float pre_servo2 = atan2(sqrt(1-((pow(x,2)+pow(y,2) - pow(len1,2) - pow(len2,2))/(2*len1*len2))), ((pow(x,2) + pow(y,2) + pow(len1,2) + pow(len2,2))/(2*len1*len2)));
    float k1 = len1+(len2*cos(pre_servo2));
    float k2 = len2*sin(pre_servo2);
    float pre_servo1 = atan2(y,x) + atan2(k2,k1);
     // 90 degrees in radians 
    if (pre_servo1  > 1.57079633 || pre_servo1 < 0){
        pre_servo2 = atan2(-sqrt(1-((pow(x,2)+pow(y,2) - pow(len1,2) - pow(len2,2))/(2*len1*len2))), ((pow(x,2) + pow(y,2) + pow(len1,2) + pow(len2,2))/(2*len1*len2)));
        float k1 = len1+(len2*cos(pre_servo2));
        float k2 = len2*sin(pre_servo2);
        pre_servo1 = atan2(y,x) + atan2(k2,k1);
        servo1 = (pre_servo1 * 180)/3.14;
        servo2 = (pre_servo2 * 180)/3.14;
    }
    else {
        servo1 = (pre_servo1 * 180)/3.14;
        servo2 = (pre_servo2 * 180)/3.14;
    }
    return 0;
}
