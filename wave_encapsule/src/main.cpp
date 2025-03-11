#include <iostream>

#include <cstring>
#include <cstdlib>

#include "AudioProcessor.h"
#include "../include/LocalDefine.h"
#include "GlobalDefine.h"

int main(int argc,char* argv[])
{
    if(1 != argc && 2 != argc && 6 != argc && 7 != argc)
    {
        std::cout<<"invalid input!!!"<<std::endl;
        std::cout<<"please enter -h for help"<<std::endl;

        exit(0);
    }

    if(1 == argc) 
    {
        std::cout<<"please enter parameter!!!"<<std::endl;
        std::cout<<"enter -h for help"<<std::endl;

        exit(0);
    }
    else if(2 == argc)
    {
        if(0 == strcmp(argv[1],"-h"))
        {
            std::cout<<"-v show the version infomation"<<std::endl;
            std::cout<<"format:wavcaps [path_in] [path_out] [sample_rate] [channel_count] [sample_depth] [audio_format]"<<std::endl;
        }
        else if(0 == strcmp(argv[1],"-v"))
        {
            std::cout<<"version:"<<VERSION<<std::endl;
            std::cout<<"author:"<<AUTHOR<<std::endl;
            std::cout<<"email:"<<EMAIL<<std::endl;
        }
        else
        {
            std::cout<<"invalid input!!!"<<std::endl;
            std::cout<<"please enter -h for help"<<std::endl;
        }

        exit(0);
    }

    int nSampleRate = atoi(argv[3]);
    int nChannels = atoi(argv[4]);
    int nSampleDeep = atoi(argv[5]);
    if(7 == argc)
    {
        // TODO:process other format
        int nAudioFormat = atoi(argv[6]);

        exit(0);
    }

    int ret = EncapsuleToWave(argv[1],argv[2],nSampleRate,nChannels,nSampleDeep);
    if(-1 == ret)
    {
        std::cout<<"invalid path, please check!!!"<<std::endl;
    }

    return 0;
}