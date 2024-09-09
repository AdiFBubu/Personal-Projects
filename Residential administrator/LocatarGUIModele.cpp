//
// Created by Adi on 5/26/2024.
//
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include "LocatarGUIModele.h"
#include "cosGUI2.h"

void LocatarGUIModele:: initGUICmps()
{
    setLayout(lyMain);

    QWidget* stanga = new QWidget;
    QVBoxLayout* lyStanga = new QVBoxLayout;
    stanga->setLayout(lyStanga);
    lyMain->addWidget(stanga);

    nrLocatari = new QLabel{"Locatari: " + QString::number(serv.getAll().size())};
    lyStanga->addWidget(nrLocatari);

    QWidget* listaTabel = new QWidget;
    QHBoxLayout* lyListaTabel = new QHBoxLayout;
    listaTabel->setLayout(lyListaTabel);
    lyStanga->addWidget(listaTabel);
    list = new QListView;
    lyListaTabel->addWidget(list);
    list->setUniformItemSizes(true);
    table = new QTableView;
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

    /*
    auto fereastra = new CosReadOnlyGUI(serv.getNotificationList());
    fereastra->setMinimumHeight(600);
    lyWidDetalii->addWidget(fereastra);
    */


    dreapta = new QWidget;
    lyDreapta = new QVBoxLayout;
    dreapta->setLayout(lyDreapta);
    lyMain->addWidget(dreapta);
    btnRaport = new QPushButton("Generare raport");
    lyDreapta->addWidget(btnRaport);

}

void LocatarGUIModele:: connectSignalsSlots()
{
    QObject::connect(btnRaport, &QPushButton::clicked, [&](){
        adaugareButoaneTipuri();
        delete btnRaport;
        btnRaport = nullptr;
    } );

    QObject::connect(btnGetAll, &QPushButton::clicked, [&](){
        reloadList(serv.getAll());
    });

    QObject::connect(btnCautareAp, &QPushButton::clicked, this, &LocatarGUIModele::cautareLocatar);

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

    QObject::connect(btnFilterByType, &QPushButton::clicked, this, &LocatarGUIModele::filterByType);

    QObject::connect(btnFilterBySurface, &QPushButton::clicked, this, &LocatarGUIModele::filterBySurface);

    QObject::connect(btnAdd, &QPushButton::clicked, this, &LocatarGUIModele::addNewLocatar);

    QObject::connect(btnDel, &QPushButton::clicked, this, &LocatarGUIModele::deleteLocatar);

    QObject::connect(btnUpd, &QPushButton::clicked, this, &LocatarGUIModele::updateLocatar);

    QObject::connect(list->selectionModel(), &QItemSelectionModel::selectionChanged, [&](){

        if (list->selectionModel()->selectedIndexes().isEmpty())
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
            int selRow = list->selectionModel()->selectedIndexes()[0].row();
            auto cell0Index = list->model()->index(selRow, 0);
            auto cell1Index = list->model()->index(selRow, 1);
            auto cell2Index = list->model()->index(selRow, 2);
            auto cell3Index = list->model()->index(selRow, 3);

            auto ap = list->model()->data(cell0Index, Qt::DisplayRole).toString();
            auto nume = list->model()->data(cell1Index, Qt::DisplayRole).toString();
            auto tip = list->model()->data(cell2Index, Qt::DisplayRole).toString();
            auto suprafata = list->model()->data(cell3Index, Qt::DisplayRole).toString();

            txtAppartment->setText(ap);
            txtName->setText(nume);
            txtType->setText(tip);
            txtSurface->setText(suprafata);
        }
    });

    QObject::connect(table->selectionModel(), &QItemSelectionModel::selectionChanged, [&](){

        if (table->selectionModel()->selectedIndexes().isEmpty())
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

            int selRow = table->selectionModel()->selectedIndexes()[0].row();

            auto cell0Index = table->model()->index(selRow, 0);
            auto cell1Index = table->model()->index(selRow, 1);
            auto cell2Index = table->model()->index(selRow, 2);
            auto cell3Index = table->model()->index(selRow, 3);

            auto ap = table->model()->data(cell0Index, Qt::DisplayRole).toString();
            auto nume = table->model()->data(cell1Index, Qt::DisplayRole).toString();
            auto tip = table->model()->data(cell2Index, Qt::DisplayRole).toString();
            auto suprafata = table->model()->data(cell3Index, Qt::DisplayRole).toString();

            txtAppartment->setText(ap);
            txtName->setText(nume);
            txtType->setText(tip);
            txtSurface->setText(suprafata);
        }
    });

    QObject::connect(btnAddCos, &QPushButton::clicked, [&](){

        if (! list->selectionModel()->selectedIndexes().isEmpty())
        {
            auto selRow = list->selectionModel()->selectedIndexes()[0].row();
            auto cell0Index = list->model()->index(selRow, 0);
            int ap = list->model()->data(cell0Index, Qt::DisplayRole).toInt();
            try {
                serv.addNotif(ap);
            }
            catch (const RepoException& e)
            {
                QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
                return;
            }
        }

        if (! table->selectionModel()->selectedIndexes().isEmpty())
        {
            auto selRow = table->selectionModel()->selectedIndexes()[0].row();
            auto cell0Index = table->model()->index(selRow, 0);
            int ap = table->model()->data(cell0Index, Qt::DisplayRole).toInt();
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

void LocatarGUIModele:: reloadList(const vector<Locatar>& lista)
{
    nrLocatari->setText(QString{"Locatari: " + QString::number(lista.size())});
    model->setLocatari(lista);
}

void LocatarGUIModele:: addNewLocatar()
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

void LocatarGUIModele:: deleteLocatar()
{
    if (! list->selectionModel()->selectedIndexes().isEmpty())
    {
        auto selRow = list->selectionModel()->selectedIndexes()[0].row();
        auto cell0Index = list->model()->index(selRow, 0);
        int ap = list->model()->data(cell0Index, Qt::DisplayRole).toInt();

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
    if (! table->selectionModel()->selectedIndexes().isEmpty())
    {
        auto selRow = table->selectionModel()->selectedIndexes()[0].row();
        auto cell0Index = table->model()->index(selRow, 0);
        int ap = table->model()->data(cell0Index, Qt::DisplayRole).toInt();

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

void LocatarGUIModele:: updateLocatar()
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

void LocatarGUIModele::filterByType()
{
    string tip = txtType->text().toStdString();
    if (tip == "")
    {
        QMessageBox::warning(this, "Warning", "Tipul trebuie sa fie nevid!");
        return;
    }
    reloadList(serv.filtrareTip(tip));
}

void LocatarGUIModele::filterBySurface()
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

void LocatarGUIModele::cautareLocatar()
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

void LocatarGUIModele::adaugareButoaneTipuri()
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

void LocatarGUIModele::stergereButoaneTipuri()
{
    for (const auto& el : btns)
        delete el;
    btns.clear();
}

void LocatarGUIModele::generareRaport() {
    stergereButoaneTipuri();
    adaugareButoaneTipuri();
}