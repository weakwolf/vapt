#include <iostream>

#include <cstring>
#include <cstdlib>

#include "../include/WaveMuxer.h"

int main(int argc,char* argv[])
{
    // 参数检查
    if(1 != argc && 2 != argc && 6 != argc && 7 != argc)
    {
        std::cout<<"invalid input!!!"<<std::endl;
        std::cout<<"please enter -h for help"<<std::endl;

        exit(0);
    }

    // 参数处理
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
            std::cout<<"format:wave_muxer [path_in] [path_out] [sample_rate] [channel_count] [sample_depth] [audio_format]"<<std::endl;
        }
        else if(0 == strcmp(argv[1],"-v"))
        {
            std::cout<<"version:1.0"<<std::endl;
            std::cout<<"written by wearkwolf"<<std::endl;
            std::cout<<"email:1946075576@qq.com"<<std::endl;
        }
        else
        {
            std::cout<<"invalid input!!!"<<std::endl;
            std::cout<<"please enter -h for help"<<std::endl;
        }

        exit(0);
    }
    
    // 获取采样率，通道数量，采样精度，音频格式
    int nSampleRate = atoi(argv[3]);
    int nChannels = atoi(argv[4]);
    int nSampleDeep = atoi(argv[5]);
    // 在wava文件中使用整数来代表音频采样格式，例如1代表pcm
    int nAudioFOrmat = 1;
    if(7 == argc)
    {
        // TODO:其他采样格式的处理
    }

    // 封装音频数据
    CWaveMuxer waveMuxer(nSampleRate,nChannels,nSampleDeep,nAudioFOrmat);
    int ret = waveMuxer.Mux(argv[1],argv[2]);
    if(-1 == ret)
    {
        std::cout<<"invalid path, please check!!!"<<std::endl;
    }

    return 0;
}