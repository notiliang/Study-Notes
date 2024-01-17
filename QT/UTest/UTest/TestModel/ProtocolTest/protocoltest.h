#ifndef PROTOCOLTEST_H
#define PROTOCOLTEST_H

#include <QCoreApplication>
#include <QtTest>
#include "Common/CommMessage/commmessage.h"
#include "UTest/testsuit.h"

class ProtocolTest : public TestSuite
{
    Q_OBJECT
public:
    ProtocolTest();
    ~ProtocolTest();

private slots:
    void initTestCase();

    void cleanupTestCase();

    void TestPacketProcess();
    void TestPacketProcess_data();

private:
    CommMessage m_readBuf;
    QVector<quint8> m_dataBuf;
};

#endif // PROTOCOLTEST_H
