//testsuite.h
#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>
#include <QString>
#include <QtTest/QtTest>
#include <vector>


class TestSuite : public QObject
{
    Q_OBJECT
public:
    explicit TestSuite(const QString& _testName = "");
    virtual ~TestSuite();

    //测试用例的名称
    QString testName;
    //获取所有实例化的测试用例
    static std::vector<TestSuite*>& testList();
};



#endif
