#ifndef SIGNALLISTFILTER_H
#define SIGNALLISTFILTER_H

#include <QSortFilterProxyModel>

#include "signallistadapter.h"

template <class T> class SignalListFilter : public QSortFilterProxyModel
{
public:
    explicit SignalListFilter(QObject *parent = 0);
    void setFilter(std::function<bool(T)> filter);
    void setSourceModel(SignalListAdapter<T> * adapter);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

private:
    std::function<bool(T)> mFilter;
    SignalListAdapter<T> * mAdapter;
};

#include "signallistfilter.hxx"

#endif // SIGNALLISTFILTER_H
