#include "gifCreate.h"
#include "gif/gifimage/qgifimage.h"

s21::gifCreate::gifCreate() {
    arrayImage_.reserve(50);
    writeGif_ = false;
}

void s21::gifCreate::createGif() {
    QGifImage gif;
    gif.setDefaultDelay(10);
    for (auto it = arrayImage_.begin(); it != arrayImage_.end(); it++) {
        gif.addFrame(*it);
    }
    gif.save("animation.gif");
    writeGif_ = false;
    arrayImage_.clear();
}

void s21::gifCreate::addImage(QImage newImage) {
    if (writeGif_) {
        arrayImage_.push_back(newImage);
    }
}
