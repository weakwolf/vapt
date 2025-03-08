#include "../include/WaveMuxer.h"

#include <cstdlib>
#include <cstdint>
#include <cstring>

CWaveMuxer::CWaveMuxer(int nSampleRate,int nChannels,int nSampleDeep,int nAudioFormat)
                        :m_nSampleRate(nSampleRate),m_nChannels(nChannels),
                        m_nSampleDeep(nSampleDeep),m_nAudioFormat(nAudioFormat)
{

}

int CWaveMuxer::Mux(const std::string& szInputPath,const std::string& szOutputPath)
{
	// 以下结构体对应wava文件中的数据块
	// !!!整型最好使用平台无关类型，否则可能会跟预期的有出入!!!
	// header，12字节
	struct WAVE_HEADER
	{
		char		fccID[4];
		uint32_t	nSize;		// 文件总大小
		char		fccType[4];
	};
	// format，24字节
	struct WAVE_FORMAT
	{
		char		fccID[4];
		uint32_t	nSize;				// 除去前两个字段，其余字段的字节数之和，为16
		uint16_t	nFormatTag;			// 格式类型，1代表pcm
		uint16_t	nChannels;			// 通道数
		uint32_t	nSamplesPerSec;		// 采样率
		uint32_t	nAvgBytesPerSec;	// 每秒字节数
		uint16_t	nBlockAlign;		// 等于nChannels * nBitsPerSample / 8
		uint16_t	nBitsPerSample;		// 一个通道中样本的位数，例如16位整型为16
	};
	// data，8字节
	struct WAVE_DATA 
	{
		char		fccID[4];
		uint32_t	nSize;
	};

	FILE* pIn = fopen(szInputPath.c_str(), "rb");
	FILE* pFileOut = fopen(szOutputPath.c_str(), "wb+");
    if(nullptr == pIn || nullptr == pFileOut)
    {
        return -1;
    }

	WAVE_HEADER header;
	memset(header.fccID, 0, 4);
	memset(header.fccType, 0, 4);
	WAVE_FORMAT format;
	memset(format.fccID, 0, 4);
	WAVE_DATA data;
	memset(data.fccID, 0, 4);

	// 填充header
	memcpy(header.fccID, "RIFF", strlen("RIFF"));
	header.nSize = 0;
	memcpy(header.fccType, "WAVE", strlen("WAVE"));
	// 注意，我们这里先不填充nSize字段
	fseek(pFileOut, sizeof(WAVE_HEADER), SEEK_CUR);

	// 填充format
	format.nChannels = m_nChannels;
	format.nSamplesPerSec = m_nSampleRate;
	format.nBitsPerSample = m_nSampleDeep;
	format.nBlockAlign = format.nChannels * (format.nBitsPerSample / 8);
	format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;
	// !!!不要忘记fmt后面的空格，这是四个字节
	memcpy(format.fccID, "fmt ", strlen("fmt "));
	// WAVE_FORMAT中除去fccid和nsize这两个字段的其余字段的总大小
	format.nSize = 16;
	// 音频格式，例如pcm
	format.nFormatTag = m_nAudioFormat;
	fwrite(&format, sizeof(WAVE_FORMAT), 1, pFileOut);

	// 填充data
	memcpy(data.fccID, "data", strlen("data"));
	data.nSize = 0;
	// 同样的，我们这里先不填充nSize字段
	fseek(pFileOut, sizeof(WAVE_DATA), SEEK_CUR);

	// 填充pcm数据
	int nSize = format.nBlockAlign;
	unsigned char* pBuf = (unsigned char*)malloc(nSize);
#if 0
	while (!feof(pIn))
	{
		fread(pBuf, 1, nSize, pIn);
		fwrite(pBuf, 1, nSize, pFileOut);
		data.nSize += nSize;
	}
#else
	fread(pBuf, nSize, 1, pIn);
	while (!feof(pIn))
	{
		data.nSize += nSize;
		fwrite(pBuf, nSize, 1, pFileOut);
		fread(pBuf, nSize, 1, pIn);
	}
#endif

	// 36和44都可以，但是36更符合规范
	header.nSize = 36 + data.nSize;
	// rewind函数用于将文件的位置指针重置到文件的开头
	rewind(pFileOut);
	fwrite(&header, sizeof(WAVE_HEADER), 1, pFileOut);
	fseek(pFileOut, sizeof(WAVE_FORMAT), SEEK_CUR);
	fwrite(&data, sizeof(WAVE_DATA), 1, pFileOut);

	free(pBuf);
	fclose(pIn);
	fclose(pFileOut);

    return 0;
}