

#include "printer.h"


Printer::Printer()
{
    endTime = -1;
    isUsed = false;
}
void Printer::setRequest(Request rq, int time)
{
    curRequest = rq;
    isUsed = true;
    endTime = rq.getProcessTime()+ time;
}
Request Printer::getRequest(){return curRequest;}
int Printer::getEndtime()
{
    return endTime;
}
bool Printer::getIsUsed()
{
    return isUsed;

}

void Printer::freePrinter()
{
    isUsed = false;

}

