//
// Created by Adi on 5/26/2024.
//

#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "domain.h"
#include <QBrush>

using std::vector;

class MyTableModel: public QAbstractTableModel{
    vector<Locatar> lista;

public:
    MyTableModel(const vector<Locatar>& v);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void setLocatari(const vector<Locatar>& v);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role);
    };