/*
 * Made by Jaap Reerink
 */

// if not defined, run code below
#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <Adafruit_NeoPixel.h>
#include <stdint.h>

// animaties
enum Animation
{
    none,
    walkin,
    walkout,
    idleOn
};

// define variables en functies
class Ledstrip
{
private:
    Adafruit_NeoPixel strip;
    uint8_t r, g, b, pin, leds, startLed;

    Animation currentAnimation = Animation::none;

    unsigned long delayEnd = 0;

    /* Variables for the animation functions */
    uint8_t currentLed = 0;
    bool ledOn = false;
    uint8_t currentLoop = 0;

    void WalkIn();
    void WalkOut();
    void IdleOn();

    // functies te gebruiken in de main file
public:
    Ledstrip(uint8_t pin, uint8_t leds, uint8_t startLed);

    // void init();

    void setAnimation(Animation animation);
    void setColour(uint8_t r, uint8_t g, uint8_t b);

    void delay(unsigned long delay);

    void loop();
};

#endif