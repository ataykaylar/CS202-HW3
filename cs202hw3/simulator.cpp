/**
* Title: Heaps
* Author: Atay Kaylar
* ID: 21703284
* Assignment: 3
* Description: Implementation of the heap class
*/




#include "simulator.h"




Simulator::Simulator(int printerCount, int maxAvgTime, ifstream& file)
{
    this->printerCount = printerCount;
    this-> maxAvgTime= maxAvgTime;
    readFileIntoArray(file);
    systemTime = 0;
    printers = new Printer[printerCount];
    availablePrinterCount = printerCount;
    
    
}

Simulator::Simulator()
{}

void Simulator::testHeap()
{
    Heap test;
    for(int i = 0; i < requestCount;i++)
    {
        test.insert(requests[i]);
    }
    test.printHeap();
  
}



void Simulator::readFileIntoArray(ifstream& file)
{
    int in;
    bool var = false;
    int i = 1;
    int index=0;
    while (file>> in)
    {   
        if(var)
        {
            if(i%4==1)
                requests[index].setId(in);
            else if(i%4==2)
                requests[index].setPriority(in);
            else if(i%4==3)
                requests[index].setRequestTime(in);
            else if(i%4==0)
            {
                requests[index].setProcessTime(in);    
                index++;
            }
            i++;
        }
        else
        {
            var = true;
            requestCount = in;
            requests = new Request[requestCount];
            results = new Request[requestCount];
        }      
    }


}


void Simulator::print()
{
    cout<<"Minimum number of printers needed: "<<printerCount<<endl;
    cout<<endl;
    cout<<"Simulation with "<<printerCount<<" printers:"<<printerCount<<endl;
    cout<<endl;
    for(int i =0;i<requestCount;i++)
    {
       //cout<<"waitTime: "<< results[i].getWaitTime() << " Id: "<< results[i].getId()<<" Printer ID: "<< results[i].getPrinterId()<<endl;
       cout<<"Printer "<<results[i].getPrinterId()<<" print request "<<results[i].getId()<<" at minute "<<results[i].getWaitTime()+results[i].getRequestTime()
       <<" (wait: "<<results[i].getWaitTime()<<" mins)"<<endl;
    }
    cout<<endl;

    cout<<"Average waiting time: "<<averageTime<<" minutes"<<endl;
}

double Simulator::returnAvgTime()
{
    return averageTime;
}


bool Simulator::availablePrinter()
{
    for(int i = 0; i < printerCount;i++)
    {
        if(!printers[i].getIsUsed())
        {
        
    
            return true;
           
           
      }
     
    }
    return false;

    
}


void Simulator::assignPrinter(Request& rq, int t)
{
    for(int i = 0; i < printerCount;i++)
    {
        if(!printers[i].getIsUsed())
        {
            printers[i].setRequest(rq,t);
            availablePrinterCount--;
            rq.setPrinterId(i);

            break;
         
        }
    }
}


void Simulator::updatePrinters(int t)
{
    for(int i=0; i< printerCount;i++)
    {
        if(printers[i].getEndtime() == t)
        {
            printers[i].freePrinter();
            availablePrinterCount++;
        }
    }
}



void Simulator::startSimulation()
{
    int count = 0;
    while(true)
    {
        updatePrinters(systemTime);
        
        for(int i = 0; i <requestCount; i++)
        {
            if(systemTime == requests[i].getRequestTime())
            {
                preQ.insert(requests[i]);
            }
        }
      
     
        if(availablePrinter()){
      
            for(int i = availablePrinterCount; i>0;i--)
            {
             
                if(!preQ.isEmpty() && preQ.maximum().getPriority()>waitQ.maximum().getPriority())
                {
                   

                    Request rq = preQ.popMaximum();
                    assignPrinter(rq,systemTime);
                    results[count].setWaitTime(systemTime- rq.getRequestTime());
                    results[count].setRequestTime(rq.getRequestTime());
                    results[count].setId(rq.getId());
                    results[count].setPrinterId(rq.getPrinterId());
                   
                    count++;
                }
                else if(!waitQ.isEmpty() && preQ.maximum().getPriority()<=waitQ.maximum().getPriority())
                {
                 
                    Request rq = waitQ.popMaximum();
                    assignPrinter(rq,systemTime);
                    results[count].setWaitTime(systemTime- rq.getRequestTime());
                    results[count].setRequestTime(rq.getRequestTime());
                    results[count].setId(rq.getId());
                    results[count].setPrinterId(rq.getPrinterId());
                    count++;
                   
                }
            }
    
        }
        if(!availablePrinter()){
            for(int i = 0; i< preQ.getSize();i++)
            {
               
                waitQ.insert(preQ.popMaximum());
              
                
            }
        }
            
    
        if(count==10)
        {
            break;
        }

        systemTime++;
        
    }
    averageTime = calculateAverageWaitTime();
  
    
}

double Simulator::calculateAverageWaitTime()
{   
    double avg = 0;
    for(int i = 0; i<requestCount;i++)
    {
        avg+=results[i].getWaitTime();
    }
    return avg/requestCount;

}



Simulator::~Simulator()
{
    delete[] requests;
    delete[] results;
    delete[] printers;
}



