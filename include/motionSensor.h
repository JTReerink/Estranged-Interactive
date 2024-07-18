// if not defined, run code below
#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include <stdint.h>

enum MotionState {
    nothing,
    activated,
    deactivated,
    active
};

class MotionSensor
{
private:
    int pin;
    MotionState state = nothing;

public:
    MotionSensor(int pin);
    MotionState checkState();
};

#endif