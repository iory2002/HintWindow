#include "HintWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HintWindow w;
	w.show();
	return a.exec();
}
