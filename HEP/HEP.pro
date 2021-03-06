#-------------------------------------------------
#
# Project created by QtCreator 2018-11-08T09:21:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HEP
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += c++14

SOURCES += \
        main.cpp \
    image_window.cpp \
    voltage_temperature_coordinate.cpp \
    coordinate.cpp \
    login_dialog.cpp \
    parameter_dialog.cpp \
    coordinate_service.cpp \
    access_point.cpp \
    temperature_coordinate.cpp \
    voltage_coordinate.cpp


HEADERS += \
    image_window.h \
    voltage_temperature_coordinate.h \
    temperature_coordinate.h \
    voltage_coordinate.h \
    coordinate.h \
    login_dialog.h \
    parameter_dialog.h \
    coordinate_service.h \
    access_point.h

FORMS += \
    image_window.ui \
    login_dialog.ui \
    parameter_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    photo.qrc
