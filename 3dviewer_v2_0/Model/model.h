#ifndef SRC_3DVIEWER_V2_0_MODEL_MODEL_H_
#define SRC_3DVIEWER_V2_0_MODEL_MODEL_H_

#include "data.h"
#include "affinitytransformation.h"
#include "preparingdataforrender.h"

namespace s21 {
class Model {
 public:
    Model();
    ~Model();

    std::string openFile(std::string);
    void move(double x, double y, double z);
    void rotate(double x, double y, double z);
    void scale(double x);
    void sendIndexesToOpenGL(QOpenGLBuffer *indexBuf, GLuint *countEdges);
    void sendVertexToOpenGL(QOpenGLBuffer *arrayBuf);
    size_t getCountFacets();
    int getCountDots();
    void centeringPicture();

 private:
    Data* data;
    AffinityTransformation* afinTransform;
    PreparingDataForRender* preparingData;
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_MODEL_MODEL_H_
