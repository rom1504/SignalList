#ifndef SIGNALLIST_HXX
#define SIGNALLIST_HXX

#include "signallist.h"
#include <algorithm>


template <class T> SignalList<T>::SignalList(std::function<bool(T,T)> comp, QObject * parent) :
    SignalListBase(parent),mOrdered(true),mComp(comp)
{
}

template <class T> SignalList<T>::SignalList(QObject * parent) :
    SignalListBase(parent),mOrdered(false),mComp([](T,T){return false;})
{

}

template <class T> int SignalList<T>::append(T element)
{
    int elementNumber=mOrdered ? std::find_if(mList.begin(),mList.end(),[this,element](T a){return mComp(element,a);})-mList.begin() : mList.size();
    emit beginInsert(elementNumber);
    mList.insert(elementNumber,element);
    emit endInsert();
    return elementNumber;
}

template <class T> void SignalList<T>::remove(T element)
{
    remove(mList.indexOf(element));
}


template <class T> void SignalList<T>::set(int number,T value)
{
    mList[number]=value;
    emit dataChanged(number,number);
}

template <class T> void SignalList<T>::remove(int row)
{
    emit beginRemove(row);
    mList.removeAt(row);
    emit endRemove();
}


template <class T> void SignalList<T>::clear()
{
    emit beginReset();
    mList.clear();
    emit endReset();
}


template <class T> typename QList<T>::const_iterator SignalList<T>::constBegin() const
{
    return mList.constBegin();
}

template <class T> typename QList<T>::const_iterator SignalList<T>::constEnd() const
{
    return mList.constEnd();
}


template <class T> typename QList<T>::const_iterator SignalList<T>::begin() const
{
    return mList.constBegin();
}

template <class T> typename QList<T>::const_iterator SignalList<T>::end() const
{
    return mList.constEnd();
}

template <class T> bool SignalList<T>::contains(T element) const
{
    return mList.contains(element);
}

template <class T> int SignalList<T>::size() const
{
    return mList.size();
}

template <class T> T SignalList<T>::get(int number)
{
    return mList.at(number);
}


template <class T> T SignalList<T>::get(int number) const
{
    return mList.at(number);
}

template <class T> void SignalList<T>::shuffle()
{
    emit beginReset();
    std::random_shuffle(mList.begin(),mList.end());
    emit endReset();
}


#endif // SIGNALLIST_HXX
