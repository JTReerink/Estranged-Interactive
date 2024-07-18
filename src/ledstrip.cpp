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
        uint16_t hue = 0 + ((currentLed-startLed) * 1 * 65536) / leds;
        uint32_t color = strip.ColorHSV(hue);
        this->strip.setPixelColor(this->currentLed, color);
    } else {
        this->strip.setPixelColor(this->currentLed, strip.Color(0, 0, 0));
    }

    this->currentLed++;
    this->delay(200);
}

bool Ledstrip::checkLed() {
    if(this->strip.getPixelColor(1)||this->strip.getPixelColor(2)||this->strip.getPixelColor(3) == 255) {
        return true;
    } else return false;
}