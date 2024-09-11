/*
 * Name: Will Cooper
 * Date Submitted:2/20/2024
 * Lab Section:01
* Assignment Name: search sort
 */

#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>



template <class T>
std::vector<T> mergeSort(std::vector<T> lst)
{
   int mid = (lst.size() - 1) / 2;
   int currentIndex = 0;

   std::vector<T> half1;
   std::vector<T> half2;

   if(lst.size() <= 1)
   {
    return lst;
   }
   else
   {

    for(int i = 0; i <= mid; i++)
    {
        half1.push_back(lst[i]);
    }

    for(int i = mid + 1; i < lst.size(); i++)
    {
        half2.push_back(lst[i]);
    }


    half1 = mergeSort(half1);
    half2 = mergeSort(half2);

    int half1Index = 0;
    int half2Index = 0;

    while(half1Index < half1.size() && half2Index < half2.size())
    {
        if(half1[half1Index] < half2[half2Index]){
            lst[currentIndex] = half1[half1Index];
            ++half1Index;
        }
        else
        {
            lst[currentIndex] = half2[half2Index];
            ++half2Index;
        }
    
        ++currentIndex;
    }

    while(half1Index < half1.size()){
        lst[currentIndex] = half1[half1Index];
        ++half1Index;
        ++currentIndex;
    }

    while(half2Index < half2.size()){
        lst[currentIndex] = half2[half2Index];
        ++half2Index;
        ++currentIndex;
    }

    return lst;
   }

}


template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    T pivotValue;
    int pivotIndex = 0;
    bool notOrdered = false;

    for(int i = 1; i < lst.size(); i++)
    {
        if(lst[i-1] > lst[i]) {
            notOrdered = true;
        }
    }

    if(!notOrdered)
    {
        return lst;
    }
    else {
        srand(time(NULL));
        int randIndex = rand() % lst.size();

        std::swap(lst[0], lst[randIndex]);
        pivotValue = lst[0];
    

    for(int i = 1; i < lst.size(); i++)
    {
        if(lst[i] < pivotValue)
        {
            ++pivotIndex;
            std::swap(lst[pivotIndex], lst[i]);
        }
    }

    std::swap(lst[0], lst[pivotIndex]);

    std::vector<T> half1(lst.begin(), lst.begin() + (pivotIndex));
    std::vector<T> half2(lst.begin() + (pivotIndex), lst.end());

    half1 = quickSort(half1);
    half2 = quickSort(half2);

    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < lst.size(); i++)
    {
        if(count1 < half1.size())
        {
            lst[i] = half1[count1];
            ++count1;
        }
        else
        {
            lst[i] = half2[count2];
            ++count2;
        }
    }
}

return lst;
}
