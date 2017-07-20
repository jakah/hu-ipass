#include "arm.hpp"
/// \file
/// \class servoarm
/// \brief
/// \a arm with servomotors
class servoarm : public arm{
protected:
    Servo &servo1;
    Servo &servo2;
    int servo1_degrees;
    int servo2_degrees;
public:   
    servoarm(int &len1, int &len2, Servo &servo1, Servo &servo2);
    void set_joint1(const uint16_t &degrees);
    void set_joint2(const uint16_t &degrees);
};