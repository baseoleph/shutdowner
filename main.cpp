#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //w.setWindowIcon(QIcon("shutdowner.ico"));
    //Set window in center of screen
    QDesktopWidget *desktop = QApplication::desktop();
    int x = (desktop->width() - w.width()) / 2;
    int y = (desktop->height() - w.height()) / 3;
    w.move(x, y);

    w.show();
    return a.exec();
}
