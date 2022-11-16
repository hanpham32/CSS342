#ifndef SORTS_H_
#define SORTS_H_
#include <iostream>
#include <vector>

/*
[] Merge
[] MergeSort
[] BubbleSort
[] InsertionSort
[] QuickSort
*/
class Sorts
{
public:
    void Merge(std::vector<int> &vec, int first, int mid, int last);
    void MergeSort(std::vector<int> &vec, int first, int last);
    void InsertionSort(std::vector<int> &vec);

private:
};

#endif

void Sorts::InsertionSort(std::vector<int> &vec)
{
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
        }
    }
}

/// @brief Merge a sorted array
/// @param vec
/// @param first
/// @param mid
/// @param last
void Sorts::Merge(std::vector<int> &vec, int first, int mid, int last)
{
    int size = last - first + 1;
    int *tmp_arr;
    tmp_arr = new int[size];

    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int index = 0;

    while ((first1 <= last1) && (first2 <= last2))
    {
        if (vec[first1] < vec[last2])
        {
            tmp_arr[index] = first1;
            first1++;
        }
        else
        {
            tmp_arr[index] = first2;
            first2++;
        }
        index++;
    }

    while (first1 <= last1)
    {
        tmp_arr[index] = vec[first1];
        index++;
        first1++;
    }

    while (first2 <= last2)
    {
        tmp_arr[index] = vec[first2];
        index++;
        first2++;
    }

    for (int i = 0; i < size; i++)
    {
        vec[first] = tmp_arr[i];
        first++;
    }
    delete[] tmp_arr;
}

void Sorts::MergeSort(std::vector<int> &vec, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(vec, first, mid);
        MergeSort(vec, mid + 1, last);
        Merge(vec, first, mid, last);
    }
}
