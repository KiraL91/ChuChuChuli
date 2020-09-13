#include "../include/manager.h"
#include "../assets/sound/sound.h"

namespace Kiral
{
    namespace Chuli 
    {
        bool Manager::play = false;

        Manager::Manager(int speaker, int timer)
        {
            WavPlayer = new XT_Wav_Class(Sound);
            DacAudio = new XT_DAC_Audio_Class(speaker, timer);
        }
        
        Manager::~Manager()
        {
            delete DacAudio;
            delete WavPlayer;
        }

        void Manager::Setup(uint8_t button) 
        {
            pinMode(button, INPUT);
            attachInterrupt(button, &Manager::isr, FALLING);

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
