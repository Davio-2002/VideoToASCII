#include <PixelToAsciiConverter.h>
#include <string_view>

namespace {
    const std::string ASCII_CHARS = "   ._-=+*!&#%$@o>{}";
} // anonymous namespace

PixelToAsciiConverter::PixelToAsciiConverter( std::string_view asciiChars) : asciiChars_( asciiChars )
{}

cv::String PixelToAsciiConverter::convert(const PixelIntensity &intensity) {
    return std::string(1, ASCII_CHARS[ intensity * ASCII_CHARS.length() / 256]);
}

