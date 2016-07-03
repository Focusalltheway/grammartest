TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
#CONFIG+=qt
#CONFIG -= qt

SOURCES += main.cpp \
    classtest.cpp

include(deployment.pri)
qtcAddDeployment()

