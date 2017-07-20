#ifndef ARM_HPP
#define ARM_HPP
#include "stdint.h"
#include "hwlib.hpp"
#include "../servo/servo.hpp"
/// \file
/// \class Arm
/// \brief
/// the robotarm class
/// \details
/// This class handles all math that is need to move the robotarm to a given coordinate. 
class arm{
private:
    int x_pos;
    int y_pos;
    int &len1;
    int &len2;
    uint16_t joint1_degrees;
    uint16_t joint2_degrees;
protected:
    virtual void set_joint1(const uint16_t &degrees) = 0;
    virtual void set_joint2(const uint16_t &degrees) = 0;
public:
    /// \brief
    /// constructor for the robotarm
    /// \param[in] int len1, length of the first arm
    /// \param[in] int len2, length of the second arm
    /// \param[in] Servo servo1, servo object of the first servo
    /// \param[in] Servo servo2, servo object of the second servo
    arm(int &len1, int &len2);
    /// \brief
    /// set the position of the robotarm
    /// \param[in] int x, the desired x position
    /// \param[in] int y, the desired y position
    void set_position(int &x,int &y);
    /// \brief
    /// the x position of the robotarm
    /// \result int x, x position of the robotarm
    int get_X();
    /// \brief
    /// the y position of the robotarm
    /// \result int y, y position of the robotarm
    int get_Y();
    /// \brief
    /// return the value that joint2 should be
    /// \result int degrees, value of joint2
    uint16_t get_joint1_degrees();
    uint16_t get_joint2_degrees();

};
#endif
