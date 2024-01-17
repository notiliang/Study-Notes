#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Common/CommManager/commmanager.h"
#include "Common/CommProtocol/commprotocol.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();
    iniCom();
    iniConnections();
    iniCommManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniConnections()
{
    connect(Commmanager::getInstance(), &Commmanager::comStatus, this, &MainWindow::on_comStatus);
    connect(CommProtocol::getInstance(), &CommProtocol::dataParse,this,&MainWindow::dataParse);
    connect(CommProtocol::getInstance(), &CommProtocol::signalError, this, &MainWindow::slotErroDone);
}

void MainWindow::iniCom()
{
    m_pSerialPort = CommSerialPort::getInstance();
    m_pCommManager = Commmanager::getInstance();
    m_pCommManager->setHWND((HWND)this->winId());//设置串口句柄过滤事件
    cBoxPort->addItems(Commmanager::getAvailablePort());
    m_pSerialPort->selectSerialPort(cBoxPort->currentText());
}

void MainWindow::iniUI()
{
    cBoxPort = new QComboBox(this);
    ui->toolBar->addWidget(cBoxPort);
}

void MainWindow::iniCommManager()
{
    CommMessage msg;

    if (!m_pCommManager->createCom(m_comStart)){
        return;
    }
    else {
        msg = {CommProtocol::WRITE, CommProtocol::CMD_TYPE_HEART, QVector<quint8>{0x24,0x24,0x24,0x24,0x24,0x24},
               QVector<quint8>{}, QVector<quint8>{}, QVector<quint8>{}};
        m_pCommManager->setCom(m_comStart,msg);
    }

    if (!m_pCommManager->createCom(m_comHand)){
        return;
    }
    else {
        msg = {CommProtocol::WRITE, CommProtocol::CMD_TYPE_HAND, QVector<quint8>{0x00,0x00,0x00,0x00,0x00,0x00},
               QVector<quint8>{}, QVector<quint8>{}, QVector<quint8>{}};
        m_pCommManager->setCom(m_comHand,msg);
    }

    if (!m_pCommManager->createCom(m_comCacheDevice)){
        return;
    }
    else {
        msg = {CommProtocol::WRITE, CommProtocol::CMD_TYPE_CACHE,QVector<quint8>{},
               QVector<quint8>{0x00,0x36},QVector<quint8>{0x00,0x00},QVector<quint8>{0x00,0x39}};
        m_pCommManager->setCom(m_comCacheDevice,msg);
    }

    if (!m_pCommManager->createCom(m_comCacheParam)){
        return;
    }
    else {

    }

    if (!m_pCommManager->createCom(m_comCacheSpilt)){
        return;
    }
    else {

    }

    if (!m_pCommManager->createCom(m_comCacheParamLink)){
        return;
    }
    else {

    }

}

void MainWindow::on_comStatus(QString name, bool flag)
{
    if(flag)
    {
        qDebug() << name << "检测到设备插入";
        cBoxPort->addItem(name);
        m_pSerialPort->setPortName(cBoxPort->currentText());
    }
    else
    {
        qDebug() << name <<"检测到设备拔出" ;
        cBoxPort->removeItem(cBoxPort->findText(name));
    }
}

void MainWindow::dataParse(const QString &name, const CommMessage &msg)
{

    CommMessage msgOfParam;
    CommMessage msgOfSpilt;
    CommMessage msgOfLinkParam;
    quint16 sum = 0;
    quint16 spiltOffSet = 0;
    quint16 spiltSum = 0;
    quint16 linkOffSet = 0;
    quint16 linkSum = 0;

    if (msg.dataType() != CommProtocol::READ){
        return;
    }

    else {
        if (name == m_comStart){
            if (msg.data().at(0) == 0xAA){
                m_pCommManager->startCom(m_comHand);
            }
            else {

            }
        }

        else if (name == m_comHand) {
            m_pCommManager->startCom(m_comCacheDevice);
        }

        else if (name == m_comCacheDevice) {

            /*---cache of param---*/
            //计算cache of param 指令的和校验
            sum = CommProtocol::CMD_TYPE_CACHE + msg.data().at(46) + msg.data().at(47) + 0x3A;
            msgOfParam.setDataType(CommProtocol::WRITE);
            msgOfParam.setCmdType(CommProtocol::CMD_TYPE_CACHE);
            msgOfParam.setDataLength({msg.data().at(46),msg.data().at(47)});
            msgOfParam.setParamAddr({0x00,0x3A});
            msgOfParam.setCrcVal({static_cast<quint8>(sum>>8),static_cast<quint8>(sum&0xFF)});
            /*---cache of spilt---*/
            msgOfSpilt.setDataType(CommProtocol::WRITE);
            msgOfSpilt.setCmdType(CommProtocol::CMD_TYPE_CACHE);
            msgOfSpilt.setDataLength({msg.data().at(48),msg.data().at(49)});
            spiltOffSet = CommProtocol::getInstance()->paramCacheSum() + 0x3A;
            spiltSum = CommProtocol::CMD_TYPE_CACHE + (spiltOffSet>>8) + (spiltOffSet&0xFF) + msg.data().at(48) + msg.data().at(49);
            msgOfSpilt.setParamAddr({static_cast<quint8>(spiltOffSet>>8),static_cast<quint8>(spiltOffSet&0xFF)});
            msgOfSpilt.setCrcVal({static_cast<quint8>(spiltSum>>8),static_cast<quint8>(spiltSum&0xFF)});
            m_pCommManager->setCom(m_comCacheSpilt,msgOfSpilt);
            /*---cache of Linking-Parameters---*/
            msgOfLinkParam.setDataType(CommProtocol::WRITE);
            msgOfLinkParam.setCmdType(CommProtocol::CMD_TYPE_CACHE);
            msgOfLinkParam.setDataLength({msg.data().at(50),msg.data().at(51)});
            linkOffSet = spiltOffSet + CommProtocol::getInstance()->spiltCacheSum();
            linkSum = CommProtocol::CMD_TYPE_CACHE + (linkOffSet>>8) + (linkOffSet&0xFF) + msg.data().at(50) + msg.data().at(51);
            msgOfLinkParam.setParamAddr({static_cast<quint8>(linkOffSet>>8),static_cast<quint8>(linkOffSet&0xFF)});
            msgOfLinkParam.setCrcVal({static_cast<quint8>(linkSum>>8),static_cast<quint8>(linkSum&0xFF)});
            m_pCommManager->setCom(m_comCacheSpilt,msgOfLinkParam);

            m_pCommManager->setCom(m_comCacheParam,msgOfParam);
            m_pCommManager->startCom(m_comCacheParam);

        }

        else if (name == m_comCacheParam) {

            m_pCommManager->startCom(m_comCacheSpilt);
        }

        else if (name == m_comCacheSpilt) {
            m_pCommManager->startCom(m_comCacheParamLink);
        }

        else {

        }


    }
}


void MainWindow::on_actionConnect_triggered()
{
    m_pSerialPort->configSerialPort(9600,CommSerialPort::Data8,CommSerialPort::NoParity,
                                    CommSerialPort::OneStop,CommSerialPort::NoFlowControl);
    m_pSerialPort->openSerialPort();

    m_pCommManager->startCom(m_comStart);
}

void MainWindow::slotErroDone(CommProtocol::error_code_t erro)
{
    if (erro == CommProtocol::ERRO_TIMEOUT) {

    }
    else if (erro == CommProtocol::ERRO_RESPONSE) {

    }
    else if (erro == CommProtocol::ERRO_PARAMCACHE) {

    }
    else if (erro == CommProtocol::ERRO_CALSUM) {

    }
    else {

    }
}

