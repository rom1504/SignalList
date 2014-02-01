#ifndef SIGNALLISTADAPTER_HXX
#define SIGNALLISTADAPTER_HXX

#include "signallistadapter.h"

template <class T> SignalListAdapterBase<T>::SignalListAdapterBase(SignalList<T> *list,QString fullItemRoleName, QObject *parent) : QAbstractListModel(parent),mList(list),mFullItemRoleName(fullItemRoleName)
{
    connect(mList,&SignalListBase::beginInsert,[this](int number){beginInsertRows(QModelIndex(),number,number);});
    connect(mList,&SignalListBase::endInsert,[this](){endInsertRows();});// je pourrais supprimer le int de SignalListBase::finAjout
    connect(mList,&SignalListBase::beginRemove,[this](int number){beginRemoveRows(QModelIndex(),number,number);});
    connect(mList,&SignalListBase::endRemove,[this](){endRemoveRows();});
    connect(mList,&SignalListBase::beginReset,[this](){beginResetModel();});
    connect(mList,&SignalListBase::endReset,[this](){endResetModel();});
    connect(mList,&SignalListBase::dataChanged,[this](int begin,int end){emit dataChanged(createIndex(begin,1),createIndex(end,1));});
}

template <class T> int SignalListAdapterBase<T>::rowCount (const QModelIndex &) const
{
    if(mList==nullptr) return 0;
    return mList->size();
}


template <class T> QVariant SignalListAdapterBase<T>::data ( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
     return QVariant();

    if (index.row() >= mList->size())
       return QVariant();

    if(role == FullItemRole) return QVariant::fromValue(mList->get(index.row()));

    return QVariant();
}

template <class T> Qt::ItemFlags SignalListAdapterBase<T>::flags(const QModelIndex &) const
{
    return Qt::ItemIsEnabled|Qt::ItemIsSelectable;
}

template <class T> QHash<int, QByteArray> SignalListAdapterBase<T>::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FullItemRole] = mFullItemRoleName.toUtf8();
    return roles;
}



#endif // SIGNALLISTADAPTER_HXX
