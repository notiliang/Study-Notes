//test-suite.cpp
#include "testsuit.h"
#include <QDebug>


TestSuite::TestSuite(const QString& _testName)
    : QObject()
    , testName(_testName)
{
    //只要测试用例创建就会被添加到静态容器中
    qDebug() << "create test:" << testName;
    testList().push_back(this);
    qDebug() << testList().size() << "test added";
}

TestSuite::~TestSuite()
{
    qDebug() << "destory test:" << testName;
}

std::vector<TestSuite*>& TestSuite::testList()
{
    static std::vector<TestSuite*> instance = std::vector<TestSuite*>();
    return instance;
}

