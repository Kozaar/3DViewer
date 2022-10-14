#include "preparingdataforrender.h"
#include <vector>

s21::PreparingDataForRender::PreparingDataForRender(Data *picture) {
    updatePicture(picture);
}

void s21::PreparingDataForRender::sendIndexesToOpenGL(QOpenGLBuffer *indexBuf, GLuint *countEdges) {
    std::vector<std::vector<int>> *facies = picture_->setFacets();
    GLuint *indices = new GLuint[facies->size()*20];
    GLuint n = 0;
    for (size_t i = 0; i < facies->size(); i++) {
        indices[n] = facies->data()[i][0] - 1;
        n++;
        for (size_t j = 1; j < facies->data()[i].size(); j++) {
            indices[n] = facies->data()[i][j] - 1;
            n++;
            indices[n] = facies->data()[i][j] - 1;
            n++;
        }
        indices[n] = facies->data()[i][0] - 1;
        n++;
    }
    indexBuf->bind();
    indexBuf->allocate(indices, n * sizeof(GLuint));
    *countEdges = n;
    delete[] indices;
}

void s21::PreparingDataForRender::sendVertcesToOpenGL(QOpenGLBuffer *arrayBuf) {
    std::vector<std::vector<double>> *dots = picture_->setDots();
    VertexData *vertices = new VertexData[dots->size()];
    for (size_t i = 0; i < dots->size(); i++) {
        vertices[i] = {QVector3D(dots->data()[i][0],
                                 dots->data()[i][1],
                                 dots->data()[i][2]),
                       QVector3D(Settings::Instance().FacetColor()[0],
                                 Settings::Instance().FacetColor()[1],
                                 Settings::Instance().FacetColor()[2])};
    }
    arrayBuf->bind();
    arrayBuf->allocate(vertices, dots->size() * sizeof(VertexData));
    delete[] vertices;
}

void s21::PreparingDataForRender::updatePicture(Data *picture) {
    picture_ = picture;
}
