#ifndef SRC_3DVIEWER_V2_0_SETTINGS_SETTINGS_H_
#define SRC_3DVIEWER_V2_0_SETTINGS_SETTINGS_H_

#include <string>

namespace s21 {
class Settings {
 public:
    static Settings& Instance() {
        static Settings inst;
        return inst;
    }
    int& ProectionType() {return ProectionType_;}
    double* BackgroundColor() {return BackgroundColor_;}
    int& FacetType() {return FacetType_;}
    int& FacetSize() {return FacetSize_;}
    double* FacetColor() {return FacetColor_;}
    int& DotType() {return DotType_;}
    int& DotSize() {return DotSize_;}
    double* DotColor() {return DotColor_;}
    void setBackgroundColor(double r, double g, double b);
    void setFacetColor(double r, double g, double b);
    void setDotColor(double r, double g, double b);
    void setDefoltSettings();
    void validSettings();
    void writeVariable(std::ofstream* fout, int var);
    void writeVariable(std::ofstream* fout, double* var);

 private:
    Settings();
    ~Settings();

    Settings(const Settings&);
    Settings& operator=(const Settings&);

    void parseConfiguration();
    void writeInConfiguration();

    int ProectionType_;
    double BackgroundColor_[3];

    int FacetType_;
    int FacetSize_;
    double FacetColor_[3];

    int DotType_;
    int DotSize_;
    double DotColor_[3];
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_SETTINGS_SETTINGS_H_
