#include <VideoProcessor.h>

VideoProcessor::VideoProcessor(const FilePathsAliases::String &videoFilePath, ResolutionAlias<int> width,
                               ResolutionAlias<int> height)
    : videoFilePath_(videoFilePath), width_(width), height_(height) {
}

bool VideoProcessor::openVideo() {
    cap.open(videoFilePath_);
    if (!cap.isOpened()) {
        return false;
    }

    fps_ = cap.get(cv::CAP_PROP_FPS);
    frameWidth_ = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    frameHeight_ = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    std::cout << "Video FPS: " << fps_ << std::endl;
    std::cout << "Frame Width: " << frameWidth_ << std::endl;
    std::cout << "Frame Height: " << frameHeight_ << std::endl;


    this->height_ = static_cast<int>((width_ * frameHeight_ / frameWidth_) * 0.4194);
    return true;
}

bool VideoProcessor::readNextFrame(cv::Mat &frame) {
    cap >> frame;
    return !frame.empty();
}
