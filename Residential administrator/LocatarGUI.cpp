#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include "LocatarGUI.h"
#include "cosGUI2.h"

void LocatarGUI:: initGUICmps()
{
    setLayout(lyMain);

    QWidget* stanga = new QWidget;
    QVBoxLayout* lyStanga = new QVBoxLayout;
    stanga->setLayout(lyStanga);
    lyMain->addWidget(stanga);

    QWidget* listaTabel = new QWidget;
    QHBoxLayout* lyListaTabel = new QHBoxLayout;
    listaTabel->setLayout(lyListaTabel);
    lyStanga->addWidget(listaTabel);
    list = new QListWidget;
    lyListaTabel->addWidget(list);
    table = new QTableWidget(1,2);
    lyListaTabel->addWidget(table);

    btnDel = new QPushButton("Sterge");
    btnDel->setDisabled(true);
    lyStanga->addWidget(btnDel);

    QWidget* widCos = new QWidget;
    QHBoxLayout* lyWidCos = new QHBoxLayout;
    widCos->setLayout(lyWidCos);
    lyStanga->addWidget(widCos);
    btnAddCos = new QPushButton("Adauga in cos");
    btnAddCos->setDisabled(true);
    lyWidCos->addWidget(btnAddCos);
    btnDelNotif = new QPushButton{"Sterge cosul"};
    lyWidCos->addWidget(btnDelNotif);

    QWidget* widGen = new QWidget;
    QHBoxLayout* lyWidGen = new QHBoxLayout;
    widGen->setLayout(lyWidGen);
    lyStanga->addWidget(widGen);
    QFormLayout* lyFormGen = new QFormLayout;
    lyWidGen->addLayout(lyFormGen);
    txtGen = new QLineEdit;
    lyFormGen->addRow("Locatari", txtGen);
    btnGenNotif = new QPushButton{"Generare cos"};
    lyWidGen->addWidget(btnGenNotif);

    QWidget* widCosuri = new QWidget;
    QHBoxLayout* lyWidCosuri = new QHBoxLayout;
    widCosuri->setLayout(lyWidCosuri);
    lyStanga->addWidget(widCosuri);
    btnCosCRUD = new QPushButton{"CosCRUDGUI"};
    lyWidCosuri->addWidget(btnCosCRUD);
    btnCosRO = new QPushButton{"CosReadOnlyGUI"};
    lyWidCosuri->addWidget(btnCosRO);

    QWidget* butoane = new QWidget;
    QHBoxLayout* lyButoane = new QHBoxLayout;
    butoane->setLayout(lyButoane);
    lyStanga->addWidget(butoane);

    QWidget* widSortName = new QWidget;
    QVBoxLayout* lyWidSortName = new QVBoxLayout;
    widSortName->setLayout(lyWidSortName);
    lyButoane->addWidget(widSortName);
    btnSortByNameCresc = new QPushButton("Sort by name (asc)");
    lyWidSortName->addWidget(btnSortByNameCresc);
    btnSortByNameDescresc = new QPushButton("Sort by name (desc)");
    lyWidSortName->addWidget(btnSortByNameDescresc);

    QWidget* widSortSurface = new QWidget;
    QVBoxLayout* lyWidSortSurface = new QVBoxLayout;
    widSortSurface->setLayout(lyWidSortSurface);
    lyButoane->addWidget(widSortSurface);
    btnSortBySurfaceCresc = new QPushButton("Sort by surface (asc)");
    lyWidSortSurface->addWidget(btnSortBySurfaceCresc);
    btnSortBySurfaceDescresc = new QPushButton("Sort by surface (desc)");
    lyWidSortSurface->addWidget(btnSortBySurfaceDescresc);

    QWidget* widSortTypeSurface = new QWidget;
    QVBoxLayout* lyWidSortTypeSurface = new QVBoxLayout;
    widSortTypeSurface->setLayout(lyWidSortTypeSurface);
    lyButoane->addWidget(widSortTypeSurface);
    btnSortByTypeAndSurfaceCresc = new QPushButton("Sort by Type, Surface (asc)");
    lyWidSortTypeSurface->addWidget(btnSortByTypeAndSurfaceCresc);
    btnSortByTypeAndSurfaceDescresc = new QPushButton("Sort by Type, Surface (desc)");
    lyWidSortTypeSurface->addWidget(btnSortByTypeAndSurfaceDescresc);

    QWidget* widDetalii = new QWidget;
    QFormLayout* lyWidDetalii = new QFormLayout;
    widDetalii->setLayout(lyWidDetalii);
    lyMain->addWidget(widDetalii);

    txtAppartment = new QLineEdit;
    lyWidDetalii->addRow(new QLabel("Apartament:"), txtAppartment);
    txtName = new QLineEdit;
    lyWidDetalii->addRow(new QLabel("Name:"), txtName);
    txtType = new QLineEdit;
    lyWidDetalii->addRow(new QLabel("Tip:"), txtType);
    txtSurface = new QLineEdit;
    lyWidDetalii->addRow(new QLabel("Suprafata:"), txtSurface);

    QWidget* addUpdGet = new QWidget;
    QHBoxLayout* lyAddUpdGet = new QHBoxLayout;
    addUpdGet->setLayout(lyAddUpdGet);
    lyWidDetalii->addWidget(addUpdGet);
    btnAdd = new QPushButton("Adauga");
    lyAddUpdGet->addWidget(btnAdd);
    btnUpd = new QPushButton("Update");
    lyAddUpdGet->addWidget(btnUpd);
    btnGetAll = new QPushButton("Get all");
    lyAddUpdGet->addWidget(btnGetAll);

    QWidget* cautare = new QWidget;
    QHBoxLayout* lyCautare = new QHBoxLayout;
    cautare->setLayout(lyCautare);
    lyWidDetalii->addWidget(cautare);
    btnCautareAp = new QPushButton("Cautare locatar");
    lyCautare->addWidget(btnCautareAp);
    txtCautareAp = new QLineEdit;
    QFormLayout* formCautare = new QFormLayout;
    lyCautare->addLayout(formCautare);
    formCautare->addRow("Ap:", txtCautareAp);

    QWidget* filterType = new QWidget;
    QHBoxLayout* lyFilterType = new QHBoxLayout;
    filterType->setLayout(lyFilterType);
    lyWidDetalii->addWidget(filterType);
    btnFilterByType = new QPushButton("Filter by type");
    lyFilterType->addWidget(btnFilterByType);
    QFormLayout* lyFormFilterType = new QFormLayout;
    txtFilterType = new QLineEdit;
    lyFormFilterType->addRow("Type:", txtFilterType);
    lyFilterType->addLayout(lyFormFilterType);

    QWidget* filterSurf = new QWidget;
    QHBoxLayout* lyFilterSurf = new QHBoxLayout;
    filterSurf->setLayout(lyFilterSurf);
    lyWidDetalii->addWidget(filterSurf);
    btnFilterBySurface = new QPushButton("Filter by surface");
    lyFilterSurf->addWidget(btnFilterBySurface);
    QFormLayout* lyFormFilterSurf = new QFormLayout;
    txtFilterMinSurf = new QLineEdit;
    lyFormFilterSurf->addRow("min:", txtFilterMinSurf);
    txtFilterMaxSurf = new QLineEdit;
    lyFormFilterSurf->addRow("max", txtFilterMaxSurf);
    lyFilterSurf->addLayout(lyFormFilterSurf);

    btnUndo = new QPushButton("Undo");
    lyWidDetalii->addWidget(btnUndo);

    dreapta = new QWidget;
    lyDreapta = new QVBoxLayout;
    dreapta->setLayout(lyDreapta);
    lyMain->addWidget(dreapta);
    btnRaport = new QPushButton("Generare raport");
    lyDreapta->addWidget(btnRaport);

}

void LocatarGUI:: connectSignalsSlots()
{
    QObject::connect(btnRaport, &QPushButton::clicked, [&](){
        adaugareButoaneTipuri();
        delete btnRaport;
        btnRaport = nullptr;
    } );

    QObject::connect(btnGetAll, &QPushButton::clicked, [&](){
        reloadList(serv.getAll());
    });

    QObject::connect(btnCautareAp, &QPushButton::clicked, this, &LocatarGUI::cautareLocatar);

    QObject::connect(btnSortByNameCresc, &QPushButton::clicked, [&](){
        reloadList(serv.sortareNume(0));
    });

    QObject::connect(btnSortByNameDescresc, &QPushButton::clicked, [&](){
        reloadList(serv.sortareNume(1));
    });

    QObject::connect(btnSortBySurfaceCresc, &QPushButton::clicked, [&](){
        reloadList(serv.sortareSuprafata(0));
    });

    QObject::connect(btnSortBySurfaceDescresc, &QPushButton::clicked, [&](){
        reloadList(serv.sortareSuprafata(1));
    });

    QObject::connect(btnSortByTypeAndSurfaceCresc, &QPushButton::clicked, [&](){
        reloadList(serv.sortareTipSuprafata(0));
    });

    QObject::connect(btnSortByTypeAndSurfaceDescresc, &QPushButton::clicked, [&](){
        reloadList(serv.sortareTipSuprafata(1));
    });

    QObject::connect(btnUndo, &QPushButton::clicked, [&](){
        try{
            serv.undo();
            reloadList(serv.getAll());
            if (btnRaport == nullptr)
                generareRaport();
        }
        catch (const RepoException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
        }
    });

    QObject::connect(btnFilterByType, &QPushButton::clicked, this, &LocatarGUI::filterByType);

    QObject::connect(btnFilterBySurface, &QPushButton::clicked, this, &LocatarGUI::filterBySurface);

    QObject::connect(btnAdd, &QPushButton::clicked, this, &LocatarGUI::addNewLocatar);

    QObject::connect(btnDel, &QPushButton::clicked, this, &LocatarGUI::deleteLocatar);

    QObject::connect(btnUpd, &QPushButton::clicked, this, &LocatarGUI::updateLocatar);

    QObject::connect(list, &QListWidget::itemSelectionChanged, [&](){
        auto selection = list->selectedItems();
        if (selection.isEmpty())
        {
            txtAppartment->setText("");
            txtName->setText("");
            txtType->setText("");
            txtSurface->setText("");
            btnDel->setDisabled(true);
            btnAddCos->setDisabled(true);
        }
        else
        {
            btnDel->setDisabled(false);
            btnAddCos->setEnabled(true);
            auto selectionItem = selection[0];
            QString ap = selectionItem->data(Qt::UserRole).toString();
            QString nume = selectionItem->text();
            QString tip = selectionItem->data(Qt::UserRole + 1).toString();
            QString suprafata = selectionItem->data(Qt::UserRole + 2).toString();
            txtAppartment->setText(ap);
            txtName->setText(nume);
            txtType->setText(tip);
            txtSurface->setText(suprafata);
        }
    });

    QObject::connect(table, &QTableWidget::itemSelectionChanged, [&](){
        auto selection = table->selectedItems();
        if (selection.isEmpty())
        {
            txtAppartment->setText("");
            txtName->setText("");
            txtType->setText("");
            txtSurface->setText("");
            btnDel->setDisabled(true);
            btnAddCos->setDisabled(true);
        }
        else
        {
            btnDel->setDisabled(false);
            btnAddCos->setEnabled(true);
            auto selectionItem = selection[0];
            QString ap = selectionItem->data(Qt::UserRole).toString();
            QString nume = selectionItem->text();
            QString tip = selectionItem->data(Qt::UserRole + 1).toString();
            QString suprafata = selectionItem->data(Qt::UserRole + 2).toString();
            txtAppartment->setText(ap);
            txtName->setText(nume);
            txtType->setText(tip);
            txtSurface->setText(suprafata);
        }
    });

    QObject::connect(btnAddCos, &QPushButton::clicked, [&](){
        auto selection = list->selectedItems();
        if (!selection.isEmpty())
        {
            auto selectionItem = selection[0];
            int ap = selectionItem->data(Qt::UserRole).toInt();
            try {
                serv.addNotif(ap);
            }
            catch (const RepoException& e)
            {
                QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
                return;
            }
        }
        auto selection2 = table->selectedItems();
        if (!selection2.isEmpty())
        {
            auto selectionItem = selection2[0];
            int ap = selectionItem->data(Qt::UserRole).toInt();
            try {
                serv.addNotif(ap);
            }
            catch (const RepoException& e)
            {
                QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
                return;
            }
        }
    });

    QAction::connect(btnDelNotif, &QPushButton::clicked, [&](){
        serv.clearList();
    });

    QAction::connect(btnGenNotif, &QPushButton::clicked, [&](){
        bool eroare;
        int nr = txtGen->text().toInt(&eroare);
        if (!eroare || nr < 0)
        {
            QMessageBox::warning(this, "atentie!", "Trebuie sa introduci un numar natural!");
            return;
        }
        serv.generate(nr);
    });

    QAction::connect(btnCosCRUD, &QPushButton::clicked, [&](){
        CosCRUDGUI* guiCos = new CosCRUDGUI{serv.getNotificationList()};
        guiCos->show();
    });

    QAction::connect(btnCosRO, &QPushButton::clicked, [&](){
        CosReadOnlyGUI* guiCos = new CosReadOnlyGUI{serv.getNotificationList()};
        guiCos->show();
    });
}

void LocatarGUI:: reloadList(const vector<Locatar>& lista)
{
    list->clear();
    for (const auto& locatar : lista)
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(locatar.get_nume()));
        item->setData(Qt::UserRole, QString::number(locatar.get_ap()));
        item->setData(Qt::UserRole + 1, QString::fromStdString(locatar.get_tip()));
        item->setData(Qt::UserRole + 2, QString::number(locatar.get_suprafata()));
        if (locatar.get_suprafata() < 25)
            item->setData(Qt::BackgroundRole, QBrush{Qt::red, Qt::SolidPattern});
        else if (locatar.get_suprafata() < 100)
            item->setData(Qt::BackgroundRole, QBrush{Qt::yellow, Qt::SolidPattern});
        else
            item->setData(Qt::BackgroundRole, QBrush{Qt::green, Qt::SolidPattern});
        list->addItem(item);
    }

    table->clear();
    int i = 0, j = 0;
    for (const auto& locatar : lista)
    {
        if (j == 2)
        {
            i++, j = 0;
            if (i == table->rowCount())
                table->insertRow(table->rowCount());
        }
        QTableWidgetItem* cellItem = new QTableWidgetItem(QString::fromStdString(locatar.get_nume()));
        cellItem->setData(Qt::UserRole, QString::number(locatar.get_ap()));
        cellItem->setData(Qt::UserRole + 1, QString::fromStdString(locatar.get_tip()));
        cellItem->setData(Qt::UserRole + 2, QString::number(locatar.get_suprafata()));
        if (locatar.get_suprafata() < 25)
            cellItem->setData(Qt::BackgroundRole, QBrush{Qt::red, Qt::SolidPattern});
        else if (locatar.get_suprafata() < 100)
            cellItem->setData(Qt::BackgroundRole, QBrush{Qt::yellow, Qt::SolidPattern});
        else
            cellItem->setData(Qt::BackgroundRole, QBrush{Qt::green, Qt::SolidPattern});
        table->setItem(i, j, cellItem);
        j ++;
    }

}

void LocatarGUI:: addNewLocatar()
{
        bool eroare;
        int ap = txtAppartment->text().toInt(&eroare);
        if (!eroare)
        {
            QMessageBox::warning(this, "Warning", "Apartamentul trebuie sa fie un numar intreg!");
            return;
        }
        string nume = txtName->text().toStdString();
        string tip = txtType->text().toStdString();
        double suprafata = txtSurface->text().toDouble(&eroare);
        if (!eroare)
        {
            QMessageBox::warning(this, "Warning", "Suprafata trebuie sa fie un numar real!");
            return;
        }

        try{
        serv.add(ap, nume, tip, suprafata);
        reloadList(serv.getAll());
        if (btnRaport == nullptr)
            generareRaport();
    }
    catch (const RepoException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
    }
    catch (const ValidatorException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
    }
}

void LocatarGUI:: deleteLocatar()
{
    auto selection = list->selectedItems();
    if (!selection.isEmpty())
    {
        auto selectionItem = selection[0];
        int ap = selectionItem->data(Qt::UserRole).toInt();
        try{
            serv.sterge(ap);
            reloadList(serv.getAll());
            if (btnRaport == nullptr)
                generareRaport();
        }
        catch (const RepoException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
        }
    }
    auto selection2 = table->selectedItems();
    if (!selection2.isEmpty())
    {
        auto selectionItem = selection2[0];
        int ap = selectionItem->data(Qt::UserRole).toInt();
        try{
            serv.sterge(ap);
            reloadList(serv.getAll());
            if (btnRaport == nullptr)
                generareRaport();
        }
        catch (const RepoException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
        }
    }
}

void LocatarGUI:: updateLocatar()
{
    bool eroare;
    int ap = txtAppartment->text().toInt(&eroare);
    if (!eroare)
    {
        QMessageBox::warning(this, "Warning", "Apartamentul trebuie sa fie un numar intreg!");
        return;
    }
    string nume = txtName->text().toStdString();
    string tip = txtType->text().toStdString();
    double suprafata = txtSurface->text().toDouble(&eroare);
    if (!eroare)
    {
        QMessageBox::warning(this, "Warning", "Suprafata trebuie sa fie un numar real!");
        return;
    }

    try{
        serv.modifica(ap, nume, tip, suprafata);
        reloadList(serv.getAll());
        if (btnRaport == nullptr)
            generareRaport();
    }
    catch (const RepoException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
    }
    catch (const ValidatorException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
    }
}

void LocatarGUI::filterByType()
{
    string tip = txtType->text().toStdString();
    if (tip == "")
    {
        QMessageBox::warning(this, "Warning", "Tipul trebuie sa fie nevid!");
        return;
    }
    reloadList(serv.filtrareTip(tip));
}

void LocatarGUI::filterBySurface()
{
    bool eroare;
    double smin = txtFilterMinSurf->text().toDouble(&eroare);
    if (eroare == false)
    {
        QMessageBox::warning(this, "Warning", "Suprafata minima trebuie sa fie un numar real!");
        return;
    }
    double smax = txtFilterMaxSurf->text().toDouble(&eroare);
    if (eroare == false)
    {
        QMessageBox::warning(this, "Warning", "Suprafata maxima trebuie sa fie un numar real!");
        return;
    }
    reloadList(serv.filtrareSuprafata(smin,smax));
}

void LocatarGUI::cautareLocatar()
{
    bool eroare;
    int ap = txtCautareAp->text().toInt(&eroare);
    if (!eroare)
    {
        QMessageBox::warning(this, "Warning", "Apartamentul trebuie sa fie un numar intreg!");
        return;
    }
    else
    {
        try{
            Locatar l = serv.cautareLocatar(ap);
            string mesaj = string("Locatarul a fost gasit!\n") + "Apartament: " + std::to_string(l.get_ap()) + ", Nume: " + l.get_nume() + ", Tip: " + l.get_tip() + ", Suprafata: " + std::to_string(l.get_suprafata());
            QMessageBox::information(this, "Info", QString::fromStdString(mesaj));
        }
        catch (const RepoException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
        }
        catch (const ValidatorException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
        }
    }
}

void LocatarGUI::adaugareButoaneTipuri()
{
    auto raport = serv.getRaport();
    for (const auto& tip : raport)
    {
        QPushButton* btn = new QPushButton(QString::fromStdString(tip.first));
        btns.push_back(btn);
        lyDreapta->addWidget(btn);
        QString mesaj = "";
        for (const auto &el : tip.second)
            mesaj += "Apartament: " + std::to_string(el.get_ap()) + ", Nume: " + el.get_nume() + ", Tip: " + el.get_tip() + ", Suprafata: " + std::to_string(el.get_suprafata()) + '\n';
        QAction::connect(btn, &QPushButton::clicked, [mesaj, this, btn](){
            QMessageBox::information(this, "Info", mesaj);
            auto it = std::find(btns.begin(), btns.end(), btn);
            btns.erase(it);
            delete btn;
        });
    }
}

void LocatarGUI::stergereButoaneTipuri()
{
    for (const auto& el : btns)
        delete el;
    btns.clear();
}

void LocatarGUI::generareRaport() {
    stergereButoaneTipuri();
    adaugareButoaneTipuri();
}