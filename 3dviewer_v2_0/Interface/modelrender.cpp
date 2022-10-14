#include "modelrender.h"

s21::ModelRender::ModelRender(QWidget *parent, Controller *controller)
    : QOpenGLWidget(parent), indexBuf(QOpenGLBuffer::IndexBuffer), controller_(controller) {
    countEdges_ = 0;
}

s21::ModelRender::~ModelRender() {
    arrayBuf.destroy();
    indexBuf.destroy();
}

void s21::ModelRender::initializeGL() {
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    arrayBuf.create();
    indexBuf.create();
    initShaders();
    initCubeGeometry();
}

void s21::ModelRender::resizeGL(int w, int h) {
    qreal aspect = qreal(w) / qreal(h ? h : 1);
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;
    projection.setToIdentity();
    if (!controller_->getCountDots() || settings->ProectionType()) {
        projection.perspective(fov, aspect, zNear, zFar);
    } else {
        projection.ortho(-2.0f, 2.0f, -2.0f, 2.0f, -10.0f, 8.0f);
    }
}

void s21::ModelRender::paintGL() {
    glClearColor(settings->BackgroundColor()[0],
                 settings->BackgroundColor()[1],
                 settings->BackgroundColor()[2], 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 matrix;
    matrix.translate(0.0, 0.0, -5.0);
    QMatrix4x4 *qq = new QMatrix4x4(projection * matrix);
    if (qq != nullptr) {
        shProgram.setUniformValue("mvp_matrix", *qq);
        shProgram.setUniformValue("isDotsDraw", false);

        arrayBuf.bind();
        indexBuf.bind();

        quintptr offset = 0;

        int vertexLocation = shProgram.attributeLocation("a_position");
        shProgram.enableAttributeArray(vertexLocation);
        shProgram.setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));
        offset += sizeof(QVector3D);
        int texcoordLocation = shProgram.attributeLocation("a_texcoord");
        shProgram.enableAttributeArray(texcoordLocation);
        shProgram.setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 3, sizeof(VertexData));
        if (settings->FacetType() == 1) {
            glEnable(GL_LINE_STIPPLE);
            glLineStipple(1, 0x0101);
        } else {
            glDisable(GL_LINE_STIPPLE);
        }

        glLineWidth(settings->FacetSize());
        glDrawElements(GL_LINES, countEdges_, GL_UNSIGNED_INT, nullptr);
        if (settings->DotType() != 0) {
            shProgram.setUniformValue("isDotsDraw", true);
            shProgram.setUniformValue("a_texcoord", QVector4D(settings->DotColor()[0],
                                      settings->DotColor()[1],
                    settings->DotColor()[2], 1.0));
            if (settings->DotType() == 1) {
                glEnable(GL_POINT_SMOOTH);
            } else {
                glDisable(GL_POINT_SMOOTH);
            }
            glPointSize(settings->DotSize());
            glDrawElements(GL_POINTS, countEdges_, GL_UNSIGNED_INT, nullptr);
        }
        delete qq;
    }
//    std::cout << "edges " << countEdges_ << "  dots " << controller_->getCountDots() << std::endl;
}

void s21::ModelRender::initShaders() {
    if (!shProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
        close();

    if (!shProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl"))
        close();

    if (!shProgram.link())
        close();

    if (!shProgram.bind())
        close();
}

void s21::ModelRender::initCubeGeometry() {
    VertexData vertices[] = {
        {QVector3D(.0f, 1.0f,  .0f), QVector3D(0.5, 0.7, 0.33)},
        {QVector3D(-1.0f, -1.0f, 1.), QVector3D(0.33, 1., 1.)},
        {QVector3D(1.0f, -1.0f, 1.), QVector3D(0., 0.5, 1.)},
        {QVector3D(1.0f, -1.0f, -1.), QVector3D(0.66, .0, 1.)},
        {QVector3D(-1.0f, -1.0f, -1.), QVector3D(0.0, 0.66, .33)}
    };

    GLuint indices[] = {
        0, 1, 1, 2, 2, 0,
        0, 2, 2, 3, 3, 0,
        0, 3, 3, 4, 4, 0,
        0, 4, 4, 1, 1, 0,
        1, 2, 2, 3, 3, 4, 4, 1
    };
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 5 * sizeof(VertexData));

    indexBuf.bind();
    indexBuf.allocate(indices, 32 * sizeof(GLuint));
    countEdges_ = 32;
}

void s21::ModelRender::initGeo() {
    if (controller_->getCountDots()) {
        controller_->sendIndexesToOpenGL(&indexBuf, &countEdges_);
        controller_->sendVertexToOpenGL(&arrayBuf);
    }
    resizeGL(this->width(), this->height());
    update();
}
