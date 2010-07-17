#-------------------------------------------------
#
# Project created by QtCreator 2010-07-16T10:34:25
#
#-------------------------------------------------

QT       += core gui

TARGET = PhoneCallWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    activeobjectwrapper.cpp \
    activeobjectwrapperprivate.cpp

HEADERS  += widget.h \
    activeobjectwrapper.h \
    activeobjectwrapperprivate.h

FORMS    += widget.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe738ee40
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000

    symbian:TARGET.CAPABILITY = NetworkServices

    INCLUDEPATH += C:/NokiaQtSDK/Symbian/SDK/epoc32/include

    LIBS += -LC:/NokiaQtSDK/Symbian/SDK_OK/epoc32/release/armv5/lib
    LIBS += -lcone \
    -leikcore \
    -lavkon
}
