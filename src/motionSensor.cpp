#include <Arduino.h>
#include <motionSensor.h>

MotionSensor::MotionSensor()
{
    this-> val = 0;
    this-> state = LOW;
}

bool MotionSensor::CheckMotions(int sensorNum, uint8_t sensorPin, bool allSensors)
{
    this->val = digitalRead(sensorPin);
    Serial.println(this->state);
    if (this->val == 1)
    {
        if (this->state == 0)
        {
            Serial.println((String)"Motion at pin: " + sensorNum + " detected");
            allSensors = true;
            this->state = HIGH;
            return allSensors;
        } else return allSensors;
    }
    else
    {
        Serial.println(this->state);

        if (this->state == 1)
        {
            Serial.println((String)"The motion has stopped at: " + sensorNum);
            allSensors = 0;
            this->state = LOW;
            return allSensors;
        } else return allSensors;
    }
}