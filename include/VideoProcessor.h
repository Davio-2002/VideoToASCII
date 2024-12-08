#ifndef VIDEOPROCESOR_H
#define VIDEOPROCESOR_H

// Local headers
#include <Aliases.h>

// Third party headers
#include <opencv2/opencv.hpp>

// STL


class VideoProcessor final{
public:
    explicit VideoProcessor(FilePathsAliases::StringView videoFilePath, ResolutionAlias<int> width, ResolutionAlias<int> height);

    //// Video Processing
    bool openVideo(FilePathsAliases::StringView videoFilePath);

    bool readNextFrame(cv::Mat& frame);

public:
    //// Getters and Setters
    ResolutionAlias<double> getFps_() const { return fps_; }
    ResolutionAlias<int> getWidth() const { return width; }
    ResolutionAlias<int> getHeight_() const { return height_; }

private:
    //// Members
    cv::VideoCapture cap;

    ResolutionAlias<int> width{};
    ResolutionAlias<int> height_{};

    double fps_{};

    ResolutionAlias<double> frameWidth_{};
    ResolutionAlias<double> frameHeight_{};
};


#endif //VIDEOPROCESOR_H
