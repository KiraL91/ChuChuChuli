#include "../include/manager.h"
#include "../assets/sound/sound.h"
#include "../include/config.h"

namespace Kiral
{
    namespace Chuli 
    {
        bool Manager::play = false;

        Manager::Manager()
        {
            WavPlayer = new XT_Wav_Class(Sound);
            DacAudio = new XT_DAC_Audio_Class(PIN_OUT_AUDIO, TIMER_0);
        }
        
        Manager::~Manager()
        {
            delete DacAudio;
            delete WavPlayer;
        }

        void Manager::Setup() 
        {
            pinMode(PIN_IN_SWITCH, INPUT);
            attachInterrupt(PIN_IN_SWITCH, &Manager::isr, FALLING);

            WavPlayer->Speed = 2;
            SetPlay(false);
        }

        void Manager::Run() 
        {
            DacAudio->FillBuffer();
            if(!WavPlayer->Playing && GetPlay()) {
                DacAudio->Play(WavPlayer);
                SetPlay(false);
            }
        }


        bool Manager::GetPlay()
        {
            return play;
        }

        void Manager::SetPlay(const bool play)
        {
            Manager::play = play;
        }

        void IRAM_ATTR Manager::isr() {
            play = !play;
        }
    }   
}
