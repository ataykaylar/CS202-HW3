#ifndef PRINTER
#define PRINTER

#include "request.h"
#include <iostream>
#include <fstream>
using namespace std;

class Printer
{
    public:
        Printer();
        
        void setRequest(Request rq,int time);
        Request getRequest();
        int getEndtime();
        bool getIsUsed();
        void freePrinter();
    private:
        Request curRequest;
        int endTime;
        bool isUsed;

};

#endif