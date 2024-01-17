QT       += core gui
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common/CommManager/commmanager.cpp \
    Common/CommMessage/commmessage.cpp \
    Common/CommMultiTree/commmutitree.cpp \
    Common/CommProtocol/commprotocol.cpp \
    Common/CommSerialPort/commserialport.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Common/CommManager/commmanager.h \
    Common/CommMessage/commmessage.h \
    Common/CommMultiTree/commmutitree.h \
    Common/CommProtocol/commprotocol.h \
    Common/CommSerialPort/commserialport.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
