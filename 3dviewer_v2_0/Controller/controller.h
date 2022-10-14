#ifndef SRC_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#define SRC_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#include "../Model/model.h"
#include <QOpenGLBuffer>
namespace s21 {
class Controller {
 public:
    Controller();
    void move(double x, double y, double z);
    void rotate(double x, double y, double z);
    void scale(double x);
    std::string viewNewPicture(std::string filename);
    void sendIndexesToOpenGL(QOpenGLBuffer *indexBuf, GLuint *countEdges);
    void sendVertexToOpenGL(QOpenGLBuffer *arrayBuf);
    size_t getCountFacets();
    int getCountDots();
    void centeringPicture();

    ~Controller();

 private:
    Model *model;
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
