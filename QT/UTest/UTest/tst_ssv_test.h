#ifndef TST_SSV_TEST_H
#define TST_SSV_TEST_H

#include <QCoreApplication>
#include <QtTest>
#include "testsuit.h"

// add necessary includes here


class SSV_TEST : public TestSuite
{
    Q_OBJECT

public:
    SSV_TEST();
    ~SSV_TEST();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};




#endif // TST_SSV_TEST_H
