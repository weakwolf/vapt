## 介绍
## wave_muxer是一款可以将pcm音频采样数据封装为wave文件的工具。wave格式是一种非常简单的音频封装格式，其内部没有对音频数据进行压缩，只是加了文件头用于存储音频格式信息
## 使用说明 
### -v 输出版本信息<br> -h 输出帮助信息<br>
## 示例
### wave_muxer input.pcm output.wav 44100 2 16 pcm<br>input.pcm--原始pcm采样数据的路径<br>output.wav--输出路径<br>44100--采样率<br>2--通道数<br>16--采样精度<br>pcm代表音频格式，如果不输入这个参数则默认为pcm