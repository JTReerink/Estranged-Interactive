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
        if(value != 1) break;

        // Nu gaan we aan
        this->state = activated;
        break;

    case active:
        if(value != 0) break;

        this->state = deactivated;
        break;

    case activated:
        if(value == 0) {
            this->state = deactivated;
        } else {
            this->state = active;
        }
        break;

    case deactivated:
        if(value == 1)
        {
            this->state = activated;
        } else {
            this->state = nothing;
        }
        
        break;
    
    default:
        break;
    }

    return this->state;
}