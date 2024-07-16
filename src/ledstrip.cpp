/*
 * Made by Jaap Reerink
 */

#include <ledstrip.h>

//initialize ledstrip
Ledstrip::Ledstrip(uint8_t pin, uint8_t leds, uint8_t startLed)
{
    Serial.begin(115200);
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

void Ledstrip::loop()
{
    if (this->currentAnimation == none)
        return;

    if (millis() < this->delayEnd)
        return;

    switch (this->currentAnimation)
    {
    case walkin:
        this->WalkIn();
        break;

    case walkout:
        this->WalkOut();
        break;

    default:
        return;
    }

    this->strip.show();
}

void Ledstrip::setAnimation(Animation animation)
{
    this->currentAnimation = animation;

    // Resetting the animation variables
    this->currentLed = this->startLed;
    this->ledOn = false;
    this->currentLoop = 0;

    this->delayEnd = 0;

    this->strip.clear();
    this->strip.show();
}

void Ledstrip::setColour(uint8_t r, uint8_t g, uint8_t b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void Ledstrip::WalkIn()
{
    if(this->currentLed < this->leds) {
        this->strip.setPixelColor(this->currentLed,this->r, this->g, this->b);
        this->currentLed++;
    } else {
        this->setAnimation(none);
        this->currentLed = 0;
    }
    this->delay(100);
}

void Ledstrip::WalkOut()
{
    if(this->currentLed < this->leds) {
        this->strip.setPixelColor(this->currentLed,0, 0, 0);
        this->currentLed++;
    } else {
        this->setAnimation(none);
        this->currentLed = 0;
    }
    this->delay(100);
}

void Ledstrip::IdleOn()
{
    // regenboog animatie
}