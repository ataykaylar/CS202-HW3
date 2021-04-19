
#include "request.h"

Request::Request()
{
    id=0;
    priority=0;
    requestTime = 0;
    processTime = 0;
    waitTime = 0;
}

void Request::operator=(Request const &obj) {
        
         this->id = obj.id;
         this->priority = obj.priority;
         this->requestTime = obj.requestTime;
         this->processTime = obj.processTime;
    
         
}
void Request::setId(int id){this->id=id;}
void Request::setPriority(int priority){this->priority=priority;}
void Request::setRequestTime(int requestTime){this->requestTime=requestTime;}
void Request::setProcessTime(int processTime){this->processTime=processTime;}
void Request::setWaitTime(int waitTime){this->waitTime = waitTime;}
void Request::setPrinterId(int printerId){this->printerId =printerId;}
int Request::getId(){return id;}
int Request::getPriority(){return priority;}
int Request::getRequestTime(){return requestTime;}
int Request::getProcessTime(){return processTime;}
int Request::getWaitTime(){return waitTime;}
int Request::getPrinterId(){return printerId;}