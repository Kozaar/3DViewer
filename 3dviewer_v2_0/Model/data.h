#ifndef SRC_3DVIEWER_V2_0_MODEL_DATA_H_
#define SRC_3DVIEWER_V2_0_MODEL_DATA_H_

#include <vector>
#include <fstream>

namespace s21 {
class Data {
 public:
    Data();
    explicit Data(std::string filename);
    Data(const Data& other);

    std::vector<std::vector<double>>* setDots() {return &dots_;}
    std::vector<std::vector<int>>* setFacets() {return &facets_;}
    int numberOfDots();
    size_t numberOfFacets();
    Data& operator=(const Data& other);
    std::string filenameWithParametres() {return filenameWithParametres_;}

 private:
    std::vector<std::vector<double>> dots_;
    std::vector<std::vector<int>> facets_;
    void getDot(std::string strDot);
    void getFacet(std::string strFacet);
    void pars(std::string filename);
    std::string filenameWithParametres_;
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_MODEL_DATA_H_
