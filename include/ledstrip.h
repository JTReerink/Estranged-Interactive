/*
 * Made by Jaap Reerink
 */

// if not defined, run code below
#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <Adafruit_NeoPixel.h>
#include <stdint.h>

// define variables en functies
class Ledstrip
{
private:
    Adafruit_NeoPixel strip;
    uint8_t leds, startLed, currentLed;

    bool isOn = false;

    unsigned long delayEnd = 0;

    void delay(unsigned long delay);

    void walkin();
    void walkout();

    // functies te gebruiken in de main file
public:
    Ledstrip(Adafruit_NeoPixel& strip, uint8_t startLed, uint8_t leds);


    void loop();
    void setOn(bool isOn);
    bool checkLed();
};

#endif