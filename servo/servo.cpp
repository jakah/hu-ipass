#include "servo.hpp"
Servo::Servo(hwlib::pin_out &pin):
    pin(pin),pulse_time(0),updateCalls(0){};

void Servo::setServo(const int &degrees){
    // servo is physically limited to 180 degrees   
    if (degrees <= 180 && degrees >= 0){
        // values between 500 and 2250
        pulse_time = 500 + ((degrees-15) * 10);
        if (pulse_time >= 500 && pulse_time <= 2500){
            for (int i = 0; i < 200; i++){
                updateServo();
                hwlib::wait_ms(1);
            }
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