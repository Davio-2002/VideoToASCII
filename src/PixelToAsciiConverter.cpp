#include <PixelToAsciiConverter.h>
#include <string_view>

namespace {
    const std::string ASCII_CHARS = "   ._-=+*!&#%$@o>{}";
    constexpr int INTENSITY_LEVEL = 256;
}

PixelToAsciiConverter::PixelToAsciiConverter( std::string_view asciiChars) : asciiChars_( asciiChars )
{}

cv::String PixelToAsciiConverter::convert(const PixelIntensity &intensity) {
    return std::string(1, ASCII_CHARS[ intensity * ASCII_CHARS.length() / INTENSITY_LEVEL]);
}

