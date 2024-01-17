#include "protocoltest.h"
#include "Common/CommProtocol/commprotocol.h"
static ProtocolTest instance;

ProtocolTest::ProtocolTest(): TestSuite("Protocol Test")
{

}

ProtocolTest::~ProtocolTest()
{

}

void ProtocolTest::initTestCase()
{

}

void ProtocolTest::cleanupTestCase()
{

}

void ProtocolTest::TestPacketProcess()
{
    QFETCH(QVector<quint8>,data);

    CommMessage heart = {CommProtocol::WRITE, CommProtocol::CMD_TYPE_HEART, QVector<quint8>{0x24,0x24,0x24,0x24,0x24,0x24},
                         QVector<quint8>{}, QVector<quint8>{}, QVector<quint8>{}};
    CommMessage hand =  {CommProtocol::WRITE, CommProtocol::CMD_TYPE_HAND, QVector<quint8>{0x00,0x00,0x00,0x00,0x00,0x00},
                        QVector<quint8>{}, QVector<quint8>{}, QVector<quint8>{}};
    CommMessage cache = {CommProtocol::WRITE, CommProtocol::CMD_TYPE_CACHE,QVector<quint8>{},
                         QVector<quint8>{0x00,0x36},QVector<quint8>{0x00,0x00},QVector<quint8>{0x00,0x39}};

    CommProtocol::getInstance()->setDataBuf(data);
    CommProtocol::getInstance()->setWriteBuf(cache);

    QCOMPARE(CommProtocol::getInstance()->dataProcess(),true);
}

void ProtocolTest::TestPacketProcess_data()
{
    QTest::addColumn<QVector<quint8>>("data");
    //QTest::addColumn<CommMessage>("writebuf");

    QVector<quint8> dataBuf1 = {0x01};
    QVector<quint8> dataBuf2 = {0x01,0x00,0x00,0x23,0x33,0xAA,0xAA};
    QVector<quint8> dataBuf3 = {0x01,0x00,0x23,0x90,0x12,0x98,0x99,0x34,0x12};
    QVector<quint8> dataBuf4 = {0xAA};
    QVector<quint8> dataBuf5 = {0x2A,0x00,0x12,0x00,0x00,0x00,0x00,0x00,0x12};
    QVector<quint8> dataBuf6 = {0x2A, 0x01, 0x05, 0x31, 0x32, 0x31, 0x32, 0x50, 0x2D, 0x32, 0x35, 0x30, 0x32,
                                0x00, 0x00, 0x35, 0x31, 0x33, 0x34, 0x31, 0x39, 0x00, 0x00, 0x47, 0x65,
                                0x6E, 0x65, 0x72, 0x69, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                0x00, 0x00, 0x00, 0x02, 0x00, 0x36, 0x00, 0x02, 0x00, 0x02, 0x08, 0x59,
                                0x00, 0x05, 0x00, 0x48, 0x06, 0xF0, 0x07, 0xE6};
    QTest::addRow("data1")<< dataBuf1 ;
    QTest::addRow("data2")<< dataBuf2 ;
    QTest::addRow("data3")<< dataBuf3 ;
    QTest::addRow("data4")<< dataBuf4 ;
    QTest::addRow("data5")<< dataBuf5 ;
    QTest::addRow("data6")<< dataBuf6 ;
}
