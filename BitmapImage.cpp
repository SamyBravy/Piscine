#include "BitmapImage.h"

BitmapImage::BitmapImage() : width(640), height(480), channels(3), depth(8)
{
    buffer = new int[width * height * channels];
}

bool BitmapImage::load(std::string name) {
    // check it is a supported image file
    std::string fileExt = name.substr(name.find_last_of(".") + 1);
    if (fileExt == "jpg") {
        // load image file
        // decompress into buffer
        return true;
    }
    return false;
}

void BitmapImage::resize(int newWitdh, int newHeight)
{
    width = newWitdh;
    height = newHeight;
    // pretend to resize image...
    delete []buffer;
    buffer = new int[width * height * channels];
}

BitmapImage::~BitmapImage() {
    delete[] buffer;
}
