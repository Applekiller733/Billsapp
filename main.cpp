#include <iostream>
#include <QApplication>
#include <Qt>
#include <QtCore>
#include <QWidget>
#include "GUI/GUI.h"
#include "Repository/Repository.h"

int main(int argc, char* argv[]) {

    Repository repo{"bills.csv"};
    QApplication app(argc, argv);
    app.setApplicationName("Bills");
    app.setStyle("fusion");
    GUI gui{repo};
    gui.show();

    return app.exec();
}
