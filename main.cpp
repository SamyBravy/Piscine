#include <iostream>

#include "BitmapImage.h"

static const std::string VERSION = "v1.0";

int main() {
    std::cout << "Image viewer - " << VERSION << std::endl;
    BitmapImage b;
    std::string imgName = "test.png";
    if (b.load(imgName))
        std::cout << "show image: " << imgName << std::endl;
    else
        std::cerr << "image:" << imgName << " not readable." << std::endl;
    return 0;
}