//
// Created by ANDREI on 25-May-24.
//

#include "GUI.h"



GUI::GUI(Repository &repo) : repo{repo}{
    this->build_GUI();
    this->populate_list(this->repo.get_list());

    QObject::connect(this->filterbox, &QCheckBox::clicked, this, &GUI::checkboxhandler);
    QObject::connect(this->calculatesumbutton, &QPushButton::clicked, this, &GUI::sumbuttonhandler);

    QObject::connect(this->billslist, &QListWidget::itemClicked, this, &GUI::clickeditemhandler);
    this->error = new QErrorMessage;
}

void GUI::build_GUI() {
    auto mainlayout = new QGridLayout{this};

    this->billslist = new QListWidget{};
    mainlayout->addWidget(this->billslist, 0, 0);
    this->filterbox = new QCheckBox{"Filter paid/unpaid"};
    mainlayout->addWidget(this->filterbox, 1, 0);

    this->nameline = new QLineEdit{"Company name"};
    mainlayout->addWidget(this->nameline, 2, 0);

    this->calculatesumbutton = new QPushButton{"Calculate Total Sum"};
    mainlayout->addWidget(this->calculatesumbutton, 3, 0);

    this->totalsum = new QLineEdit{"Total sum"};
    mainlayout->addWidget(this->totalsum, 4, 0);

}

void GUI::populate_list(std::vector<Bill> v) {
    int index = 0;
    this->billslist->clear();
    for (auto b : v) {
        this->billslist->addItem(QString::fromStdString(b.get_name()) + "," + QString::fromStdString(b.get_serial()) +
                                 "," + QString::fromStdString(std::to_string(b.get_sum())));
        if (!b.check_paid()) {
            this->billslist->item(index)->setBackground(Qt::red);
        }
        index++;
    }
}

void GUI::sumbuttonhandler() {
    double sum = 0;
    std::string name;
    QString text = this->nameline->text();
    name = text.toStdString();
    std::vector<Bill> list = this->repo.filter_by_name(name);
    for (auto b : list){
        if (!b.check_paid())
            sum += b.get_sum();
    }
    if (list.empty())
        this->error->showMessage("Invalid company name");
    else
        this->totalsum->setText(QString::fromStdString(std::to_string(sum)));
}

void GUI::checkboxhandler() {
    if (this->filterbox->isChecked()){
        this->populate_list(this->repo.filter_paid().second);
    }
    else
        this->populate_list(this->repo.filter_paid().first);
}

void GUI::clickeditemhandler(QListWidgetItem *clickeditem) {
    auto index = this->billslist->indexFromItem(clickeditem).row();
    auto bill = this->repo.get_list()[index];
    this->nameline->setText(QString::fromStdString(bill.get_name()));

}

