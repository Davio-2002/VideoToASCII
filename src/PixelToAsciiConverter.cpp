#include <PixelToAsciiConverter.h>

namespace {
    constexpr int INTENSITY_LEVEL = 256;
}

PixelToAsciiConverter::PixelToAsciiConverter( FilePathsAliases::StringView asciiChars ) : asciiChars_{ asciiChars }
{}

cv::String PixelToAsciiConverter::convert(const PixelIntensity &intensity) {
    if (intensity < 0 || intensity >= INTENSITY_LEVEL) {
        throw std::out_of_range("Pixel intensity out of range.");
    }
    if (asciiChars_.empty()) {
        throw std::runtime_error("Ascii character set is empty.");
    }
    return std::string(1, asciiChars_[ intensity * asciiChars_.length() / INTENSITY_LEVEL ]);
}


