// include libraries
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ledstrip.h>
#include <motionSensor.h>

/*number of leds on strip*/
#define NUM_LEDS 30
/*pin for data*/
#define NEO_PIN 14
/* amount of motion sensors inproject */
#define SENSORS 2
/* amount of ledstrip parts in project */
#define STRIPS 2


Adafruit_NeoPixel strip { NUM_LEDS, NEO_PIN, NEO_GRB + NEO_KHZ800 };

/* define each pin for each motion sensor */
MotionSensor motionSensors[SENSORS] = {
    MotionSensor(4),
    MotionSensor(15)
};

/* all the states of the motion sensors */
bool motionStates[SENSORS];

/* define START and END LED number */
Ledstrip strips[STRIPS] = {
    Ledstrip(strip, 0, 14),
    Ledstrip(strip, 15, 14)
};



void setup()
{    
    /* setup for neopixel */
    strip.begin();
    strip.setBrightness(255);
    strip.clear();

    // open Serial monitor voor debugging
    Serial.begin(115200);
    Serial.println("first print");

}

void loop()
{

    //read all motionsensorState
    for (int i = 0; i < SENSORS; i++) {

        /* set state of current motion sensor */
        MotionState state = motionSensors[i].checkState();

        // Serial.println((String) "Sensor " + i + ": ");

        switch (state)
        {
        case activated:
            Serial.println((String)"Activated! " + i);
            /* set state in array to true */
            /* turn on corresponding LEDstrip part */
            /* TODO: Make this so it does it after 6 seconds and also only if the next 2 sensors are inactive */
            strips[i].setOn(true);
            /* TODO: turn on corresponding spotlight (corresponding relais pin) */            

            
        case deactivated:
            motionStates[i] = false;
            Serial.println((String)"Deactivated " + i);
        
        case active:
            motionStates[i] = true;
            Serial.println((String)"Active " + i);
            /* If current sensor is active and previous is not, disable previous LEDstrip part */
            if(!motionStates[i-1]) Serial.println(motionStates[i]);

        case nothing:
            Serial.println((String)"Idle " + i);
        default:
            break;
        }
    }

    /* run the LOOP of each ledsrip part */
    for (int i = 0; i < SENSORS; i++) strips[i].loop();

    strip.show();
    yield();
}