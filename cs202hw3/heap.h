#ifndef HEAP
#define HEAP


#include <iostream>
#include <fstream>
#include <iostream>
#include "request.h"
const int MAX_HEAP = 10000;
using namespace std;

class Heap{
    public:
        Heap();
        void insert(const Request a);
        Request maximum();
        Request popMaximum();
        bool isEmpty() const;
        int getSize() const;
        void getItems(Request * returnItems);
        void printHeap();


    protected:
        void heapRebuild(int root);


    private:
        
        Request items[MAX_HEAP];	// array of heap items
	    int size;            
    

};

#endif