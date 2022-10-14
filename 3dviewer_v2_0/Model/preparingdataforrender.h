#ifndef SRC_3DVIEWER_V2_0_MODEL_PREPARINGDATAFORRENDER_H_
#define SRC_3DVIEWER_V2_0_MODEL_PREPARINGDATAFORRENDER_H_

#include "data.h"
#include "../Settings/settings.h"

#include <QtOpenGL/QOpenGLBuffer>
#include <QVector3D>

namespace s21 {
class PreparingDataForRender {
 public:
    explicit PreparingDataForRender(Data* picture);

    void sendIndexesToOpenGL(QOpenGLBuffer *indexBuf, GLuint *countEdges);
    void sendVertcesToOpenGL(QOpenGLBuffer *arrayBuf);
    void updatePicture(Data *picture);
 private:
    struct VertexData {
        QVector3D position;
        QVector3D texCoord;
    };
    Data* picture_;
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_MODEL_PREPARINGDATAFORRENDER_H_
