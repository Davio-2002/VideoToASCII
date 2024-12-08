#include <FrameProcessor.h>
#include <PixelToAsciiConverter.h>

FrameProcessor::FrameProcessor(ResolutionAlias<int> width, ResolutionAlias<int> height,
                               const PixelToAsciiConverterPtr &pixelToAsciiConverter)
    : width_(width)
    , height_(height)
    , pixelToAsciiConverter_(pixelToAsciiConverter) {
}

CommonStringAliases::String FrameProcessor::processFrame(const cv::Mat &frame) const {
    cv::Mat grayFrame;
    cv::Mat resizedFrame;
    cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
    resize(grayFrame, resizedFrame, cv::Size(width_, height_), 0, 0, cv::INTER_LINEAR);


    AsciiArtAliases::String asciiFrame;
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            asciiFrame += pixelToAsciiConverter_->convert(resizedFrame.at<uchar>(i, j));
        }
        asciiFrame += "\n";
    }

    return asciiFrame;
}
