#ifndef VIDEOPROCESOR_H
#define VIDEOPROCESOR_H

// Third party headers
#include <opencv2/opencv.hpp>

// Local headers
#include <Aliases.h>

// STL


class VideoProcessor final{
public:
    explicit VideoProcessor(FilePaths::StrView videoFilePath, Resolution<int> width, Resolution<int> height);

    //// Video Processing
    bool openVideo(FilePaths::StrView videoFilePath);

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
