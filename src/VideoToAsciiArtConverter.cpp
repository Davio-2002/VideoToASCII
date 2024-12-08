// Local headers

#include <PixelToAsciiConverter.h>
#include <VideoToAsciiArtConverter.h>

// STL
#include <thread>
#include <chrono>

namespace {
    const std::string ASCII_CHARS = "   ._-=+*!&#%$@o>{}";
}

VideoToAsciiArtConverter::VideoToAsciiArtConverter(const FilePathsAliases::StringView videoFilePath,
                                                   ResolutionAlias<int> width,
                                                   ResolutionAlias<int> height)
    : vProcessor_{videoFilePath, width, height}
      , fProcessor_{width, height, pixelToAsciiConverter_}
      , pixelToAsciiConverter_{std::make_shared<PixelToAsciiConverter>(ASCII_CHARS)}
{
}

void VideoToAsciiArtConverter::start() {
    if (!vProcessor_.openVideo("testing")) {
        std::cerr << "Failed to open video" << std::endl;
        return;
    }

    cv::Mat frame;
    const auto frameDurationMs = static_cast<int>(500 / vProcessor_.getFps_());

    while (true) {
        if (!vProcessor_.readNextFrame(frame)) {
            break;
        }

        const auto asciiFrame = fProcessor_.processFrame(frame);
        renderer_.render(asciiFrame);

        std::this_thread::sleep_for(std::chrono::milliseconds(frameDurationMs));
    }
}
