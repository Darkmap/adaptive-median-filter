#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

#include <QImage>
#include <windows.h>

class MedianFilter{
public:

    MedianFilter(QImage * s_image);
    ~MedianFilter();

    //添加噪声
    void addNoise();
    //自适应中值滤波
    void AMF();


private:
    //源图像
    QImage * sourceImage;
    //添加噪声图像
    QImage * noiseImage;
    //滤波图像
    QImage * resultImage;

};


#endif // MEDIANFILTER_H
