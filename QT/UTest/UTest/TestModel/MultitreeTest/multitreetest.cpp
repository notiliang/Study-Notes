#include "multitreetest.h"

static MultitreeTest instance;

MultitreeTest::MultitreeTest()
    : TestSuite("Multitree Test")
    ,m_pTestTree{new commMutitree}
{

}

MultitreeTest::~MultitreeTest()
{
    delete m_pTestTree;
}

void MultitreeTest::initTestCase()
{

}

void MultitreeTest::cleanupTestCase()
{

}
