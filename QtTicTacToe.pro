#-------------------------------------------------
#
# Project created by QtCreator 2017-12-25T23:42:51
#
#-------------------------------------------------

QT       += core gui

CONFIG  +=  c++11

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTicTacToe
TEMPLATE = app


SOURCES += main.cpp\
    spielfigur.cpp \
    x_spielfigur.cpp \
    o_spielfigur.cpp \
    tictactoe_mainwindow.cpp \
    frame_spielfeld.cpp

HEADERS  += \
    spielfigur.h \
    x_spielfigur.h \
    o_spielfigur.h \
    tictactoe_mainwindow.h \
    frame_spielfeld.h

FORMS    += \
    tictactoe_mainwindow.ui \
    frame_spielfeld.ui
