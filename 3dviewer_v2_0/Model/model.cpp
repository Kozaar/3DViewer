#include "model.h"

s21::Model::Model() {
    data = new Data;
    afinTransform = new AffinityTransformation;
    preparingData = new PreparingDataForRender(data);
}


s21::Model::~Model() {
    delete data;
    delete afinTransform;
    delete preparingData;
}


std::string s21::Model::openFile(std::string filename) {
    delete data;
    data = new Data(filename);
    afinTransform->update(data->setDots());
    preparingData->updatePicture(data);
    return data->filenameWithParametres();
}

void s21::Model::move(double x, double y, double z) {
    if (!x && !y && !z) {
    } else if (!y && !z) {
        afinTransform->movingX(x/10);
    } else if (!x && !z) {
        afinTransform->movingY(y/10);
    } else if (!x && !y) {
        afinTransform->movingZ(z/10);
    } else {
        afinTransform->moving(x/10, y/10, z/10);
    }
}

void s21::Model::rotate(double x, double y, double z) {
    if (!x && !y && !z) {
    } else if (!y && !z) {
        afinTransform->rotateX(x);
    } else if (!x && !z) {
        afinTransform->rotateY(y);
    } else if (!x && !y) {
        afinTransform->rotateZ(z);
    } else {
        afinTransform->rotate(x, y, z);
    }
}

void s21::Model::scale(const double x) {
    afinTransform->scale(x);
}

void s21::Model::sendIndexesToOpenGL(QOpenGLBuffer *indexBuf, GLuint *countEdges) {
    preparingData->sendIndexesToOpenGL(indexBuf, countEdges);
}

void s21::Model::sendVertexToOpenGL(QOpenGLBuffer *arrayBuf) {
    preparingData->sendVertcesToOpenGL(arrayBuf);
}

size_t s21::Model::getCountFacets() {
    return data->numberOfFacets();
}

int s21::Model::getCountDots() {
    return data->numberOfDots();
}

void s21::Model::centeringPicture() {
    afinTransform->centeringPicture();
}
