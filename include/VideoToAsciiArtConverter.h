#ifndef VIDEOTOASCIIARTCONVERTER_H
#define VIDEOTOASCIIARTCONVERTER_H

// Local headers

#include <FrameProcessor.h>
#include <VideoProcessor.h>
#include <AsciiRenderer.h>

// Third party headers
#include <opencv2/opencv.hpp>

class VideoToAsciiArtConverter final {
public:
    explicit VideoToAsciiArtConverter( const FilePathsAliases::String &, ResolutionAlias<int> width, ResolutionAlias<int> height );

    void start();

private:
    VideoProcessor vProcessor_;
    PixelToAsciiConverterPtr pixelToAsciiConverter_;
    FrameProcessor fProcessor_;
    AsciiRenderer renderer_;
};



#endif //VIDEOTOASCIIARTCONVERTER_H
