#include "configuration.h"

namespace Kiral
{
    namespace Chuli 
    {
        Configuration::Configuration() : 
            pin_out_audio(25),
            pin_in_switch(32),
            timer_0(0),
            speech_speed(1)
        { 

        }

        Configuration::~Configuration()
        {

        }


        ConfigurationBuilder::ConfigurationBuilder()
        {
        }
        
        ConfigurationBuilder::~ConfigurationBuilder()
        {
        }

        ConfigurationBuilder* ConfigurationBuilder::SetPinOuAudio(const unsigned int pin) 
        {
            this->conf.pin_out_audio = pin;
            return this;
        }

        ConfigurationBuilder* ConfigurationBuilder::SetPinInSwitch(const unsigned int pin) 
        {
            this->conf.pin_in_switch = pin;
            return this;
        }

        ConfigurationBuilder* ConfigurationBuilder::SetTimer(const unsigned int timer) 
        { 
            this->conf.timer_0 = timer; 
            return this;
        }

        ConfigurationBuilder* ConfigurationBuilder::SetSpeechSpeed(const float speed)
        { 
            this->conf.speech_speed = speed; 
            return this;
        }

        Configuration ConfigurationBuilder::Build() const 
        { 
            return this->conf; 
        }
    }
}
