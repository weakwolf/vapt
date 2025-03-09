## Introduction
### this repository includes some tools which can process audio data.<br>Well, until now, this project is just a toy.
## How to build?
### clone this project;execute "mkdir build" in the main directory; cd build;run cmake and make
## Tool list
### wave_muxer:<br>this tool can encapsulate raw audio data     into a WAV file. When you want to store some raw auido data,you can use this tool, so that you don't need know the sample rate, channels and so on to play it next time.<br>example:wave_muxer input.pcm output.wav 44100 2 16 pcm<br>input.pcm--raw data path<br>output.wav--output path<br>44100--sample rate<br>2--channel count<br>16--sample depth<br>pcm--audio format, this is optional. If you don't input, the default is pcm
## finally
### have fun!
