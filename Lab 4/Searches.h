/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#pragma once

#include <vector>
#include <cstdlib>

template <class T>
int linearSearch(std::vector<T> data, T target){
    for(size_t i = 0; i < data.size(); i++)
    {
        if(data[i] == target)
        {
        return i;
        }
    }
    return -1;

}


template <class T>
int binarySearch(std::vector<T> data, T target){

     int high = data.size() - 1; 
    int low = 0;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(data[mid] == target)
            return mid;
        else if(data[mid] < target)
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return -1; 
}
