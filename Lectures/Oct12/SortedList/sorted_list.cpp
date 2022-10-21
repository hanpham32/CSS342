#ifndef SORTED_LIST_CPP_
#define SORTED_LIST_CPP_
#include "sorted_list.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
SortedList<T>::SortedList()
{
    for (int i = 0; i < the_list_.size(); i++)
    {
        T temp = vect[i];
        int j = i;
        while ((j > 0) && vect[j - 1] > temp)
        {
            vect[j] = vect[j - 1];
            j--
        }
        vect[j] = temp;
    }
}

template <class T>
void SortedList<T>::Add(const T &item)
{
    the_list_.push_back(item);
}

template <class T>
void SortedList<T>::Print() const
{
    for (int i = 0; i < the_list_.size(); i++)
    {
        cout << the_list_[i] << endl;
    }
}

#endif