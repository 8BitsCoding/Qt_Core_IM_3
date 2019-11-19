#include <QtCore/QCoreApplication>

// The QScopedPointer class stores a pointer to a dynamically allocated object,
// and deletes it upon destruction!!!

#include <qdebug.h>
#include <qscopedpointer.h>

#include "test.h"

void useit(test* obj) {
	if (!obj) return;

	qInfo() << "Using" << obj;
}

void doStuff() {
	//test* t = new test();			// dangling(�޶��޶�) pointer!!!
	QScopedPointer<test> mypointer(new test());

	//�̷��� �����͸� ���� �� �ִ�.
	useit(mypointer.data());		

	// pointer is automatically deleted!!
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	for (int i = 0; i < 100; i++) {
		doStuff();
	}

	return a.exec();
}
