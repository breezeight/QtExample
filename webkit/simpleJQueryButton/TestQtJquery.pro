#-------------------------------------------------
#
# Project created by QtCreator 2010-07-10T13:27:30
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = TestQtJquery
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe1b7ccb1
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

symbian:TARGET.CAPABILITY = NetworkServices \
    ReadUserData \
    WriteUserData \
    LocalServices

RESOURCES += \
    res.qrc
