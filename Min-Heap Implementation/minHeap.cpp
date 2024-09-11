#include <iostream>
#include "minHeap.h"
using namespace std;

//function which maintains min heap property by moving the element towards up direction
void minHeap::siftUp(int pos) {
    //variables for the function
    int parent = (pos-1)/2; //parent
    int child = pos; //child

    //compare the parents 
    while(child!=0 && heap[parent] > heap[child]) {
        //swapping child with parent
        int temp = heap[parent]; 
        heap[parent] = heap[child];
        heap[child] = temp;

        //make current parent as child
        child = parent;  
        //make new parent 
        parent = (parent-1)/2; 
    }
}

//function that sifts a value down through the heap until found the appropriate spot
void minHeap::siftDown(int pos) {
    //declares the parent
    int parent = pos; 

    //declares the left child 
    int child1 = 2*parent + 1;
    
    //declares the right child
    int child2 = 2*parent + 2;

    //declares who to swap the parent with
    int childSwap = -1;   

    //checks the left child
    if(child1 < (int)heap.size() && heap[child1] < heap[parent]) {
        //sets the childSwap to the left child
        childSwap=child1;
    }

    //checks the right child
    if(child2 < (int)heap.size() && heap[child2] < heap[parent]) {
        //if childSwap is -1
        if (childSwap == -1) {
            childSwap = child2;
        }
        else {
            //takes the min of the left and right child
            if (heap[child2] < heap[child1]) {
                childSwap=child2; 
            }
        }
    }
 
    //do not need to swap
    if(childSwap == -1) {
        return; 
    }
 
    //swapping parent with child_to_swap
    int temp=heap[parent];    

    heap[parent]= heap[childSwap];

    heap[childSwap] = temp;

    //calling recursively shiftDown on child_to_swap
    siftDown(childSwap); 
}

//function that finds the min heap
minHeap :: minHeap(vector<int> data) {
    //clears the heap
    heap.resize(0); 

    //for loop that fills the heap vector
    for(int i=0;i<(int)data.size();i++) {
        heap.push_back(data[i]); 
    }

    //for loop that inserts in bottom up manner by using siftDown
    for(int i=heap.size()-1;i>=0;i--) {
        siftDown(i); 
    } 

}

//function that inserts a value into the heap
void minHeap::insert(int value) {
    //inserting at end of heap array
    heap.push_back(value);  

    //declare and set the position 
    int position = heap.size()-1;

    //moves the last element in upward direction using siftup funciton
    siftUp(position); 
}

//function that removes the min
int minHeap::removeMin() {
    //when the heap is empty
    if(heap.size()== 0) {
        return -1;
    }

    //swapping  heap[0] with last element of heap array
    int temp = heap[0];   

    heap[0] = heap[heap.size()-1];

    heap[heap.size()-1] = temp;

    //removes the last element
    heap.pop_back(); 
 
    //moving heap[0] in downward direction to satisfy minheap property
    siftDown(0); 

    //return statement 
    return temp; 
}

// int main()

// {

//     minHeap m;

//     m.insert(5);

//     m.insert(11);

//     m.insert(7);

//     m.insert(9);

//     m.insert(2);

//     vector<int> HEAP = m.getHeap();

//     cout<<"HEAP: ";

//     for(int i=0;i<5;i++) cout<<HEAP[i]<<" ";

//     cout<<endl;

//     for(int i=0;i<5;i++) cout<< m.removeMin()<<" ";

//     cout<<endl;

 

//     vector<int> temp= {14,19,2,36,23,15,17,18,11,5,10,19,20,13,15,17};

//     minHeap m2(temp);

//     HEAP = m2.getHeap();

//     cout<<"HEAP: ";

//     for(int i=0;i<(int) temp.size();i++) cout<<HEAP[i]<<" ";

//     cout<<endl;

//     for(int i=0;i<(int)temp.size();i++) cout<< m2.removeMin()<<" ";

//     cout<<endl;

// }