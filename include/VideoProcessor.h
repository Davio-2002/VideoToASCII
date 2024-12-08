#ifndef VIDEOPROCESOR_H
#define VIDEOPROCESOR_H

// Local headers
#include <Aliases.h>

// Third party headers
#include <opencv2/opencv.hpp>

// STL


class VideoProcessor final{
public:
    VideoProcessor(const FilePathsAliases::String &videoFilePath, ResolutionAlias<int> width, ResolutionAlias<int> height);

    //// Video Processing
    bool openVideo();

    bool readNextFrame(cv::Mat& frame);

public:
    //// Getters and Setters
    ResolutionAlias<double> getFps_() const { return fps_; }
    ResolutionAlias<int> getWidth() const { return width_; }
    ResolutionAlias<int> getHeight_() const { return height_; }

private:
    //// Members
    cv::VideoCapture cap;
    FilePathsAliases::String videoFilePath_;

    ResolutionAlias<int> width_{};
    ResolutionAlias<int> height_{};

    double fps_{};

    ResolutionAlias<double> frameWidth_{};
    ResolutionAlias<double> frameHeight_{};
};


#endif //VIDEOPROCESOR_H
