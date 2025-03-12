/**
 * some funcitons which can process raw video data
 */

 #ifndef VIDEO_PROCESS_H
 #define VIDEO_PROCESS_H
 
 #if defined(_WIN32) || defined(_WIN64)
     #ifdef VIDEO_PROCESS_EXPORT
         #define VIDEO_PROCESS_API __declspec(dllexport)
     #else
         #define VIDEO_PROCESS_API __declspec(dllimport)
     #endif
 #elif defined(__linux__)
     #ifdef VIDEO_PROCESS_EXPORT
         #define VIDEO_PROCESS_API __attribute__((visibility("default")))
     #else
         #define VIDEO_PROCESS_API
     #endif
 #else
     #define VIDEO_PROCESS_API
 #endif

#include <string>

 /**
  * split yuv420p into y, u, v
  * 
  * @param szInput  yuv picture file path
  * @param szOutY   y data output path
  * @param szOutU   u data output path
  * @param szOutV   v data output path
  * @param nWidth   the width of yuv picture
  * @param nHeight  the height of yuv picture
  * @return         -1 is failed, 0 is succeed
  */
 VIDEO_PROCESS_API int SplitYUV420P(const std::string& szInput,const std::string& szOutY,const std::string& szOutU,
    const std::string& szOutV,int nWidth,int nHeight);
/**
 * @param szInput   rgb file input path
 * @param szOutR    r data output path
 * @param szOutG    g data output path
 * @param szOutB    b data output path
 * @param nWidth    the width of rgb picture
 * @param nHeight   the height of rgb picture
 * @return          -1 is failed, 0 is succeed
 */
VIDEO_PROCESS_API int SplitRGB(const std::string& szInput,const std::string& szOutR,const std::string& szOutG,
        const std::string& szOutB,int nWidth,int nHeight);
    
/**
 * transform yuv420p into rgb
 * 
 * @param szInput   yuv420p file path
 * @param szOut     rgb file outout path
 * @return          -1 is failed,0 is succeed
 */
VIDEO_PROCESS_API int YUV420P2RGB(const std::string& szInput,const std::string& szOut);

#endif