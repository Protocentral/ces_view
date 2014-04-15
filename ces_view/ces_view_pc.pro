TEMPLATE = app
CONFIG += console
QT += gui
QT += widgets
QT += serialport
OBJECTS_DIR = obj
MOC_DIR = moc

DESTDIR = bin
TARGET  = ces_view

INCLUDEPATH  += ../qwt-6.1/src \

QMAKE_LIBDIR += ../qwt-6.1/lib

QMAKE_LFLAGS += -static-libgcc

HEADERS += data_plot.h \
    ces_view.h \
    serialcontrol.h \
    ces_cmdif.h \
    mtqueue.h \
    mtqueue.h
SOURCES += main.cpp \
           data_plot.cpp \
    ces_view.cpp \
    serialcontrol.cpp

win32 {
    LIBS += -lsetupapi -luuid -ladvapi32 -lqwt
}
unix:!macx {
    LIBS += -ludev -lqwt
}
