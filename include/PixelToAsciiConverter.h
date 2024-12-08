#ifndef PIXELTOASCIICONVERTER_H
#define PIXELTOASCIICONVERTER_H

// Local headers
#include <Aliases.h>

// Third party libraries
#include <opencv2/opencv.hpp>

class PixelToAsciiConverter final {
public:
    using PixelIntensity = int;

    explicit PixelToAsciiConverter( CommonStringAliases::StringView asciiChars);

    AsciiArtAliases::String convert(const PixelIntensity &);

    ~PixelToAsciiConverter() = default;

private:
    std::string asciiChars_;
};


#endif //PIXELTOASCIICONVERTER_H
