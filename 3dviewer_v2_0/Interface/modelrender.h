#ifndef SRC_3DVIEWER_V2_0_INTERFACE_MODELRENDER_H_
#define SRC_3DVIEWER_V2_0_INTERFACE_MODELRENDER_H_

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QVector2D>
#include <QVector3D>
#include <QtOpenGL/QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include "../Controller/controller.h"
#include "../Settings/settings.h"

namespace s21 {
class ModelRender : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

 public:
    ModelRender(QWidget *parent, Controller* controller);
    ~ModelRender();
    void initGeo();

 protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

 private:
    struct VertexData {
        QVector3D position;
        QVector3D texCoord;
    };
    QMatrix4x4 projection;
    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    QOpenGLShaderProgram shProgram;
    Controller* controller_;
    GLuint countEdges_;
    Settings *settings = &(Settings::Instance());

    void initShaders();
    void initTextures();
    void initCubeGeometry();
};
}  // namespace s21
#endif  // SRC_3DVIEWER_V2_0_INTERFACE_MODELRENDER_H_
