#include "hwlib.hpp"
#ifndef SERVO_HPP
#define SERVO_HPP
/// \file

/// \brief
/// this is a control class for servo motors that use PWM.
/// \details
/// This class controls servos that use pwm. 
/// You can manipulate the pulse duration.
/// Every millisecond you  must call the updateServo function, it
/// will send a new pulse to the servo if needed.
class Servo {
private:
    hwlib::pin_out & pin;
public:
    /// \brief
    /// Create a servo object
    /// \param[in] hwlib::pin_out pin, reference to the pin the servo's PWM pin is connected to
    Servo(hwlib::pin_out &pin);
    /// \brief 
    /// Set the position of the servo
    /// \param[in] int position, give the position in degrees, 0 is the most left 
    /// position ,180 is the most right position
    void setServo(const int &position);
};

#endif