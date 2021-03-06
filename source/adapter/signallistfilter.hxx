#ifndef SIGNALLISTFILTER_HXX
#define SIGNALLISTFILTER_HXX

#include "signallistfilter.h"

template <class T> SignalListFilter<T>::SignalListFilter(QObject *parent) : QSortFilterProxyModel(parent)
{

}

template <class T> void SignalListFilter<T>::setFilter(std::function<bool(T)> filter)
{
    mFilter=filter;
}

template <class T> void SignalListFilter<T>::setSourceModel(SignalListAdapter<T> * adapter)
{
    QSortFilterProxyModel::setSourceModel(adapter);
    mAdapter=adapter;
}

template <class T> bool SignalListFilter<T>::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QVariant v=mAdapter->data(sourceModel()->index(sourceRow,0,sourceParent),FullItemRole);
    return mFilter(v.value<T>());
}

#endif // SIGNALLISTFILTER_HXX
