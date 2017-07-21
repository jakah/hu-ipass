#include "servo.hpp"
Servo::Servo(hwlib::pin_out &pin):
    pin(pin){};

void Servo::setServo(const int &degrees){
    // servo is physically limited to 180 degrees   
    if (degrees <= 180 && degrees >= 0){
        // values between 500 and 2250
        int pulse_time = 500 + ((degrees-15) * 10);
        if (pulse_time >= 500 && pulse_time <= 2500){
            for (int i = 0; i < 10; i++){
                pin.set(1);
                hwlib::wait_us(pulse_time);
                pin.set(0);
                hwlib::wait_us(20000 - pulse_time);
            }
        }
    }
};