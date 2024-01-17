#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include "Common/CommManager/commmanager.h"
#include "Common/CommSerialPort/commserialport.h"
#include "Common/CommProtocol/commprotocol.h"
#include "Common/CommMultiTree/commmutitree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionConnect_triggered();
    void slotErroDone(CommProtocol::error_code_t erro);

private:
    Ui::MainWindow *ui;

private:

    void iniConnections();
    void iniCom();
    void iniUI();
    void iniCommManager();
    void on_comStatus(QString name, bool flag);
    void dataParse(const QString &name, const CommMessage &msg);

    CommSerialPort * m_pSerialPort = nullptr;
    Commmanager * m_pCommManager = nullptr;
    QComboBox * cBoxPort;

    commMutitree tTree;

    const QString m_comStart = "Start Connect";
    const QString m_comHand = "Start Hand";
    const QString m_comCacheDevice = "Start Send Cache Of Device";
    const QString m_comCacheParam = "Start Send Cache Of Parameters";
    const QString m_comCacheSpilt = "Start Send Cache Of Spilt Infomation";
    const QString m_comCacheParamLink = "Start Send Cache Of Linking-Parameters";
};
#endif // MAINWINDOW_H
