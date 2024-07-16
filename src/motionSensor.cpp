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
    if (this->val == HIGH)
    {
        if (this->state == LOW)
        {
            Serial.println((String)"Motion at pin: " + sensorNum + " detected");
            allSensors = true;
            this->state = HIGH;
            return allSensors;
        }
    }
    else
    {
        if (state == HIGH)
        {
            Serial.println((String)"The motion has stopped at: " + sensorNum);
            sensorNum = 0;
            this->state = LOW;
        }
    }
}