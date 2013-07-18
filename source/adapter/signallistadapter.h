#ifndef SIGNALLISTADAPTER_H
#define SIGNALLISTADAPTER_H

#include <QAbstractListModel>
#include "model/signallist.h"

template <class T> class SignalListAdapterBase : public QAbstractListModel
{
public:
    explicit SignalListAdapterBase(SignalList<T> * list,QObject *parent = 0);
    int rowCount (const QModelIndex & = QModelIndex()) const;

protected:
    SignalList<T> * mList;

};

template <class T> class SignalListAdapter : public SignalListAdapterBase<T>
{
public:
    explicit SignalListAdapter(SignalList<T> * list,QObject *parent = 0);
};

#include "signallistadapter.hxx"

#endif // SIGNALLISTADAPTER_H
