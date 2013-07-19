#include "signallist.h"

SignalListBase::SignalListBase(QObject * parent) : QObject(parent)
{
    connect(this,&SignalListBase::finAjout,this,&SignalListBase::endOfAChange);
    connect(this,&SignalListBase::finSupression,this,&SignalListBase::endOfAChange);
    connect(this,&SignalListBase::endReset,this,&SignalListBase::endOfAChange);
    connect(this,&SignalListBase::dataChanged,[this](int,int){emit endOfAChange();});
}
