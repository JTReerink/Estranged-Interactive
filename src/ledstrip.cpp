/*
 * Made by Jaap Reerink
 */

#include <ledstrip.h>

//initialize ledstrip
Ledstrip::Ledstrip(Adafruit_NeoPixel& strip, uint8_t startLed, uint8_t leds)
{
    this->strip = strip;
    this->startLed = startLed;

    this->leds = leds;
}

void Ledstrip::delay(unsigned long delay)
{
    this->delayEnd = millis() + delay;
}

void Ledstrip::setOn(bool isOn) {
    this->isOn = isOn;

    this->currentLed = this->startLed;
}

void Ledstrip::loop()
{
    if(this->delayEnd > millis()) return;
    if(this->currentLed > this->startLed + this->leds) return;

    if(this->isOn) {
        this->strip.setPixelColor(this->currentLed, strip.Color(255, 0, 0));
    } else {
        this->strip.setPixelColor(this->currentLed, strip.Color(0, 0, 0));
    }

    this->currentLed++;
    this->delay(500);
}