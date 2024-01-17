#include <QtTest/QtTest>
#include <QCoreApplication>
#include "testsuit.h"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "found:" << TestSuite::testList().size() << "test suite";

    //记录测试失败的数量
    int failedTestsCount = 0;
    for(TestSuite* test : TestSuite::testList()){
        int res = QTest::qExec(test, argc, argv);

        if (res) {
            failedTestsCount ++;
        }
    }
    qDebug() << "Test suite complete:" << failedTestsCount << "failures detected.";

    return 0;//app.exec(); // 运行应用程序事件循环

}
