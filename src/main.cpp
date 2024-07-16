// include libraries
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ledstrip.h>
#include <motionSensor.h>

/*number of leds on strip*/
#define NUM_LEDS 30
/*pin for data*/
#define NEO_PIN 14
bool sensorState[2];
int pins[2] {4, 15};

int sensorStateLength = sizeof(sensorState) / sizeof(sensorState[0]);

// ledstrip aanmaken
Ledstrip strip { NEO_PIN, NUM_LEDS, 0 };

MotionSensor sensor[2];

// Ledstrip strip2 { NEO_PIN, NUM_LEDS, 13 };

void setup()
{
    //Set all sensor pins to inputs
    for (int i = 0; i < sensorStateLength; i++)
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
    Serial.println(sensorStateLength);

    //read all motionsensorState
    for (int i = 0; i < sensorStateLength; i++) {
        sensor[i].CheckMotions(i, pins[i], sensorState[i]);
        delay(500);
    }

    // strip.loop(sensorState, sensorStateLength);
    yield();

}