#include "controller.h"

s21::Controller::Controller() {
    model = new Model;
}

s21::Controller::~Controller() {
    delete model;
}

void s21::Controller::move(double x, double y, double z) {
    model->move(x, y, z);
}

void s21::Controller::rotate(double x, double y, double z) {
    model->rotate(x, y, z);
}

void s21::Controller::scale(double x) {
    model->scale(x);
}

std::string s21::Controller::viewNewPicture(std::string filename) {
    return model->openFile(filename);
}

void s21::Controller::sendIndexesToOpenGL(QOpenGLBuffer *indexBuf, GLuint *countEdges) {
    model->sendIndexesToOpenGL(indexBuf, countEdges);
}

void s21::Controller::sendVertexToOpenGL(QOpenGLBuffer *arrayBuf) {
    model->sendVertexToOpenGL(arrayBuf);
}

size_t s21::Controller::getCountFacets() {
    return model->getCountFacets();
}

int s21::Controller::getCountDots() {
    return model->getCountDots();
}

void s21::Controller::centeringPicture() {
    model->centeringPicture();
}
