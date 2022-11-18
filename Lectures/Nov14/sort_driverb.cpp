#include <iostream>
#include <vector>

void MergeSort(std::vector<int> &vec, int first, int last);
void Merge(std::vector<int> &vec, int first, int mid, int last);
void QuickSort(std::vector<int> &vec, int first, int last);
void InsertionSort(std::vector<int> &vec, int first, int last);

int main()
{
    return 0;
}

void Merge(std::vector<int> &vec, int first, int mid, int last)
{
    int size = last - first + 1;
    int *tmp_arr; // dynamic => a pointer is needed
    tmp_arr = new int[size];

    // set indexes for beginning and end of each subarray
    // how many indexes are in this program?
    //// ans = 5
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

void MergeSort(std::vector<int> &vec, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(vec, first, mid);
        MergeSort(vec, mid + 1, last);
        Merge(vec, first, mid, last);
    }
}

void QuickSort(std::vector<int> &vec, int first, int last)
{
    if (last - first < 5)
    {
        InsertionSort(vec, first, last);
        return;
    }
    int mid = (first + last) / 2;
    // sort first, mid, last values
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
        std::swap(vec[left], vec[last - 1]);
        QuickSort(vec, first, left - 1);
        QuickSort(vec, left + 1, last);
    }
}