QT       += core gui opengl openglwidgets

win32 {
    LIBS += -lopengl32 -lglu32
}
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller.cpp \
    Interface/clicks.cpp \
    Interface/gifCreate.cpp \
    Interface/interface.cpp \
    Interface/modelrender.cpp \
    Model/affinitytransformation.cpp \
    Model/data.cpp \
    Model/model.cpp \
    Model/preparingdataforrender.cpp \
    Settings/settings.cpp \
    gif/3rdParty/giflib/dgif_lib.c \
    gif/3rdParty/giflib/egif_lib.c \
    gif/3rdParty/giflib/gif_err.c \
    gif/3rdParty/giflib/gif_font.c \
    gif/3rdParty/giflib/gif_hash.c \
    gif/3rdParty/giflib/gifalloc.c \
    gif/3rdParty/giflib/quantize.c \
    gif/gifimage/qgifimage.cpp \
    main.cpp \

HEADERS += \
    Controller/controller.h \
    Interface/clicks.h \
    Interface/gifCreate.h \
    Interface/interface.h \
    Interface/modelrender.h \
    Model/affinitytransformation.h \
    Model/data.h \
    Model/model.h \
    Model/preparingdataforrender.h \
    Settings/settings.h \
    gif/3rdParty/giflib/gif_hash.h \
    gif/3rdParty/giflib/gif_lib.h \
    gif/3rdParty/giflib/gif_lib_private.h \
    gif/gifimage/qgifglobal.h \
    gif/gifimage/qgifimage.h \
    gif/gifimage/qgifimage_p.h

FORMS += \
    Interface/interface.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Interface/shaders.qrc
