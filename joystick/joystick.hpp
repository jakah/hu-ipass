#include "hwlib.hpp"
#ifndef JOYSTICK_HPP
#define JOYSTICK_HPP
/// \file
/// \class joystick
/// \brief
/// the joystick class
/// \details
/// This class is an abstracion for a joystick. Two analog pins go in and you can call 
/// functions to check if the joystick is at a certain position
class joystick{
private:
    int position;
    hwlib::adc & pin_x;
    hwlib::adc & pin_y;

public:
    /// \brief
    /// constructor for joystick class
    /// \details
    /// Constructs a joystick object using the two anolog pins of the potentiometers.
    /// \param[in] hwlib::adc & pin_x , the pin that gives the anolog value for the x potentiometer
    /// \param[in] hwlib::adc & pin_y , the pin that gives the anolog value for the y potentiometer
    joystick(hwlib::adc & pin_x, hwlib::adc & pin_y);
    /// \brief
    /// check if the joystick is up
    /// \details
    /// This function checks if the joystick is in the up position.
    /// \result true if in the up position, false if not in the up position
    bool up();
    /// \brief
    /// check if the joystick is down
    /// \details
    /// This function checks if the joystick is in the down position.
    /// \result true if in the down position, false if not in the down position
    bool down();
    /// \brief
    /// check if the joystick is left
    /// \details
    /// This function checks if the joystick is in the left position.
    /// \result true if in the left position, false if not in the left position
    bool left();
    /// \brief
    /// check if the joystick is right
    /// \details
    /// This function checks if the joystick is in the right position.
    /// \result true if in the right position, false if not in the right position
    bool right();
};
#endif