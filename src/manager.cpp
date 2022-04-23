#include "../include/manager.h"
#include "../assets/sound/sound.h"

namespace Kiral
{
    namespace Chuli 
    {
        bool Manager::play = false;

        Manager::Manager()
        {
            Initialize();
        }

        Manager::Manager(const Configuration& conf)
        {   
            this->conf = conf;
            Initialize();
        }
        
        void Manager::Initialize() {
            wavPlayer = new XT_Wav_Class(Sound);
            dacAudio = new XT_DAC_Audio_Class(conf.pin_out_audio, conf.timer_0);
            Serial.begin(115200);
        }

        Manager::~Manager()
        {
            delete dacAudio;
            delete wavPlayer;
        }

        void Manager::Setup()
        {
            pinMode(conf.pin_in_switch, INPUT);
            attachInterrupt(conf.pin_in_switch, &Manager::isr, FALLING);

            wavPlayer->Speed = conf.speech_speed;
            SetPlay(false);
        }

        void Manager::Run() 
        {
            dacAudio->FillBuffer();
            if(!wavPlayer->Playing && GetPlay()) {
                dacAudio->Play(wavPlayer);
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
