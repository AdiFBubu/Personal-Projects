//
// Created by Adi on 5/26/2024.
//

#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QAction>
#include <QListWidget>
#include <vector>
#include <QTableWidget>
#include "domain.h"
#include "service.h"
#include "MyTableModel.h"
#include <QTableView>
#include <QListView>
#include <QLabel>

using std::vector;

class LocatarGUIModele: public QWidget{
private:
    LocatariService& serv;

    MyTableModel* model;
    QListView* list;
    QTableView* table;

    QLabel* nrLocatari;

    QHBoxLayout* lyMain = new QHBoxLayout;

    QPushButton* btnGetAll;
    QPushButton* btnCautareAp;
    QLineEdit* txtCautareAp;
    QPushButton* btnSortByNameCresc;
    QPushButton* btnSortByNameDescresc;
    QPushButton* btnSortBySurfaceCresc;
    QPushButton* btnSortBySurfaceDescresc;
    QPushButton* btnSortByTypeAndSurfaceCresc;
    QPushButton* btnSortByTypeAndSurfaceDescresc;
    QPushButton* btnFilterByType;
    QLineEdit* txtFilterType;
    QPushButton* btnFilterBySurface;
    QLineEdit* txtFilterMinSurf;
    QLineEdit* txtFilterMaxSurf;
    QPushButton* btnUndo;
    QPushButton* btnAddCos;

    QLineEdit* txtAppartment;
    QLineEdit* txtName;
    QLineEdit* txtType;
    QLineEdit* txtSurface;
    QPushButton* btnAdd;
    QPushButton* btnDel;
    QPushButton* btnUpd;

    QPushButton* btnDelNotif;
    QPushButton* btnGenNotif;
    QLineEdit* txtGen;

    QWidget* dreapta;
    QVBoxLayout* lyDreapta;
    QPushButton* btnRaport;
    QPushButton* btnCosCRUD;
    QPushButton* btnCosRO;

    void initGUICmps();
    void connectSignalsSlots();
    void reloadList(const vector<Locatar>& lista);
    void addNewLocatar();
    void deleteLocatar();
    void updateLocatar();
    void filterByType();
    void filterBySurface();
    void cautareLocatar();
    void adaugareButoaneTipuri();
    vector<QPushButton*>btns;
    void stergereButoaneTipuri();
    void generareRaport();

public:
    LocatarGUIModele(LocatariService& serv): serv{serv} {
        initGUICmps();
        model = new MyTableModel{serv.getAll()};
        list->setModel(model);
        table->setModel(model);
        connectSignalsSlots();
    }
};