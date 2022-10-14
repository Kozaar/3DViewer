#include "data.h"
#include <iostream>

s21::Data::Data() {
    dots_.reserve(700000);
    facets_.reserve(500000);
}

s21::Data::Data(std::string filename) : Data() {
    try {
        pars(filename);
        filename.erase(0, filename.rfind("/")+1);
        filenameWithParametres_ =   filename +
                                    "\ndots: " + std::to_string(dots_.size()) +
                                    "\nedges: " + std::to_string(facets_.size());
    } catch (std::exception& e) {
        filenameWithParametres_ = "Wrong file";
    }
}

s21::Data::Data(const Data& other) {
    *this = other;
}

int s21::Data::numberOfDots() {
    return dots_.size();
}

size_t s21::Data::numberOfFacets() {
    return facets_.size();
}

s21::Data& s21::Data::operator=(const Data& other) {
    dots_ = other.dots_;
    facets_ = other.facets_;
    return *this;
}

void s21::Data::pars(std::string filename) {
    std::ifstream fin(filename);
    std::string buf;
    char bufSymbol = 0;
    while (!fin.eof()) {
        fin >> bufSymbol;
        getline(fin, buf);
        if (bufSymbol == 'v') getDot(buf);
        if (bufSymbol == 'f') getFacet(buf);
    }
    fin.close();
}

void s21::Data::getDot(std::string strDot) {
    if (strDot.front() == ' ') {
        std::vector<double> bufDot;
        size_t bufSize_t;
        for (int i = 0; i < 3; i++) {
            bufDot.push_back(std::stod(strDot, &bufSize_t));
            strDot.erase(0, bufSize_t);
        }
        dots_.push_back(bufDot);
    }
}

void s21::Data::getFacet(std::string strFacet) {
    if (strFacet.front() == ' ') {
        std::vector<int> bufFacet;
        size_t bufSize_t;
        while (strFacet.front()) {
            bufFacet.push_back(std::stoi(strFacet, &bufSize_t));
            strFacet.erase(0, bufSize_t);
            while (!strFacet.empty() && strFacet.front() != ' ') strFacet.erase(0, 1);
            while (strFacet.front() == ' ') strFacet.erase(0, 1);
        }
        facets_.push_back(bufFacet);
    }
}
