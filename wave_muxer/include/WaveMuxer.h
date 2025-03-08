/**
 * 用于封装wave文件的工具类
 */

 #ifndef WAVE_MUXER_H
 #define WAVE_MUXER_H

#include <string>

 class CWaveMuxer
 {
public:
    CWaveMuxer(int nSampleRate,int nChannels,int nSampleDeep,int nAudioFormat = 1);

public:
    /**
     * @ret 0   succeed
     * @ret -1  failed
     */
    int Mux(const std::string& szInputPath,const std::string& szOutputPath);

private:
    int m_nSampleRate;  // 采样率
    int m_nChannels;    // 通道数量
    int m_nSampleDeep;  // 音频采样精度
    int m_nAudioFormat; // 音频采样格式
 };

 #endif