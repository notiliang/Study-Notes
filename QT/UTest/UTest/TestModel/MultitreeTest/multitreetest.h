#ifndef MULTITREETEST_H
#define MULTITREETEST_H

#include <QCoreApplication>
#include <QtTest>

#include "UTest/testsuit.h"
#include "Common/CommMultiTree/commmutitree.h"

class MultitreeTest : public TestSuite
{
    Q_OBJECT
public:
    MultitreeTest();
    ~MultitreeTest();

private slots:
    void initTestCase();

    void cleanupTestCase();

private:
    commMutitree * m_pTestTree = nullptr;
};

#endif // MULTITREETEST_H
