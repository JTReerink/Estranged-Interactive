/*
 * Made by Jaap Reerink
 */

#include <ledstrip.h>

//initialize ledstrip
Ledstrip::Ledstrip(uint8_t pin, uint8_t leds, uint8_t startLed)
{
    // Serial.begin(115200);
    this->strip = Adafruit_NeoPixel(leds, pin, NEO_GRB + NEO_KHZ800);

    this->startLed = startLed;


    this->strip.setBrightness(255);
    this->strip.begin();


    this->r = 255;
    this->g = 255;
    this->b = 255;

    this->leds = leds;
    this->pin = pin;

    this->strip.clear();
    // this->strip.show();  WERKT NIET


}

void Ledstrip::Init() 
{
    for(int i = 0; i < leds; i++) {
        this->strip.setPixelColor(i,0,0,0);
        this->strip.show();
    }
}

void Ledstrip::delay(unsigned long delay)
{
    this->delayEnd = millis() + delay;
}

void Ledstrip::loop(bool allSensors[], int allSensorsLength)
{
    //hier moet gecheckt worden welke sensoren er aan staan
    for (int i = 0; i < allSensorsLength; i++)
    {
        if(allSensors[i] = 1) {
            Serial.println((String)"ledstip stuk: " + i);
        } else return;
    };
    

    this->strip.show();
}


void Ledstrip::WalkIn()
{
    //hier moeten de ledjes aangezet worden, kleur wordt ergens anders bepaald
    this->delay(100);
}

void Ledstrip::Rainbow()
{
    // regenboog animatie
}