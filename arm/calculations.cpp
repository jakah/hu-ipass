#include "math.h"
/// \file
/// Most calculations in this file are based of an example that can be found at the following URL:
/// https://wiki.qut.edu.au/download/attachments/104094381/Problem+Set+2+conf.pdf

/// \brief
/// calculate the value that servo2 should be
/// \details
/// \param[in] int len1, length of the first arm
/// \param[in] int len2, length of the second arm
/// \param[in] int x, value of x that the arm should move to
/// \param[in] int y, value of y that the arm should move to
/// \param[out] int error, value will be set to 1 if a value is outside fo the domain
/// \result value that servo2 should be in radians
float calc_servo2(const int &len1, const int &len2 ,const int &x ,const int &y,int &error){
    float d = (((pow(len1,2) + pow(len2,2)) - pow(x,2) + pow(y,2)) / (2*len1*len2));
    if (d > 1){
        // if d > 1 no value can be calculated
        error = 1;
        return 0;
    }
    else{
        float result = atan2(d,-sqrt(1-pow(d,2)));
        if (result == result){
            if (x >= 0){
                return (3.14 - result);
            }
            else if (x <0){
                return (result);
            }
            else{
                return result;
            }
        }
        else{
            error = 1;
            return 0;
        }
    }
};

/// \brief 
/// calculate the value that servo1 should be
/// \details
/// \param[in] int len1, length of the first arm
/// \param[in] int len2, length of the second arm
/// \param[in] int x, value of x that the arm should move to
/// \param[in] int y, value of y that the arm should move to
/// \param[in] float servo2, the value of servo2, it is needed to determine the position of servo1 
/// \result value that servo1 should be in radians
float calc_servo1(const int &len1,const int &len2,const int &x,const int &y,const float &servo2){
    float result = atan2(x,y) - atan2(len1+(len2*cos(servo2)), (len2*sin(servo2)));
    if (x >= 0){
        return (3.14 - result);
    }
    else if (x <0){
        return (result+3.14);
    }
    else{
        return result;
    }
};

/// \brief
/// convert angle in radians to angle in degrees
/// \param[in] float radians
/// \return int angle in degrees
int radianstodegrees(const float &radians){
    return ((radians * 180)/3.14);
};