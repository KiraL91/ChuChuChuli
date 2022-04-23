#pragma once

#include <Arduino.h>
#include "../lib/XT_DAC_Audio/XT_DAC_Audio.h"
#include "../include/configuration.h"

namespace Kiral
{
    namespace Chuli 
    {
        class Manager
        {
        private:
            Configuration conf;

            XT_Wav_Class* wavPlayer;
            XT_DAC_Audio_Class* dacAudio;

            static bool play;

            static bool GetPlay();
            static void SetPlay(const bool play);

        public:
            Manager();
            Manager(const Configuration& conf);
            ~Manager();

            void Setup();
            void Run();
            inline Configuration GetConfiguration() const { return conf; }
            
            static void IRAM_ATTR isr();

        private:
            void Initialize();
        };
    }   
}
