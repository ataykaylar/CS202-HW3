/**
* Title: Heaps
* Author: Atay Kaylar
* ID: 21703284
* Assignment: 3
* Description: Header file for the heap class
*/

#include <iostream>
#include <fstream>
#include <iostream>
#include "heap.h"
#include "printer.h"
#include "request.h"

using namespace std;


class Simulator
{
    public:
        Simulator(int printerCount, int maxAvgTime, ifstream& file);
        Simulator();
        ~Simulator();
        void readFileIntoArray(ifstream& file);
        bool availablePrinter();
        void updatePrinters(int t);
        void assignPrinter(Request &rq, int t);
        void startSimulation();
        void printSimulation();
        void print();
        void testHeap();
        double calculateAverageWaitTime();
        double returnAvgTime();
        

    private:
        int printerCount;
        int maxAvgTime;
        double averageTime;
        int requestCount;
        int systemTime;
        int availablePrinterCount;
        Printer *printers;
        Request *requests;
        Request *results;
        Heap preQ;
        Heap waitQ;

};








