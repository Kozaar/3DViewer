#include "settings.h"
#include <fstream>

s21::Settings::Settings() {
    parseConfiguration();
}

s21::Settings::~Settings() {
    writeInConfiguration();
}

void s21::Settings::parseConfiguration() {
    std::ifstream fin("configuration.conf");
    setDefoltSettings();
    if (fin.is_open()) {
        fin >> ProectionType_;
        fin >> FacetType_;
        fin >> FacetSize_;
        fin >> DotType_;
        fin >> DotSize_;
        for (int i = 0; i < 3; i++) {
            fin >> BackgroundColor_[i];
        }
        for (int i = 0; i < 3; i++) {
            fin >> FacetColor_[i];
        }
        for (int i = 0; i < 3; i++) {
            fin >> DotColor_[i];
        }
        fin.close();
        validSettings();
    }
}


void s21::Settings::setDefoltSettings() {
    ProectionType_ = 1;
    FacetType_ = 0;
    FacetSize_ = 1;
    DotType_ = 0;
    DotSize_ = 1;
    for (int i = 0; i < 3; i++) {
        BackgroundColor_[i] = 0.0;
        FacetColor_[i] = 1.0;
        DotColor_[i] = 0.5;
    }
}

void s21::Settings::validSettings() {
    if (ProectionType_ < 0 || ProectionType_ > 1) ProectionType_ = 0;
    if (FacetType_ < 0 || FacetType_ > 1) FacetType_ = 0;
    if (FacetSize_ < 1 || FacetSize_ > 50) FacetSize_ = 1;
    if (DotType_ < 0 || DotType_ > 2) DotType_ = 0;
    if (DotSize_ < 1 || DotSize_ > 50) DotSize_ = 1;
    for (int i = 0; i < 3; i++) {
        if (BackgroundColor_[i] > 1.0 || BackgroundColor_[i] < 0.0) BackgroundColor_[i] = 0.0;
        if (FacetColor_[i] > 1.0 || FacetColor_[i] < 0.0) FacetColor_[i] = 0.0;
        if (DotColor_[i] > 1.0 || DotColor_[i] < 0.0) DotColor_[i] = 0.0;
    }
}

void s21::Settings::writeInConfiguration() {
    std::ofstream fout("configuration.conf");
    writeVariable(&fout, ProectionType_);
    writeVariable(&fout, FacetType_);
    writeVariable(&fout, FacetSize_);
    writeVariable(&fout, DotType_);
    writeVariable(&fout, DotSize_);
    writeVariable(&fout, BackgroundColor_);
    writeVariable(&fout, FacetColor_);
    writeVariable(&fout, DotColor_);
    fout.close();
}

void s21::Settings::writeVariable(std::ofstream* fout, int var) {
    *fout << var;
    *fout << '\n';
}

void s21::Settings::writeVariable(std::ofstream* fout, double* var) {
    for (int i = 0; i < 3; i++) {
        *fout << var[i];
        *fout << '\n';
    }
}

void s21::Settings::setBackgroundColor(double r, double g, double b) {
    BackgroundColor_[0] = r;
    BackgroundColor_[1] = g;
    BackgroundColor_[2] = b;
}

void s21::Settings::setFacetColor(double r, double g, double b) {
    FacetColor_[0] = r;
    FacetColor_[1] = g;
    FacetColor_[2] = b;
}

void s21::Settings::setDotColor(double r, double g, double b) {
    DotColor_[0] = r;
    DotColor_[1] = g;
    DotColor_[2] = b;
}










