#include "affinitytransformation.h"
#include <cmath>

s21::AffinityTransformation::AffinityTransformation() {
    this->dots_ = nullptr;
}

void s21::AffinityTransformation::moving(double x, double y, double z) {
    if (!dots_) return;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        it->at(0) += x;
        it->at(1) += y;
        it->at(2) += z;
    }
}

void s21::AffinityTransformation::movingX(double x) {
    if (!dots_) return;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        it->at(0) += x;
    }
}

void s21::AffinityTransformation::movingY(double y) {
    if (!dots_) return;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        it->at(1) += y;
    }
}

void s21::AffinityTransformation::movingZ(double z) {
    if (!dots_) return;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        it->at(2) += z;
    }
}

void s21::AffinityTransformation::scale(double x) {
    if (!dots_) return;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        it->at(0) *= x;
        it->at(1) *= x;
        it->at(2) *= x;
    }
}

void s21::AffinityTransformation::rotate(double x, double y, double z) {
    if (!dots_) return;
    x /= (180 / M_PI);
    y /= (180 / M_PI);
    z /= (180 / M_PI);
    std::vector<double> oldDot;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        //  calculate x rotation
        oldDot = *it;
        it->at(0) = oldDot.at(0);
        it->at(1) = (cos(x) * oldDot.at(1)) + (sin(x) * oldDot.at(2));
        it->at(2) = (-(sin(x)) * oldDot.at(1)) + (cos(x) * oldDot.at(2));
        //  calculate y rotation
        oldDot = *it;
        it->at(0) = (cos(y) * oldDot.at(0)) + (sin(y) * oldDot.at(2));
        it->at(1) = oldDot.at(1);
        it->at(2) = (-(sin(y)) * oldDot.at(0)) + (cos(y) * oldDot.at(2));
        //  calculate z rotation
        oldDot = *it;
        it->at(0) = (cos(z) * oldDot.at(0)) + (sin(z) * oldDot.at(1));
        it->at(1) = (-(sin(z)) * oldDot.at(0)) + (cos(z) * oldDot.at(1));
        it->at(2) = oldDot.at(2);
    }
}

void s21::AffinityTransformation::rotateX(double x) {
    if (!dots_) return;
    x *= (M_PI / 180);
    std::vector<double> oldDot;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        oldDot = *it;
        it->at(0) = oldDot.at(0);
        it->at(1) = (cos(x) * oldDot.at(1)) + (sin(x) * oldDot.at(2));
        it->at(2) = (-(sin(x)) * oldDot.at(1)) + (cos(x) * oldDot.at(2));
    }
}

void s21::AffinityTransformation::rotateY(double y) {
    if (!dots_) return;
    y *= (M_PI / 180);
    std::vector<double> oldDot;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        oldDot = *it;
        it->at(0) = (cos(y) * oldDot.at(0)) + (sin(y) * oldDot.at(2));
        it->at(1) = oldDot.at(1);
        it->at(2) = (-(sin(y)) * oldDot.at(0)) + (cos(y) * oldDot.at(2));
    }
}

void s21::AffinityTransformation::rotateZ(double z) {
    if (!dots_) return;
    z *= (M_PI / 180);
    std::vector<double> oldDot;
    for (auto it = dots_->begin(); it != dots_->end(); it++) {
        oldDot = *it;
        it->at(0) = (cos(z) * oldDot.at(0)) + (sin(z) * oldDot.at(1));
        it->at(1) = (-(sin(z)) * oldDot.at(0)) + (cos(z) * oldDot.at(1));
        it->at(2) = oldDot.at(2);
    }
}

void s21::AffinityTransformation::update(std::vector<std::vector<double> > *dots) {
    if (!dots || dots->empty()) return;
    dots_ = dots;
    double minX, minY, maxX, maxY;
    minX = maxX = dots->data()[0][0];
    minY = maxY = dots->data()[0][1];
    for (size_t i = 0; i < dots->size(); i++) {
        if (dots->data()[i][0] < minX) {
            minX = dots->data()[i][0];
        } else if (dots->data()[i][0] > maxX) {
            minX = dots->data()[i][0];
        }
        if (dots->data()[i][1] < minY) {
            minY = dots->data()[i][1];
        } else if (dots->data()[i][1] > maxY) {
            maxY = dots->data()[i][1];
        }
        while (minX < -1 || minY < -1.5 || maxX > 1 || maxY > 1.5) {
            scale(0.9);
            minX *= 0.9;
            maxX *= 0.9;
            minY *= 0.9;
            maxY *= 0.9;
        }
    }
}

void s21::AffinityTransformation::centeringPicture() {
    if (!dots_) return;
    double movingX = 0, movingY = 0, movingZ = 0;
    for (size_t i = 0; i < dots_->size(); i++) {
        movingX -= dots_->data()[i][0] / dots_->size();
        movingY -= dots_->data()[i][1] / dots_->size();
        movingZ -= dots_->data()[i][2] / dots_->size();
    }
    moving(movingX, movingY, movingZ);
}
