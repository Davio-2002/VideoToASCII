#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

// Third party
#include <opencv2/opencv.hpp>

// local headers
#include <Aliases.h>
#include <PixelToAsciiConverter.h>
// STL
#include <memory>

class FrameProcessor {

private:
    Resolution<int> width{};
    Resolution<int> height{};

    PixelToAsciiConverterPtr pixelToAsciiConverter;
};

#endif
