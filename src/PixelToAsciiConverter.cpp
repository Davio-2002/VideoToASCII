#include <PixelToAsciiConverter.h>

namespace {
    constexpr int INTENSITY_LEVEL = 256;
}

PixelToAsciiConverter::PixelToAsciiConverter( FilePathsAliases::StringView asciiChars ) : asciiChars_{ asciiChars }
{}

cv::String PixelToAsciiConverter::convert(const PixelIntensity &intensity) {
    return std::string(1, asciiChars_[ intensity * asciiChars_.length() / INTENSITY_LEVEL]);
}

