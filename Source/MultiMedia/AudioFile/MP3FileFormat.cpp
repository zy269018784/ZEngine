#include "MP3FileFormat.h"
#include "PCM.h"

#include <lame/lame.h>

#include <stdio.h>

int MP3FileFormat::LameEncoder(class PCM* InPCM, std::string OutputFile)
{
	lame_global_flags* GlobalFlags = nullptr;

    FILE* MP3File = fopen(OutputFile.c_str(), "wb");
    if (!MP3File)
    {
        return -1;
    }
    GlobalFlags = lame_init();
	lame_set_in_samplerate(GlobalFlags, InPCM->GetSampleRate());
	lame_set_num_channels(GlobalFlags,  InPCM->GetChannels());
	lame_set_quality(GlobalFlags, 2);  // 质量等级 2(较好)
	lame_init_params(GlobalFlags);

    //lame_set_in_samplerate(GlobalFlags, 44100);
    //lame_set_num_channels(GlobalFlags, 2);
    //lame_set_quality(GlobalFlags, 2);  // 质量等级 2(较好)
    //lame_init_params(GlobalFlags);

    const int BUFFER_SIZE = 8192;
    const int MP3_BUFFER_SIZE = 8192;
    unsigned char MP3Buffer[MP3_BUFFER_SIZE]; 

    /*
        样本数量
    */
    int LeftSampleCount = InPCM->GetSampleCount();
    /*
        通道数量
    */
    int Channels = InPCM->GetChannels();
    auto PCMBuffer = InPCM->GetPCMBuffer();
    int PCMBufferSampleOffset = 0;
    /*
        每次循环处理8192个样本
    */
    int CurrentSampleCount  = 8192;
    size_t NumWriteBytes = 0;
    while (LeftSampleCount > 0)
    {
        CurrentSampleCount = 8192;
        if (LeftSampleCount < 8192)
            CurrentSampleCount = LeftSampleCount;

        int encoded = lame_encode_buffer_interleaved(
            GlobalFlags, PCMBuffer.data() + PCMBufferSampleOffset, CurrentSampleCount / Channels, MP3Buffer, MP3_BUFFER_SIZE
        );

        NumWriteBytes += fwrite(MP3Buffer, 1, encoded, MP3File);
        //printf("NumWriteBytes %llu, PCMBufferSampleOffset %d, encoded %d, CurrentSampleCount %d\n", 
        //    NumWriteBytes, PCMBufferSampleOffset, encoded, CurrentSampleCount);

        PCMBufferSampleOffset += CurrentSampleCount;

        LeftSampleCount -= CurrentSampleCount;
    }

    // 刷新剩余数据
    int final = lame_encode_flush(GlobalFlags, MP3Buffer, MP3_BUFFER_SIZE);
    NumWriteBytes += fwrite(MP3Buffer, 1, final, MP3File);
    printf("NumWriteBytes %llu\n", NumWriteBytes);

    lame_close(GlobalFlags);

	return 0;
}