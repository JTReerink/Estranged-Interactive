#include <Arduino.h>
#include <motionSensor.h>

MotionSensor::MotionSensor(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

MotionState MotionSensor::checkState()
{
    int value = digitalRead(this->pin);

    switch (this->state)
    {
    case nothing:
        if(value != 1) return;

        // Nu gaan we aan
        this->state = activate;
        break;

    case activate:
        if(value != 0) return;

        this->state = deactivated;
        break;

    case deactivated:
        if(value == 1)
        {
            this->state = activate;
        } else {
            this->state = nothing;
        }
        
        break;
    
    default:
        break;
    }

    return this->state;
}