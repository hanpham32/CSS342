/*
FileName: sorts.h
Author: Han Pham
Description: Implementation file for sort algorithms
Course: CSS342
Instructor: Robert Dimpsey
Created: Nov 16th, 2022
Last Modified:
*/

#ifndef SORTS_H_
#define SORTS_H_
#include <iostream>
#include <algorithm>
#include <vector>

/*
# List of sort algorithms:
## [x]: done; [~]: working; []: not started; [?]: bug found

[~] BubbleSort
[x] InsertionSort
[?] MergeSort
[] IterativeMergeSort (non-recursive)
[~] QuickSort
[] ShellSort
*/

class Sorts
{
public:
    void Merge(std::vector<int> &vec, int first, int mid, int last);
    void MergeSort(std::vector<int> &vec, int first, int last);
    void InsertionSort(std::vector<int> &vec, int first, int last);
    void QuickSort(std::vector<int> &vec, int first, int last);
    void PrintList(std::vector<int> &vec);

private:
};

#endif

void Sorts::PrintList(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void Sorts::QuickSort(std::vector<int> &vec, int first, int last)
{
    if (last - first < 5)
    {
        InsertionSort(vec, first, last);
    }
    int mid = (first + last) / 2;
    if (vec[first] > vec[last])
    {
        std::swap(vec[first], vec[last]);
    }
    if (vec[first] > vec[mid])
    {
        std::swap(vec[first], vec[mid]);
    }
    if (vec[mid] > vec[last])
    {
        std::swap(vec[mid], vec[last]);
    }
    int pivot = mid;
    std::swap(vec[mid], vec[last - 1]);
    int left = left + 1;
    int right = last - 2;
    bool done = false;
    while (!done)
    {
        while (vec[left] < pivot)
        {
            left++;
        }
        while (vec[right] > pivot)
        {
            right--;
        }
        if (right > left)
        {
            std::swap(vec[left], vec[right]);
            left++;
            right--;
        }
        else
        {
            done = true;
        }
        std::swap(vec[left], vec[last - 1]);
        QuickSort(vec, first, left - 1);
        QuickSort(vec, left + 1, last);
    }
}

void Sorts::InsertionSort(std::vector<int> &vec, int first, int last)
{
    int size = vec.size();
    for (int i = 1; i < size; i++)
    {
        if (vec[i] < vec[i - 1])
        {
            int index = i;
            while (vec[index] < vec[index - 1])
            {
                std::swap(vec[index], vec[index - 1]);
                index--;
            }
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
    int size_subarray_one = mid - first + 1;
    int size_subarray_two = last - mid;

    int *left_array = new int[size_subarray_one];
    int *right_array = new int[size_subarray_two];

    // Copy from vec to the sub_arrays
    for (int i = 0; i < size_subarray_one; i++)
    {
        left_array[i] = vec[first + i];
    }
    for (int j = 0; j < size_subarray_two; j++)
    {
        right_array[j] = vec[mid + 1 + j];
    }

    // Indexes
    int index_subarray_one = 0, index_subarray_two = 0;
    int index_merged_array = first;

    // PrintList(vec);
    // std::cout << "first: " << first << ", mid: " << mid << ", last: " << last << std::endl;

    while ((index_subarray_one <= size_subarray_one) && (index_subarray_two <= size_subarray_two))
    {
        if (vec[index_subarray_one] < vec[index_subarray_two])
        {
            vec[index_merged_array] = left_array[index_subarray_one];
            index_subarray_two++;
        }
        else
        {
            vec[index_merged_array] = right_array[index_subarray_two];
            index_subarray_two++;
        }
        index_merged_array++;
    }

    while (index_subarray_one <= size_subarray_one)
    {
        vec[index_merged_array] = left_array[index_subarray_one];
        index_merged_array++;
        index_subarray_one++;
    }

    while (index_subarray_two <= size_subarray_two)
    {
        vec[index_merged_array] = right_array[index_subarray_two];
        index_merged_array++;
        index_subarray_two++;
    }

    delete[] left_array;
    delete[] right_array;
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
