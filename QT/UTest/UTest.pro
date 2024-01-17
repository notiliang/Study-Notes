QT += testlib
QT += gui
QT += serialport
CONFIG += qt warn_on depend_includepath testcase
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app

SOURCES +=  UTest/tst_ssv_test.cpp \
    Common/CommMultiTree/commmutitree.cpp \
    UTest/TestModel/MultitreeTest/multitreetest.cpp \
    UTest/TestModel/ProtocolTest/protocoltest.cpp \
    Common/CommManager/commmanager.cpp \
    Common/CommMessage/commmessage.cpp \
    Common/CommProtocol/commprotocol.cpp \
    Common/CommSerialPort/commserialport.cpp \
    UTest/main.cpp \
    UTest/testsuit.cpp

HEADERS += \
    Common/CommMultiTree/commmutitree.h \
    UTest/TestModel/MultitreeTest/multitreetest.h \
    UTest/TestModel/ProtocolTest/protocoltest.h \
    UTest/testsuit.h \
    Common/CommManager/commmanager.h \
    Common/CommMessage/commmessage.h \
    Common/CommProtocol/commprotocol.h \
    Common/CommSerialPort/commserialport.h \
    UTest/tst_ssv_test.h

