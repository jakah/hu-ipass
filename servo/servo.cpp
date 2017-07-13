#include "servo.hpp"
Servo::Servo(hwlib::pin_out &pin):
    pin(pin),pulse_time(0),updateCalls(0){};

void Servo::setServo(const int &degrees){
    // servo is physically limited to 180 degrees   
    if (degrees <= 180 && degrees >= 0){
        // values between 500 and 2250
        pulse_time = 500 + (degrees * 10);
        if (pulse_time >= 1000 && pulse_time <= 2000){
            updateCalls = 200;
        }
    }
};

void Servo::updateServo(){
    if (updateCalls >= 20){
            pin.set(1);
            hwlib::wait_us(pulse_time);
            pin.set(0);
            updateCalls = 0;
        
    }
    else{
        updateCalls++;
    }
};
