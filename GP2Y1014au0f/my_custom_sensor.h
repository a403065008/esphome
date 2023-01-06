#include "esphome.h"


class MyCustomSensor : public PollingComponent, public Sensor
{
public:
    // constructor

    MyCustomSensor() : PollingComponent(15000) {}
    Sensor *result = new Sensor();
    float get_setup_priority() const override { return esphome::setup_priority::AFTER_WIFI; }
    int dustPin = 0;
    float dustVal = 0;
    int ledPower = D2;
    int delayTime = 280;
    int delayTime2 = 40;
    float offTime = 9680;
    


    void setup() override
    {

        pinMode(ledPower, OUTPUT);
        pinMode(dustPin, INPUT);
        // This will be called by App.setup()
    }
    void update() override
    {
        // This will be called every "update_interval" milliseconds.
        digitalWrite(ledPower, LOW);
        delayMicroseconds(delayTime);
        dustVal = analogRead(dustPin);
        delayMicroseconds(delayTime2);
        digitalWrite(ledPower, HIGH);
        delayMicroseconds(offTime);

        result->publish_state(double(dustVal*(5.0/1024)-0.12)*100/0.5);

        
}
}

;
