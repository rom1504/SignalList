#include "signallist.h"

SignalListBase::SignalListBase(QObject * parent) : QObject(parent)
{
    connect(this,&SignalListBase::endInsert,this,&SignalListBase::endOfAChange);
    connect(this,&SignalListBase::endRemove,this,&SignalListBase::endOfAChange);
    connect(this,&SignalListBase::endReset,this,&SignalListBase::endOfAChange);
    connect(this,&SignalListBase::dataChanged,[this](int,int){emit endOfAChange();});
}
