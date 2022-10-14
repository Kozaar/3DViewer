#ifndef SRC_3DVIEWER_V2_0_MODEL_AFFINITYTRANSFORMATION_H_
#define SRC_3DVIEWER_V2_0_MODEL_AFFINITYTRANSFORMATION_H_

#include <vector>

namespace s21 {
class AffinityTransformation {
 public:
    AffinityTransformation();
    void moving(double x, double y, double z);
    void movingX(double x);
    void movingY(double y);
    void movingZ(double z);
    void scale(double x);
    void rotate(double x, double y, double z);
    void rotateX(double x);
    void rotateY(double y);
    void rotateZ(double z);
    void update(std::vector<std::vector<double>> *dots);
    void centeringPicture();

 private:
    std::vector<std::vector<double>> *dots_;
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_MODEL_AFFINITYTRANSFORMATION_H_
