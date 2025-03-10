/**
 * some functions for audio data process
 */

#ifndef AUDIO_PROCESSOR_H
#define AUDIO_PROCESSOR_H

#if defined(_WIN32) || defined(_WIN64)
    #ifdef AUDIO_PROCESS_EXPORT
        #define AUDIO_PROCESS_API __declspec(dllexport)
    #else
        #define AUDIO_PROCESS_API __declspec(dllimport)
    #endif
#elif defined(__linux__)
    #ifdef AUDIO_PROCESS_EXPORT
        #define AUDIO_PROCESS_API __attribute__((visibility("default")))
    #else
        #define AUDIO_PROCESS_API
    #endif
#else
    #define AUDIO_PROCESS_API
#endif

#include <string>

/**
 * encapsule audio raw data to wave file.
 * 
 * @param szInputPath   input file path
 * @param szOutputPath  output path
 * @param nSampleRate   sample rate
 * @param nChannels     channel count
 * @param nSampleDeep   bits of a sample
 * @param nAudioFormat  audio format, the default is 1(pcm)
 * @return              0 is failed, 1 is succeed
 */
AUDIO_PROCESS_API int EncapsuleToWave(const std::string& szInputPath,const std::string& szOutputPath,
    int nSampleRate,int nChannels,int nSampleDeep,int nAudioFormat = 1);

#endif