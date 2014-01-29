#ifndef SIGNALLISTADAPTER_HXX
#define SIGNALLISTADAPTER_HXX

#include "signallistadapter.h"

template <class T> SignalListAdapterBase<T>::SignalListAdapterBase(SignalList<T> *list, QObject *parent) : QAbstractListModel(parent),mList(list)
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

template <class T> SignalListAdapter<T>::SignalListAdapter(SignalList<T> * list,QObject *parent) : SignalListAdapterBase<T>(list,parent)
{

}

#endif // SIGNALLISTADAPTER_HXX
