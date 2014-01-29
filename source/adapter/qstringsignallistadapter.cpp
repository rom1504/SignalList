#include "qstringsignallistadapter.h"

#include <QDebug>

SignalListAdapter<QString>::SignalListAdapter(SignalList<QString> *list, QObject *parent) :
    SignalListAdapterBase(list,parent)
{
}

QVariant SignalListAdapter<QString>::data (const QModelIndex & index, int role ) const
{
    if (!index.isValid())
     return QVariant();

    if (index.row() >= mList->size())
     return QVariant();

    if(role==FullItemRole) return QVariant::fromValue(mList->get(index.row()));

    if(role == Qt::DisplayRole || role == Qt::EditRole) return mList->get(index.row());
    else return QVariant();
}

bool SignalListAdapter<QString>::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (!index.isValid() || role != Qt::EditRole) return false;
    mList->set(index.row(),value.value<QString>());
    return true;
}


bool SignalListAdapter<QString>::pushRow()
{
    return insertRow(rowCount());
}

Qt::ItemFlags SignalListAdapter<QString>::flags(const QModelIndex &) const
{
    return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable;
}

bool SignalListAdapter<QString>::insertRows(int row, int count, const QModelIndex & parent) // mettre ce genre de truc dans l'adapter général ?
{
    beginInsertRows(parent,row,row+count-1);
    for(int i=0;i<count;i++) mList->append(QString());
    endInsertRows();
    return true;
}

bool SignalListAdapter<QString>::removeRows(int row, int count, const QModelIndex & parent)
{
    beginRemoveRows(parent,row,row+count-1);
    for(int i=0;i<count;i++) mList->remove(row);
    endRemoveRows();
    return true;
}
