//
// Created by Adi on 5/26/2024.
//
#include "MyTableModel.h"

MyTableModel::MyTableModel(const vector<Locatar> &v): lista{v} {

}

int MyTableModel::rowCount(const QModelIndex &parent) const {
    return lista.size();
}

int MyTableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const {

    qDebug() << "row:" << index.row() << " col:" << index.column()<<" role"<<role;
    if (role == Qt::DisplayRole)
    {
        Locatar l = lista[index.row()];
        if (index.column() == 0)
            return QString::number(l.get_ap());
        else if (index.column() == 1)
            return QString::fromStdString(l.get_nume());
        else if (index.column() == 2)
            return QString::fromStdString(l.get_tip());
        else
            return QString::number(l.get_suprafata());
    }

    if (role == Qt::BackgroundRole)
    {
        Locatar l = lista[index.row()];
        if (l.get_suprafata() < 25)
            return QBrush{Qt::red, Qt::SolidPattern};
        else if (l.get_suprafata() < 100)
            return QBrush{Qt::yellow, Qt::SolidPattern};
        else
            return QBrush{Qt::green, Qt::SolidPattern};
    }

    return QVariant();
}

void MyTableModel::setLocatari(const vector<Locatar> &v) {
        emit layoutAboutToBeChanged();
        lista = v;
        emit layoutChanged();
        /*
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount() - 1, columnCount() - 1);
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
         */
        /*
        int oldRowCount = lista.size();
        int newRowCount = v.size();
        if (newRowCount > oldRowCount)
        {
            emit beginInsertRows(QModelIndex(), oldRowCount, newRowCount - 1);
            emit endInsertRows();
        }
        else if (newRowCount < oldRowCount)
        {
            emit beginRemoveRows(QModelIndex(), newRowCount, oldRowCount - 1);
            emit endRemoveRows();
        }
        else
        {
            auto topLeft = createIndex(0, 0);
            auto bottomR = createIndex(rowCount() - 1, columnCount() - 1);
            emit dataChanged(topLeft, bottomR);
        }
         */
    }

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
            return QString{"Column %1"}.arg(section + 1);
        else
            return QString{"Row %1"}.arg(section + 1);
    }
    return QVariant();
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const {
    auto defaultFlags = QAbstractTableModel::flags(index);

    if (index.isValid() && index.column() == 1) { // Doar coloana 1 este editabilă
        return defaultFlags | Qt::ItemIsEditable;
    } else {
        return defaultFlags;
    }
}

bool MyTableModel::setData(const QModelIndex & index, const QVariant & value,
                           int role) {
    if (role == Qt::EditRole)
    {
        int row = index.row();
        int column = index.column();

        if (column == 0)
            lista[index.row()].set_ap(value.toInt());
        else if (column == 1)
            lista[index.row()].set_nume(value.toString().toStdString());
        else if (column == 2)
            lista[index.row()].set_tip(value.toString().toStdString());
        else if (column == 3)
            lista[index.row()].set_suprafata(value.toDouble());

        QModelIndex topLeft = createIndex(row, column);
        emit dataChanged(topLeft, topLeft);
    }
    return true;
}
