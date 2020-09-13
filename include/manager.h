#pragma once

#include "../lib/XT_DAC_Audio/XT_DAC_Audio.h"
#include "../assets/sound/sound.h"

namespace Kiral
{
    namespace Chuli {
        
        class Manager
        {
        private:

            XT_Wav_Class ChuliSound(Sound);
            XT_DAC_Audio_Class DacAudio(PIN_OUT_AUDIO, TIMER_0);

        public:
            Manager(/* args */);
            ~Manager();
        };
        
        Manager::Manager(/* args */)
        {
        }
        
        Manager::~Manager()
        {
        }
        

    }   
}
