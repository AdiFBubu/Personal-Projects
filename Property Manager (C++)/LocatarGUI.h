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

using std::vector;

class LocatarGUI: public QWidget{
private:
    LocatariService& serv;
    QHBoxLayout* lyMain = new QHBoxLayout;
    QListWidget* list;
    QTableWidget* table;
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
    LocatarGUI(LocatariService& serv): serv{serv} {
        initGUICmps();
        connectSignalsSlots();
        reloadList(serv.getAll());
    }
};