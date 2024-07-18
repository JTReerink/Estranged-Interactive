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

Adafruit_NeoPixel strip { NUM_LEDS, NEO_PIN, NEO_GRB + NEO_KHZ800 };

MotionSensor motionSensors[SENSORS] = {
    MotionSensor(4),
    MotionSensor(15)
};

// evenveel strips als sensors? JA
Ledstrip strips[SENSORS] = {
    Ledstrip(strip, 0, 14),//why 14?
    Ledstrip(strip, 15, 14)
};
 
void setup()
{    
    strip.setBrightness(255);
    strip.begin();
    strip.clear();

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
        case activated:
            Serial.println("Activated!");
            strips[i].setOn(true);
            if(i > 0) strips[i - 1].setOn(false);
            
        case deactivated:
            Serial.println("Deactivated");
        
        case active:
        case nothing:
        default:
            break;
        }
    }

    for (int i = 0; i < SENSORS; i++) strips[i].loop();

    strip.show();
    yield();
}