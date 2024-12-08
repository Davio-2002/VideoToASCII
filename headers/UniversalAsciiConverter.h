#ifndef UNIVERSALASCIICONVERTER_H
#define UNIVERSALASCIICONVERTER_H

#include <string>
#include <opencv2/opencv.hpp>

struct AsciiStyleStrategy {
    virtual ~AsciiStyleStrategy() = default;
    virtual std::string pixelToAscii(int pixelIntensity) const = 0;
};

struct GrayScaleStyleStrategy : public AsciiStyleStrategy {
    std::string pixelToAscii(int pixelIntensity) const override;
};

template <Style ColorPolicy>
class UniversalAsciiConverter final {
public:


private:
};

#endif //UNIVERSALASCIICONVERTER_H