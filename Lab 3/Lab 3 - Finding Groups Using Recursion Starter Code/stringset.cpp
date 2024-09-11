/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    if(!find(word)){
        int loc = hash<std::string>{}(word) % size;

        table[loc].push_back(word);

        ++num_elems;
    }

    if(size == num_elems){
        vector<list<string>> temp = table;
        table.clear();
        size = size * 2;
        table.resize(size);

        for(int i = 0; i != temp.size(); i++)
        {
            for(string str : temp[i]){
                int loc = hash<std::string>{}(str) % size;
                table[loc].push_back(str);
            }
        }
    }
}

bool Stringset::find(string word) const
{
    int loc = hash<std::string>{}(word) % size;
    for(auto it : table[loc])
    {
        if(it.compare(word) == 0)
        {
            return true;
        }
    }

    return false;
}

void Stringset::remove(string word)
{
    for(int i = 0; i < size; i++)
    {
        for(auto it : table[i])
        {
            if(it == word){
                table[i].remove(it);

                --num_elems;
                return;
            }
        }
    }
}