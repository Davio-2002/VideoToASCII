#ifndef VIDEOPROCESOR_H
#define VIDEOPROCESOR_H

#include <opencv2/opencv.hpp>

/// No need to write template like this, but I am just experimenting with language, don't blame )
template <class MetricTypes>
using Resolution = MetricTypes;

class VideoProcessor final{
public:
    using Path = std::string_view;

    explicit VideoProcessor(Path videoFilePath, Resolution<int> width, Resolution<int> height);

    //// Video Processing
    bool openVideo(Path videoFilePath);

    bool readNextFrame(cv::Mat& frame);

public:
    //// Getters and Setters
    Resolution<double> getFps_() const { return fps_; }
    Resolution<int> getWidth() const { return width; }
    Resolution<int> getHeight_() const { return height_; }

private:
    //// Members
    cv::VideoCapture cap;

    Resolution<int> width{};
    Resolution<int> height_{};

    double fps_{};

    Resolution<double> frameWidth_{};
    Resolution<double> frameHeight_{};
};


#endif //VIDEOPROCESOR_H
