//
// Created by ANDREI on 25-May-24.
//

#ifndef TEST3EX_GUI_H
#define TEST3EX_GUI_H
#include "Repository/Repository.h"
#include <QApplication>
#include <QtCore>
#include <QtWidgets>

class GUI : public QWidget{
private:
    Repository& repo;

    QListWidget* billslist{};

    QCheckBox* filterbox;

    QLineEdit* nameline;

    QPushButton* calculatesumbutton;

    QLineEdit* totalsum;

    QErrorMessage* error;
public:

    GUI(Repository& repo);
    void build_GUI();
    void populate_list(std::vector<Bill> v);

    void checkboxhandler();
    void sumbuttonhandler();
    void clickeditemhandler(QListWidgetItem* clickeditem);
};


#endif //TEST3EX_GUI_H
