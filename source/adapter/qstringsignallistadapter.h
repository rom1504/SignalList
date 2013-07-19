#ifndef QSTRINGSIGNALLISTADAPTER_H
#define QSTRINGSIGNALLISTADAPTER_H

#include <QString>

#include "adapter/signallistadapter.h"


template<> class SignalListAdapter<QString> : public SignalListAdapterBase<QString>
{
public:
    explicit SignalListAdapter(SignalList<QString> * list,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;
    bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());
    bool pushRow();
};

#endif // QSTRINGSIGNALLISTADAPTER_H
