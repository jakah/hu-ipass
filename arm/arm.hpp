#ifndef ARM_HPP
#define ARM_HPP
#include "stdint.h"
#include "coordinate.hpp"
/// \file
/// \class arm
/// \brief
/// the robotarm class
/// \details
/// This class handles all math that is need to move the robotarm to a given coordinate. 
/// It also funcions as a base class for all types of arm
class arm{
private:
    coordinate position;
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
    arm(int &len1, int &len2);
    /// \brief
    /// set the position of the robotarm
    /// \param[in] coordinate position, the desired position of the arm
    int set_position(coordinate &position);
    /// \brief
    /// the position of the robotarm in a coordinate
    /// \result coordinate position the position of the arm
    coordinate get_position();
    /// \brief
    /// the x position of the robotarm
    /// \result int x, x position of the robotarm
    int get_X();
    /// \brief
    /// the y position of the robotarm
    /// \result int y, y position of the robotarm
    int get_Y();
    /// \brief
    /// return the value that joint1 should be
    /// \result uint16_t degrees, value of joint1
    uint16_t get_joint1_degrees();
    /// \brief
    /// return the value that joint2 should be
    /// \result uint16_t degrees, value of joint2
    uint16_t get_joint2_degrees();

};
#endif
