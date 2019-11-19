#include "test.h"

#include <qdebug.h>

test::test(QObject* parent) : QObject(parent)
{
	qInfo() << "test class Created!" << endl;
}

test::~test()
{
	qInfo() << "test class destructed!" << endl;
}
