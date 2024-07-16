// if not defined, run code below
#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include <stdint.h>

class MotionSensor
{
private:
    int sensor;
    uint8_t val, state, sensorNum, sensorPin;

public:
    MotionSensor();
    bool sensors[9];
    int sensorsLength = sizeof(sensors) / sizeof(int);

    bool CheckMotions(int sensorNum, uint8_t sensorPin, bool allSensors);
};

#endif