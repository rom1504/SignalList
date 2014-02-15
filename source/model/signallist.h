#ifndef SIGNALLIST_H
#define SIGNALLIST_H

#include <QObject>
#include <functional>
#include <QList>

class SignalListBase : public QObject
{
    Q_OBJECT
public:
    SignalListBase(QObject * parent=0);

signals:
    void beginInsert(int position);
    void endInsert();
    void beginRemove(int position);
    void endRemove();
    void beginReset();
    void endReset();
    void dataChanged(int begin,int end);
    void endOfAChange();
};
//when ready put all this on a different module ( / library ) and possibly use it inside sale contract filler
template <class T> class SignalList : public SignalListBase
{
public:
    SignalList(std::function<bool(T,T)> comp,bool ordered=false,QObject * parent=0); // could inherit with for ordered instead of if (slower) parameterization
    SignalList(QObject * parent=0);
    void append(T element);
    void remove(T element);
    void remove(int row);
    int size() const;
    T get(int number); // voir pour fournir un iterateur (constant au moins)
    T get(int number) const;
    void set(int number,T value);
    bool contains(T element) const;
    void clear();
    void shuffle();
    typename QList<T>::const_iterator constBegin() const;
    typename QList<T>::const_iterator constEnd() const;
    typename QList<T>::const_iterator begin() const;
    typename QList<T>::const_iterator end() const;

// add begin load and end load maybe (and not emit anything except beginreset and endreset between those) ? not essential

protected:
    QList<T> mList;
    bool mOrdered;
    std::function<bool(T,T)> mComp;
};
#include "signallist.hxx"

#endif // SIGNALLIST_H
