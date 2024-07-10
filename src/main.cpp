// include libraries
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ledstrip.h>

/*number of leds on strip*/
#define NUM_LEDS 14
/*pin for data*/
#define NEO_PIN 14

#define sensor 4
#define sensor2 15
int state1 = LOW;  
int state2 = LOW;  
int val1 = 0;
int val2 = 0;


// ledstrip aanmaken
Ledstrip strip { NEO_PIN, NUM_LEDS, 0 };
// Ledstrip strip2 { NEO_PIN, NUM_LEDS, 13 };

void setup()
{
    pinMode(sensor, INPUT);
    pinMode(sensor2, INPUT);

    // open Serial monitor voor debugging
    Serial.begin(115200);
    Serial.println("first print");

}

void loop()
{
    val1 = digitalRead(sensor);
    if (val1 == HIGH)
    {
        if (state1 == LOW)
        {
            Serial.println(" Motion detected");
            state1 = HIGH;
            strip.setAnimation(walkin);
        }
    }
    else
    {
        if (state1 == HIGH)
        {
            Serial.println("The action/ motion has stopped");
            state1 = LOW;
            strip.setAnimation(walkout);
        }
    }
    val2 = digitalRead(sensor2);
    if (val2 == HIGH)
    {
        if (state2 == LOW)
        {
            Serial.println("2nd Motion detected");
            state2 = HIGH;
        }
    }
    else
    {
        if (state2 == HIGH)
        {
            Serial.println("2nd The action/ motion has stopped");
            state2 = LOW;
        }
    }

    strip.loop();
    yield();

}
