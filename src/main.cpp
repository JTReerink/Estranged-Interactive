// include libraries
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ledstrip.h>
#include <motionSensor.h>

/*number of leds on strip*/
#define NUM_LEDS 30
/*pin for data*/
#define NEO_PIN 14
bool allSensors[2];
int pins[2] {4, 15};

int allSensorsLength = sizeof(allSensors) / sizeof(allSensors[0]);

// ledstrip aanmaken
Ledstrip strip { NEO_PIN, NUM_LEDS, 0 };

MotionSensor sensor;
// Ledstrip strip2 { NEO_PIN, NUM_LEDS, 13 };

void setup()
{
    //Set all sensor pins to inputs
    for (int i = 0; i < allSensorsLength; i++)
    {
        pinMode(pins[i], INPUT);
    }
    
    strip.Init();

    // open Serial monitor voor debugging
    Serial.begin(115200);
    Serial.println("first print");

}

void loop()
{
    Serial.println(allSensorsLength);

    //read all motionallSensors
    for (int i = 0; i < allSensorsLength; i++) {
        sensor.CheckMotions(i, pins[i], allSensors[i]);
        delay(50);
    }

    // strip.loop(allSensors, allSensorsLength);
    yield();

}
