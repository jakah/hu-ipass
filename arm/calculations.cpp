#include "math.h"
#include "calculations.hpp"

/// \brief
/// convert angle in radians to angle in degrees
/// \param[in] float radians
/// \return int angle in degrees
int radianstodegrees(float &radians){
    return ((radians * 180)/3.14);
};

uint8_t radianstodegrees(uint16_t &radians){
    return ((radians * 180)/3.14);
};
int calc_positions(int &len1,int &len2,int &x, int &y,float &servo1, float &servo2){
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
        servo1 = pre_servo1;
        servo2 = pre_servo2;
    }
    else {
        servo1 = pre_servo1;
        servo2 = pre_servo2;
    }
    return 0;
}
