#include <PixelToAsciiConverter.h>
#include <VideoToAsciiArtConverter.h>

namespace {
    const std::string ASCII_CHARS = "   ._-=+*!&#%$@o>{}";
}

VideoToAsciiArtConverter::VideoToAsciiArtConverter(const FilePathsAliases::StringView videoFilePath,
                                                   ResolutionAlias<int> width,
                                                   ResolutionAlias<int> height)
    : vProcessor_{videoFilePath, width, height}
      , fProcessor_{width, height, pixelToAsciiConverter_}
      , pixelToAsciiConverter_{std::make_shared<PixelToAsciiConverter>(ASCII_CHARS)} {
}

void VideoToAsciiArtConverter::start() {
}
