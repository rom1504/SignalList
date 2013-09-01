#ifndef SIGNALLISTADAPTER_HXX
#define SIGNALLISTADAPTER_HXX

#include "signallistadapter.h"

template <class T> SignalListAdapterBase<T>::SignalListAdapterBase(SignalList<T> *list, QObject *parent) : QAbstractListModel(parent),mList(list)
{
    connect(mList,&SignalListBase::debutAjout,[this](int numero){beginInsertRows(QModelIndex(),numero,numero);});
    connect(mList,&SignalListBase::finAjout,[this](){endInsertRows();});// je pourrais supprimer le int de SignalListBase::finAjout
    connect(mList,&SignalListBase::debutSupression,[this](int numero){beginRemoveRows(QModelIndex(),numero,numero);});
    connect(mList,&SignalListBase::finSupression,[this](){endRemoveRows();});
    connect(mList,&SignalListBase::beginReset,[this](){beginResetModel();});
    connect(mList,&SignalListBase::endReset,[this](){endResetModel();});
    connect(mList,&SignalListBase::dataChanged,[this](int begin,int end){emit dataChanged(createIndex(begin,1),createIndex(end,1));});
}

template <class T> int SignalListAdapterBase<T>::rowCount (const QModelIndex &) const
{
    if(mList==nullptr) return 0;
    return mList->nombre();
}


template <class T> T SignalListAdapterBase<T>::at(int row)
{
    return mList->get(row);
}

template <class T> SignalListAdapter<T>::SignalListAdapter(SignalList<T> * list,QObject *parent) : SignalListAdapterBase<T>(list,parent)
{

}

#endif // SIGNALLISTADAPTER_HXX
