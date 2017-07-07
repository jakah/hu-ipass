#ifndef ARM_HPP
#define ARM_HPP
#include "hwlib.hpp"
#include "../servo/servo.hpp"
/// \file

class Arm{
private:
    int x_pos;
    int y_pos;
    int len1;
    int len2;
    Servo servo1;
    Servo servo2;
    int servo1_Offset;
    int servo2_Offset;
    int servo1_degrees;
    int servo2_degrees;
public:
    /// \brief
    /// constructor for the robotarm
    /// \param[in] int len1, length of the first arm
    /// \param[in] int len2, length of the second arm
    /// \param[in] Servo servo1, servo object of the first servo
    /// \param[in] Servo servo2, servo object of the second servo
    Arm(const int &len1, const int &len2,Servo &servo1, Servo &servo2, int servo1_Offset, int servo2_Offset);
    /// \brief
    /// set the position of the robotarm
    /// \param[in] int x, the desired x position
    /// \param[in] int y, the desired y position
    void setPos(const int &x,const int &y);
    /// \brief
    /// give a update call to all the servo's in the robotarm
    /// \details
    /// The servo's need a updated every 20ms to remain in the desired position. 
    /// This function needs a call every millisecond, it passes these to the 
    /// servos who keep track of the time passed since the last pulse was send. 
    void updateServos();
    /// \brief
    /// set the position of y in 
    /// \details
    /// Give the amount of degrees that need to be added to position the servo to the Y-axis
    void setOffsetServo1(const int &degrees);
    /// \brief
    /// set the offset for servo 2
    /// \details 
    /// Give the amount of degrees that need to be added to the second servo so it is 
    void setOffsetServo2(const int &degrees);
    /// \brief
    /// the x position of the robotarm
    /// \result int x, x position of the robotarm
    int getX();
    /// \brief
    /// the y position of the robotarm
    /// \result int y, y position of the robotarm
    int getY();
    int getServo1Degrees();
    int getServo2Degrees();
};
#endif
