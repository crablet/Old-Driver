#include "src/CommonUi/StartPageWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	StartPageWindow w;
    w.show();

    return a.exec();
}
