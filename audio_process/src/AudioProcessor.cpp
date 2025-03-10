#include "../include/AudioProcessor.h"

#include <cstdlib>
#include <cstdint>
#include <cstring>

// @see https://blog.csdn.net/leixiaohua1020/article/details/50534316
int EncapsuleToWave(const std::string& szInputPath,const std::string& szOutputPath,
	int nSampleRate,int nChannels,int nSampleDeep,int nAudioFormat)
{
	// Use platform-independent types for integers to avoid unexpected error
	// header，12 bytes
	struct WAVE_HEADER
	{
		char		fccID[4];
		uint32_t	nSize;		// the total size of file
		char		fccType[4];
	};
	// format，24 bytes
	struct WAVE_FORMAT
	{
		char		fccID[4];
		uint32_t	nSize;				// except the first and second data member, the total bytes of the others ，which is 16 bytes
		uint16_t	nFormatTag;			// audio format，1 is cm
		uint16_t	nChannels;			// channel count
		uint32_t	nSamplesPerSec;		// sample rate
		uint32_t	nAvgBytesPerSec;	// bytes per second
		uint16_t	nBlockAlign;		// equal to Channels * nBitsPerSample / 8
		uint16_t	nBitsPerSample;		// sample depth
	};
	// data，8 bytes
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

	// write header
	memcpy(header.fccID, "RIFF", strlen("RIFF"));
	header.nSize = 0;
	memcpy(header.fccType, "WAVE", strlen("WAVE"));
	// here we don't know the size, so we seek to next segment
	fseek(pFileOut, sizeof(WAVE_HEADER), SEEK_CUR);

	// write format
	format.nChannels = nChannels;
	format.nSamplesPerSec = nSampleRate;
	format.nBitsPerSample = nSampleDeep;
	format.nBlockAlign = format.nChannels * (format.nBitsPerSample / 8);
	format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;
	// Be careful!!! Don't forget the space int the end
	memcpy(format.fccID, "fmt ", strlen("fmt "));
	// the bytes of WAVE_FORMAT minus bytes of fccid and nsize
	format.nSize = 16;
	format.nFormatTag = nAudioFormat;
	fwrite(&format, sizeof(WAVE_FORMAT), 1, pFileOut);

	// write data
	memcpy(data.fccID, "data", strlen("data"));
	data.nSize = 0;
	fseek(pFileOut, sizeof(WAVE_DATA), SEEK_CUR);

	// write pcm data
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

	// both of 36 and 44 are valid，but 36 is more strict
	header.nSize = 36 + data.nSize;
	rewind(pFileOut);
	fwrite(&header, sizeof(WAVE_HEADER), 1, pFileOut);
	fseek(pFileOut, sizeof(WAVE_FORMAT), SEEK_CUR);
	fwrite(&data, sizeof(WAVE_DATA), 1, pFileOut);

	free(pBuf);
	fclose(pIn);
	fclose(pFileOut);

    return 0;
}