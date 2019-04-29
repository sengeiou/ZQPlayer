//
// Created by johnwu on 2019/4/27.
//



#ifndef ZQPLAYER_DECODER_H
#define ZQPLAYER_DECODER_H

#import "list"
#import "PlayerFrame.h"
#import "PlayerCallJava.h"

extern "C" {
#import <libavformat/avformat.h>
#import <libswresample/swresample.h>
#import <libavutil/imgutils.h>
#import <libswscale/swscale.h>
#import <libavutil/eval.h>
#import <libavutil/display.h>
}

class Decoder {
public:
    PlayerCallJava *playerCallJava;
    AVFormatContext *mFormatContext;
    bool mIsEOF;
    // Video
    int mVideoStreamIndex;
    AVCodecContext *mVideoCodecContext;
    struct SwsContext *mVideoSwsContext;
    AVFrame *mVideoFrame;
    double mVideoFPS;
    double mVideoTimebase;
    double mRotation;
    double mDuration;
    bool mHasVideo;
    //Audio
    int out_sample_rate = 44100;
    enum AVSampleFormat out_formart = AV_SAMPLE_FMT_S16;
    uint64_t out_ch_layout = AV_CH_LAYOUT_STEREO;
    int mAudioStreamIndex;
    AVCodecContext *mAudioCodecContext;
    SwrContext *mAudioSwrContext;
    AVFrame *mAudioFrame;
    double mAudioTimebase;
    bool mHasAudio;

    Decoder(PlayerCallJava *playerCallJava);
    bool open(const char *url);
    bool initVideoCoder(AVFormatContext *formatContext);
    bool initAudioCoder(AVFormatContext *formatContext);
    AVCodecContext* openCodec(AVFormatContext *formatContext, int stream);
    double rotationFromVideoStream(AVStream *stream);

    std::list<PlayerFrame*> readFrames();
    std::list<PlayerFrame*> handleVideoPacket(AVPacket *packet, AVCodecContext *context ,AVFrame *frame,
            struct SwsContext *swsctx);
    std::list<PlayerFrame*> handleAudioPacket(AVPacket *packet,AVCodecContext *context,
                                             AVFrame *frame ,SwrContext *swrctx);

};


#endif //ZQPLAYER_DECODER_H
