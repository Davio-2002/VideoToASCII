#ifndef PIXELTOASCIICONVERTER_H
#define PIXELTOASCIICONVERTER_H

// Third party libraries
#include <opencv2/opencv.hpp>

class PixelToAsciiConverter {
public:
    using PixelIntensity = int;

    explicit PixelToAsciiConverter(std::string_view asciiChars);

    static cv::String convert(const PixelIntensity &);

    ~PixelToAsciiConverter() = default;

private:
    std::string asciiChars_;
};


#endif //PIXELTOASCIICONVERTER_H
