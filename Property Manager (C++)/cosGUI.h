#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QAction>
#include <QListWidget>
#include <vector>
#include "domain.h"
#include "service.h"

class cosGUI: public QWidget{
private:
    LocatariService& serv;
    void initGUICmps();
    void connectSignalsSlots();
    void reloadList(const vector<Locatar>& locatari);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QListWidget* list = new QListWidget;
    QPushButton* btnDelCos;
    QPushButton* btnGenerate;
    QLineEdit* txtGen;
    QPushButton* btnExport;
    QLineEdit* txtNume;
    QLineEdit* txtTip;

public:
    cosGUI(LocatariService& serv): serv{serv}{
        initGUICmps();
        connectSignalsSlots();
        reloadList(serv.getNotifList());
    }
};