//
// Created by Adi on 5/23/2024.
//
#include <QPainter>
#include "cosGUI2.h"
#include <random>
#include <QPixmap>

void CosCRUDGUI::initGUI() {

    lyMain = new QVBoxLayout;
    setLayout(lyMain);

    table = new QTableView;
    lyMain->addWidget(table);

    QWidget* randomWid = new QWidget;
    QHBoxLayout* lyRandomWid = new QHBoxLayout;
    randomWid->setLayout(lyRandomWid);
    lyMain->addWidget(randomWid);
    QFormLayout* lyRandomForm = new QFormLayout;
    lyRandomWid->addLayout(lyRandomForm);
    txtRandom = new QLineEdit;
    lyRandomForm->addRow("Locatari", txtRandom);
    btnRandom = new QPushButton{"Random"};
    lyRandomWid->addWidget(btnRandom);

    btnGolire = new QPushButton{"Golire"};
    lyMain->addWidget(btnGolire);
}

void CosCRUDGUI::connectSignalSlots() {
    notif.addObserver(this);

    QAction::connect(btnRandom, &QPushButton::clicked, [&](){
        bool eroare;
        int nr = txtRandom->text().toInt(&eroare);
        if (!eroare || nr < 0)
        {
            QMessageBox::warning(this, "atentie!", "Trebuie sa introduci un numar natural!");
            return;
        }
        notif.generate(nr);
    });

    QAction::connect(btnGolire, &QPushButton::clicked, [&](){
        notif.clearList();
    });
}

void CosCRUDGUI::reloadTable(vector<Locatar> locatari) {
    model->setLocatari(locatari);
}

void CosReadOnlyGUI::paintEvent(QPaintEvent *ev) {
    QPainter p{this};
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<> x(0, width());
    std::uniform_int_distribution<> y(0, height());

    int randX;
    int randY;
    for (int i = 1; i <= notif.size(); i ++)
    {
        randX = x(mt);
        randY = y(mt);
        p.drawImage(5, 5, QImage{"C:\\Users\\Adi\\CLionProjects\\OOP\\untitled1\\cmake-build-debug\\ghiocel.jpg"});
        if (i % 3 == 0)
            p.drawEllipse(randX, randY, 20, 30);
        else if (i % 3 == 1)
            p.drawLine(randX, randY, width(), height());
        else
            p.drawRect(randX, randY, 40, 60);
    }
}

void CosReadOnlyGUI::connectSignalSlots() {
    notif.addObserver(this);
}

void CosReadOnlyGUI::initGUI() {
    setFixedSize(800, 600);
}
