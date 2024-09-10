//
// Created by Adi on 5/23/2024.
//

#pragma once
#include "observer.h"
#include "service.h"
#include <QTableWidget>
#include <QAction>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include "MyTableModel.h"

class CosCRUDGUI: public QWidget, public Observer{
private:

    QVBoxLayout* lyMain;
    QTableView* table;
    MyTableModel* model;
    QPushButton* btnRandom;
    QPushButton* btnGolire;
    QLineEdit* txtRandom;

    notificationList& notif;
    void initGUI();
    void connectSignalSlots();
    void reloadTable(vector<Locatar> locatari);

public:
    CosCRUDGUI(notificationList& notif): notif{notif}{
        initGUI();
        model = new MyTableModel{notif.getList()};
        table->setModel(model);
        setAttribute(Qt::WA_DeleteOnClose); //daca vreau sa se distruga fereastra imediat dupa inchidere
        connectSignalSlots();
    }

    void update() override{
        reloadTable(notif.getList());
    }

    ~CosCRUDGUI(){
        notif.removeObserver(this);
    }
};

class CosReadOnlyGUI: public QWidget, public Observer{
private:
    notificationList& notif;
    void initGUI();
    void connectSignalSlots();
public:
    CosReadOnlyGUI(notificationList& notif): notif{notif} {
        initGUI();
        setAttribute(Qt::WA_DeleteOnClose); //daca vreau sa se distruga fereastra imediat dupa inchidere
        connectSignalSlots();
    }

    void update() override{
        repaint();
    }

    void paintEvent(QPaintEvent* ev) override;

    ~CosReadOnlyGUI(){
        notif.removeObserver(this);
    }
};
