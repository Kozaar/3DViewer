#ifndef SRC_3DVIEWER_V2_0_INTERFACE_GIFCREATE_H_
#define SRC_3DVIEWER_V2_0_INTERFACE_GIFCREATE_H_

#include "QtGui/qimage.h"
#include <vector>

namespace s21 {
class gifCreate {
 public:
    gifCreate();
    ~gifCreate() {}

    void createGif();
    void addImage(QImage newImage);
    bool& writeGif() {return writeGif_;}

 private:
    std::vector<QImage> arrayImage_;
    bool writeGif_;
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_INTERFACE_GIFCREATE_H_
