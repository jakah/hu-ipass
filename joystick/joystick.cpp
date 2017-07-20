#include "joystick.hpp"

joystick::joystick(hwlib::adc & pin_x, hwlib::adc & pin_y):pin_x(pin_x),pin_y(pin_y){};
bool joystick::up(){
    if (pin_y.get() < 2000){
            return true;
    }
    else{
        return false;
    }
}
bool joystick::down(){
    if (pin_y.get() > 3900){
        return true;
    }
    else{
        return false;
    }
}
bool joystick::left(){
    if (pin_x.get() < 2000){
        return true;
    }
    else{
        return false;
    }
}
bool joystick::right(){
    if(pin_x.get() > 3700){
        return true;
    }
    else{
        return false;
    }
}