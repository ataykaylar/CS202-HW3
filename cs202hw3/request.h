#ifndef REQUEST_H_
#define REQUEST_H_

#include <iostream>
#include <fstream>
using namespace std;
class Request
{
    public:
        Request();
        void operator=(Request const &obj);
        void setId(int id);
        void setPriority(int priority);
        void setRequestTime(int reguestTime);
        void setProcessTime(int processTime);
        void setWaitTime(int waitTime);
        void setPrinterId(int printerId);
        int getId();
        int getPriority();
        int getRequestTime();
        int getProcessTime();
        int getWaitTime();
        int getPrinterId();
    private:
        int id;
        int priority;
        int requestTime;
        int processTime;
        int waitTime;
        int printerId;
       

};

#endif 