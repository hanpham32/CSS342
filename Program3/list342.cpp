#include "list342.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    List342<string> list;
    cout << "hello world" << endl;
    return 0;
}

template <class T>
List342<T>::List342() : head_(nullptr)
{
}

// template <class T>
// List342<T>::List342(const List342 &source)
// {
// }

// template <class T>
// List342<T> &List342<T>::operator=(const List342<T> &source)
// {
// }

/// @brief open and read objects from a file and build an ordered list
/// no duplicate item allowed
/// @tparam T
/// @param file_name
/// @return true if read successfully
template <class T>
bool List342<T>::BuildList(string file_name)
{
    // fstream newfile;
    // newfile.open(file_name, ios::in);
    // if (newfile.is_open())
    // {
    //     string tp;
    //     while (getline(newfile, tp))
    //     {
    //         cout << tp << " ";
    //     }
    //     newfile.close();
    //     return true;
    // }
    // return false;
}

// template <class T>
// ostream &operator<<(ostream &stream, List342<T> &list)
// {
// }