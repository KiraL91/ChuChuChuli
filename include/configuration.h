#pragma once

namespace Kiral
{
    namespace Chuli 
    {
        class Configuration
        {
        public:
            Configuration(/* args */);
            ~Configuration();

        public:
            unsigned int pin_out_audio;
            unsigned int pin_in_switch;
            unsigned int timer_0;
            float speech_speed;
        };

        class ConfigurationBuilder
        {
        private:
            Configuration conf;
        public:
            ConfigurationBuilder(/* args */);
            ~ConfigurationBuilder();

            ConfigurationBuilder* SetPinOuAudio(const unsigned int pin);
            ConfigurationBuilder* SetPinInSwitch(const unsigned int pin); 
            ConfigurationBuilder* SetTimer(const unsigned int timer);
            ConfigurationBuilder* SetSpeechSpeed(const float speed);
            Configuration Build() const;
        };
    }
}