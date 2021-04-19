/**
* Title: Heaps
* Author: Atay Kaylar
* ID: 21703284
* Assignment: 3
* Description: Heap sort algorithms and driver function of the project
*/



#include <iostream>
#include <fstream>
#include "simulator.h"
#include "request.h"
#include "printer.h"
#include "heap.h"


using namespace std;



int main(int argc, char **argv)
{
    ifstream file;
    file.open(argv[1]);
    int printerCount = 1;
    double avgTime;
    avgTime=atof(argv[2]);
    
    while(true)
    {
        Simulator s1(printerCount,avgTime,file); 
        s1.startSimulation();
        if(s1.returnAvgTime()<=avgTime)
        {
            s1.print();
            break;
        }
        printerCount++;
    }


    return 0;
}