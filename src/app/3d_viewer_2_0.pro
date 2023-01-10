QT       += core gui widgets opengl openglwidgets
include(QtGifImage/src/gifimage/qtgifimage.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += core gui widgets opengl

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    model/storage.cpp \
    controller/facade.cpp \
    view/glwidget.cpp \
    main.cpp \
    view/mainwindow.cpp \
    view/viewsettings.cpp

HEADERS += \
    model/storage.h \
    controller/facade.h \
    view/glwidget.h \
    view/mainwindow.h \
    view/viewsettings.h

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

