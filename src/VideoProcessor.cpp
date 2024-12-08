#include <VideoProcessor.h>

VideoProcessor::VideoProcessor(FilePathsAliases::StringView videoFilePath, ResolutionAlias<int> width,
                               ResolutionAlias<int> height)
    : width_(width), height_(height) {
}

bool VideoProcessor::openVideo(const FilePathsAliases::String &videoFilePath) {
    cap.open(videoFilePath);
    if (!cap.isOpened()) {
        return false;
    }

    fps_ = cap.get(cv::CAP_PROP_FPS);
    frameWidth_ = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    frameHeight_ = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    this->height_ = static_cast<int>((width_ * frameHeight_ / frameWidth_) * 0.4194);
    return true;
}

bool VideoProcessor::readNextFrame(cv::Mat &frame) {
    cap >> frame;
    return !frame.empty();
}
