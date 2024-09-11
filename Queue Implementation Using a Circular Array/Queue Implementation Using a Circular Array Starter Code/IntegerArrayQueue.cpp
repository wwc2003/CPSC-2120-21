#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value)
{
    if((back + 2) % size != front)
    {
        back = (back + 1) % (size);
        array[back] = value;
    }
    else{
        return false;
    }
}

int IntegerArrayQueue::dequeue()
{
    if(array[front] != 0)
    {
        int value = array[front];
        array[front] = 0;
        front = (front + 1) % (size);
        return value;
    }
    else
        return 0;
}