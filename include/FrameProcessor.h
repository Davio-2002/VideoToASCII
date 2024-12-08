#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H


// local headers
#include <Aliases.h>

// Third party
#include <opencv2/opencv.hpp>

// STL
#include <memory>

class FrameProcessor {
public:
    explicit FrameProcessor(ResolutionAlias<int>, ResolutionAlias<int>, const PixelToAsciiConverterPtr&);

    CommonStringAliases::String processFrame(const cv::Mat&) const;

private:
    ResolutionAlias<int> width{};
    ResolutionAlias<int> height{};

    PixelToAsciiConverterPtr pixelToAsciiConverter;
};

#endif
