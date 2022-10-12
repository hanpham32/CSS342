// binary_search.cpp: This file contains the 'main' function. Program execution begins
// and ends here

#include <iostream>
#include <vector>
using namespace std;

const int kArrayLength = 50;
const int kMaxValue = 100;
int BinarySearch(int value, const vector<int>& arr, int index1, int index2);
void InsertionSort(vector<int>& arr);

int main()
{
    vector<int> arr(kArrayLength, 0);
    int val;

    //Create a vector full of random numbers and sort it
    for (int i=0; i<kArrayLength; i++)
    {
        arr[i] = rand() % kMaxValue;
    }
    InsertionSort(arr);

    while(true)
    {
        cout << "Input a value to search for: ";
        cin >> val;
        int index = BinarySearch(val, arr, 0, kArrayLength - 1);
        if (index == -1)
        {
            cout << "Value is not in array" << endl;
        } else
        {
            cout << "Value is at location " << BinarySearch(val, arr, 0, kArrayLength - 1) << endl;
        }

    }

}

int BinarySearch(int value, const vector<int>& arr, int index1, int index2)
{
    if (value == arr[index1])
    {
        return index1;
    } else if (value == arr[index2])
    {
        return index2;
    } else if (index2 <= index1 + 1)
    {
        return -1;
    } else 
    {
        int midpoint = (index1 + index2) / 2;
        if (arr[midpoint] > value)
        {
            return BinarySearch(value, arr, index1, midpoint);
        } else
        {
            return BinarySearch(value, arr, midpoint, index2);
        }
    }
}

void InsertionSort(vector<int>& arr)
{
    for (int i=1; i<arr.size(); i++)
    {
        int value = arr[i];
        bool inserted = false;
        for (int j=i; j > 0; j--)
        {
            if (value < arr[j - 1])
            {
                arr[j] = arr[j - 1];
            } else 
            {
                arr[j] = value;
                inserted = true;
                break;
            }
        }
        if (!inserted)
        {
            arr[0] = value;
        }
    }
}