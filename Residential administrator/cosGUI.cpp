#include "cosGUI.h"
#include <QTimer>
#include <QFormLayout>
#include <QMessageBox>

void cosGUI::initGUICmps()
{
    setLayout(mainLayout);
    mainLayout->addWidget(list);

    btnDelCos = new QPushButton("Goleste cos");
    mainLayout->addWidget(btnDelCos);

    QWidget* widGen = new QWidget;
    QHBoxLayout* lyWidGen = new QHBoxLayout;
    widGen->setLayout(lyWidGen);
    mainLayout->addWidget(widGen);
    btnGenerate = new QPushButton("Genereaza");
    lyWidGen->addWidget(btnGenerate);
    QFormLayout* lyFormGen = new QFormLayout;
    lyWidGen->addLayout(lyFormGen);
    txtGen = new QLineEdit;
    lyFormGen->addRow("numar ap", txtGen);

    QWidget* widExport = new QWidget;
    QHBoxLayout* lyWidExport = new QHBoxLayout;
    widExport->setLayout(lyWidExport);
    mainLayout->addWidget(widExport);
    btnExport = new QPushButton("Export");
    lyWidExport->addWidget(btnExport);
    QFormLayout* lyFormExport = new QFormLayout;
    lyWidExport->addLayout(lyFormExport);
    txtNume = new QLineEdit;
    txtTip = new QLineEdit;
    lyFormExport->addRow("nume fisier", txtNume);
    lyFormExport->addRow("tip fisier", txtTip);

}

void cosGUI::connectSignalsSlots()
{
    QTimer* refreshTimer = new QTimer;
    refreshTimer->start(1000);

    QObject::connect(refreshTimer, &QTimer::timeout, [this](){
        reloadList(serv.getNotifList());
    });

    QObject::connect(btnDelCos, &QPushButton::clicked, [&](){
       serv.clearList();
    });

    QAction::connect(btnGenerate, &QPushButton::clicked, [&](){
        bool eroare;
        int ap = txtGen->text().toInt(&eroare);
        if (!eroare)
        {
            QMessageBox::warning(this, "Warning", "Apartamentul trebuie sa fie un numar intreg!");
            return;
        }
        else
        {
            try{
                serv.generate(ap);
            }
            catch (const RepoException& e)
            {
                QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
                return;
            }
        }

    });

    QAction::connect(btnExport, &QPushButton::clicked, [&](){
        string numeFisier = txtNume->text().toStdString();
        string tipFisier = txtTip->text().toStdString();
        try{
            serv.exportList(numeFisier, tipFisier);
        }
        catch (const ValidatorException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
            return;
        }
        catch(const RepoException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
            return;
        }
        catch (const notificationException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.getMessage()));
            return;
        }
    });
}

void cosGUI::reloadList(const vector<Locatar> &locatari)
{
    list->clear();
    for (const auto& el : locatari)
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(el.get_nume()));
        item->setData(Qt::UserRole, QString::number(el.get_ap()));
        item->setData(Qt::UserRole + 1, QString::fromStdString(el.get_tip()));
        item->setData(Qt::UserRole + 2, QString::number(el.get_suprafata()));
        if (el.get_suprafata() < 25)
            item->setData(Qt::BackgroundRole, QBrush{Qt::red, Qt::SolidPattern});
        else if (el.get_suprafata() < 100)
            item->setData(Qt::BackgroundRole, QBrush{Qt::yellow, Qt::SolidPattern});
        else
            item->setData(Qt::BackgroundRole, QBrush{Qt::green, Qt::SolidPattern});
        list->addItem(item);
    }
}