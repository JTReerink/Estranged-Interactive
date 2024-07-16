// include libraries
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ledstrip.h>
#include <motionSensor.h>

/*number of leds on strip*/
#define NUM_LEDS 30
/*pin for data*/
#define NEO_PIN 14

#define SENSORS 2

// //een array van elke state van elke sensor
// bool sensorState[2];
// //een array met alle elke gebruikte NodeMCU pins
// int sensorPins[2] {4, 15};
// //de lengte van de array met alle states
// int sensorStateLength = sizeof(sensorState) / sizeof(sensorState[0]);

// ledstrip aanmaken
Ledstrip strip { NEO_PIN, NUM_LEDS};

MotionSensor motionSensors[SENSORS] = {
    MotionSensor(4),
    MotionSensor(15)
};

// Ledstrip strip2 { NEO_PIN, NUM_LEDS, 13 };

void setup()
{    
    strip.Init();

    // open Serial monitor voor debugging
    Serial.begin(115200);
    Serial.println("first print");

}

void loop()
{

    //read all motionsensorState
    for (int i = 0; i < SENSORS; i++) {

        MotionState state = motionSensors[i].checkState();

        Serial.println((String) "Sensor " + i + ": ");

        switch (state)
        {
        case activate:
            Serial.println("Currently active!");
            
        case deactivated:
            Serial.println("Deactivated");
        
        case nothing:
        default:
            break;
        }
        // delay(500);
    }

    strip.loop();
    yield();

}