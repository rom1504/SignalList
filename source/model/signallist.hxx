#ifndef SIGNALLIST_HXX
#define SIGNALLIST_HXX

#include "signallist.h"
#include <algorithm>


template <class T> SignalList<T>::SignalList(std::function<bool(T,T)> comp, bool ordered, QObject * parent) : SignalListBase(parent),mOrdered(ordered),mComp(comp)
{

}

template <class T> SignalList<T>::SignalList(QObject * parent) : SignalList([](T,T){return false;},false,parent)
{

}

template <class T> void SignalList<T>::ajout(T element)
{
    int numeroElement=mOrdered ? std::find_if(mList.begin(),mList.end(),[this,element](T a){return mComp(element,a);})-mList.begin() : mList.size();
    emit debutAjout(numeroElement);
    mList.insert(numeroElement,element);
    emit finAjout();
}

template <class T> void SignalList<T>::suppression(T element)
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
    emit debutSupression(row);
    mList.removeAt(row);
    emit finSupression();
}


template <class T> void SignalList<T>::clear()
{
    emit beginReset();
    mList.clear();
    emit endReset();
}


template <class T> bool SignalList<T>::contient(T element) const
{
    return mList.contains(element);
}

template <class T> int SignalList<T>::nombre() const
{
    return mList.size();
}

template <class T> T SignalList<T>::get(int numero)
{
    return mList.at(numero);
}


template <class T> T SignalList<T>::get(int numero) const
{
    return mList.at(numero);
}

template <class T> void SignalList<T>::shuffle()
{
    emit beginReset();
    std::random_shuffle(mList.begin(),mList.end());
    emit endReset();
}


#endif // SIGNALLIST_HXX
