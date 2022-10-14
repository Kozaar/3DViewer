#include "./Interface/interface.h"

#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);
    s21::Interface w;
    w.show();
    return a.exec();
}
