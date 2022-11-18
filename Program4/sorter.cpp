/*
FileName: sorter.cpp
Author: Han Pham
Description: Driver file for sorts.h
Course: CSS342
Instructor: Robert Dimpsey
Created: Nov 16th, 2022
Last Modified:
*/

#include "sorts.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    Sorts sorter;
    vector<int> vec{2, 8, 5, 3, 9, 4};

    cout << "before: ";
    sorter.PrintList(vec);

    sorter.MergeSort(vec, 0, vec.size());

    cout << "after: ";
    sorter.PrintList(vec);

    return 0;
}