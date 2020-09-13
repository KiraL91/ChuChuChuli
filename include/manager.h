#pragma once

#include <Arduino.h>
#include "../lib/XT_DAC_Audio/XT_DAC_Audio.h"

namespace Kiral
{
    namespace Chuli 
    {
        class Manager
        {
        private:
            XT_Wav_Class* WavPlayer;
            XT_DAC_Audio_Class* DacAudio;
            
            static bool play;

            static bool GetPlay();
            static void SetPlay(const bool play);

        public:
            Manager(int speaker, int timer);
            ~Manager();

            void Setup(uint8_t button);
            void Run();
            
            static void IRAM_ATTR isr();
        };
    }   
}
