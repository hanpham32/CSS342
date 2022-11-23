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

[x] BubbleSort
[x] InsertionSort
[x] MergeSort
[x] IterativeMergeSort (non-recursive)
[x] QuickSort
[x] ShellSort
*/

static void InsertionSort(std::vector<int> &vec, int first, int last)
{
    for (int i = first; i <= last; i++)
    {
        int key = vec[i];
        int j = i - 1;

        while (j >= first && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

static void QuickSort(std::vector<int> &vec, int first, int last)
{
    // If subarray is less than 5, sort with InsertionSort
    if (last - first < 5)
    {
        InsertionSort(vec, first, last);
        return;
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
    int pivot = vec[mid];
    std::swap(vec[mid], vec[last - 1]);
    int left = first + 1;
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
    }
    std::swap(vec[left], vec[last - 1]);
    QuickSort(vec, first, left - 1);
    QuickSort(vec, left + 1, last);
}

static void Merge(std::vector<int> &vec, int first, int mid, int last)
{
    int size = last - first + 1;
    int *tmp_arr;
    tmp_arr = new int[size];
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int index = 0;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (vec[first1] < vec[first2])
        {
            tmp_arr[index] = vec[first1];
            first1++;
        }
        else
        {
            tmp_arr[index] = vec[first2];
            first2++;
        }
        index++;
    }
    while (first1 <= last1)
    {
        tmp_arr[index] = vec[first1];
        first1++;
        index++;
    }
    while (first2 <= last2)
    {
        tmp_arr[index] = vec[first2];
        first2++;
        index++;
    }
    for (index = 0; index < size; index++)
    {
        vec[first] = tmp_arr[index];
        first++;
    }
    delete[] tmp_arr;
}

static void MergeSort(std::vector<int> &vec, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(vec, first, mid);
        MergeSort(vec, mid + 1, last);
        Merge(vec, first, mid, last);
    }
}

static void IterativeMergeSort(std::vector<int> &vec, int first, int last)
{
    int curr_size;
    int left_start;

    for (curr_size = 1; curr_size <= last; curr_size = 2 * curr_size)
    {
        for (left_start = first; left_start < last; left_start += 2 * curr_size)
        {
            int mid = std::min(left_start + curr_size - 1, last);

            int right_end = std::min(left_start + 2 * curr_size - 1, last);

            Merge(vec, left_start, mid, right_end);
        }
    }
}

static void BubbleSort(std::vector<int> &vec, int first, int last)
{
    for (int i = first; i <= last; i++)
    {
        for (int j = first; j < last - i; j++)
        {
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j + 1]);
        }
    }
}

static void ShellSort(std::vector<int> &vec, int first, int last)
{
    for (int gap = last / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2))
    {
        for (int i = gap; i <= last; i++)
        {
            int tmp = vec[i];
            int j = i;
            for (; (j >= gap) && (tmp < vec[j - gap]); j -= gap)
            {
                vec[j] = vec[j - gap];
            }
            vec[j] = tmp;
        }
    }
}
#endif
