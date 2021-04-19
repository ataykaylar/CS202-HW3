

#include "heap.h"


Heap::Heap() //constructor which initalizes the size to zero
{
    size = 0;
    items[0].setId(-1);
    items[0].setPriority(-1);
    items[0].setRequestTime(-1);
    items[0].setProcessTime(-1);
}

int Heap::getSize() const //returns the size of the array to the caller
{
    return size;
}

void Heap::getItems(Request * returnItems) //transfers the array to the caller
{
    for (int i = 0; i< size;i++)
    {
        returnItems[i] = items[i];
    }
}



bool Heap::isEmpty() const //returns boolean values according to the size
{
    return (size == 0);
}

void Heap::insert(const Request a) //inserts the item to its corresponding location
{
    if (size >= MAX_HEAP)
    {
        cout <<"Heap is full"<<endl;
        return;
    }

    // Place the new item at the end of the heap
    items[size] = a;

    // Trickle new item up to its proper position
    int place = size;
    int parent = (place - 1)/2;
    while ((place > 0) && (items[place].getPriority() > items[parent].getPriority()) )
    {
        Request temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }

   
    ++size;
}

Request Heap::popMaximum() //returns the maximum value in the array, which is the root, and deletes it
{
    Request maximum;
  
    if (isEmpty())
    {
        //cout<<"Heap is empty"<<endl;
        maximum.setId(-1);
        maximum.setPriority(-1);
        maximum.setRequestTime(-1);
        maximum.setProcessTime(-1);
        return maximum;
    }
    else
    {
        maximum = items[0];
        items[0] = items[--size];
        heapRebuild(0);

    }
    return maximum;
}

void Heap::heapRebuild(int root) //rebuilds with swapping down the smaller value
{
    int child = 2 * root + 1; 
    if (child < size)
    {
      
        int rightChild = child + 1;

        if ((rightChild < size) && (items[rightChild].getPriority() >items[child].getPriority())) //if the right child is bigger, child becomes right child
        {
          
            child = rightChild;
        }

        if (items[root].getPriority() < items[child].getPriority()) //if the child is bigger swap 
        {
        
            Request temp = items[root];
            items[root] = items[child];
            items[child] = temp;


            heapRebuild(child);
        }
        if (items[root].getPriority() == items[child].getPriority()&&items[root].getRequestTime() > items[child].getRequestTime()) 
        {
        
            Request temp = items[root];
            items[root] = items[child];
            items[child] = temp;


            heapRebuild(child);
        }
    }
}

Request Heap::maximum() //returns the maximum value, which is the root
{
    return items[0];

}

void Heap::printHeap()
{
    for (int i = 0; i<size;i++)
    {
        cout <<items[i].getId()<<" " <<items[i].getPriority()<<" "<<items[i].getRequestTime()<< " " <<items[i].getProcessTime()<<endl;;
    }

}

