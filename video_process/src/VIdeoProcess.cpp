#include "../include/VideoProcess.h"

#include <cstring>
#include <cstdlib>

/**
 * @see https://blog.csdn.net/leixiaohua1020/article/details/50534369
 */

 int SplitYUV420P(const std::string& szInput,const std::string& szOutY,const std::string& szOutU,
    const std::string& szOutV,int nWidth,int nHeight)
{
	FILE* pIn = fopen(szInput.c_str(), "rb+");
    if(!pIn) return -1;
	FILE* pOutY = fopen(szOutY.c_str(), "wb+");
    if(!pOutY) return -1;
	FILE* pOutU = fopen(szOutU.c_str(), "wb+");
    if(!pOutU) return -1;
	FILE* pOutV = fopen(szOutV.c_str(), "wb+");
    if(!pOutV) return -1;

	unsigned char* pPic = (unsigned char*)malloc(nWidth * nHeight * 3 / 2);

    fread(pPic, 1, nWidth * nHeight * 3 / 2, pIn);
    fwrite(pPic, 1, nWidth * nHeight, pOutY);
    fwrite(pPic + nWidth * nHeight, 1, nWidth * nHeight / 4, pOutU);
    fwrite(pPic + nWidth * nHeight * 5 / 4, 1, nWidth * nHeight / 4, pOutV);

	free(pPic);
	fclose(pIn);
	fclose(pOutY);
	fclose(pOutU);
	fclose(pOutV);

    return 0;
}
int SplitRGB(const std::string& szInput,const std::string& szOutR,const std::string& szOutG,
    const std::string& szOutB,int nWidth,int nHeight)
{
    FILE* pIn = fopen(szInput.c_str(),"rb");
    if(nullptr == pIn) return -1;
    FILE* pOutR = fopen(szOutR.c_str(),"wb+");
    if(nullptr == pOutR) return -1;
    FILE* pOutG = fopen(szOutB.c_str(),"wb+");
    if(nullptr == pOutG) return -1;
    FILE* pOutB = fopen(szOutB.c_str(),"wb+");
    if(nullptr == pOutB) return -1;

    unsigned char* pBuf = (unsigned char*)malloc(nWidth * nHeight * 3);
    int nSize = nWidth * nHeight;
    fread(pBuf,1,nSize * 3,pIn);
    fwrite(pBuf,1,nSize,pOutR);
    fwrite(pBuf + nSize,1,nSize,pOutG);
    fwrite(pBuf+2 * nSize,1,nSize,pOutB);

    free(pBuf);
    fclose(pIn);
    fclose(pOutB);
    fclose(pOutG);
    fclose(pOutR);

    return 0;
}