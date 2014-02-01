#ifndef SIGNALLISTADAPTER_H
#define SIGNALLISTADAPTER_H

#include <QAbstractListModel>
#include "model/signallist.h"

enum Roles
{
    FullItemRole=Qt::UserRole
};

template <class T> class SignalListAdapterBase : public QAbstractListModel
{
public:
    explicit SignalListAdapterBase(SignalList<T> * list,QString fullItemRoleName="fullItem",QObject *parent = 0);
    int rowCount (const QModelIndex & = QModelIndex()) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;

protected:
    QHash<int, QByteArray> roleNames() const;

protected:
    SignalList<T> * mList;

private:
    QString mFullItemRoleName;
};

template <class T> class SignalListAdapter : public SignalListAdapterBase<T>
{
public:
    using SignalListAdapterBase<T>::SignalListAdapterBase;

};

#include "signallistadapter.hxx"

#endif // SIGNALLISTADAPTER_H
