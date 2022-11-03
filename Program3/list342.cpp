#include "list342.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
List342<T>::List342() : head_(nullptr)
{
}

template <class T>
List342<T>::List342(const List342 &source)
{
}

template <class T>
List342<T> &List342<T>::operator=(const List342<T> &source)
{
}

/// @brief open and read objects from a file and build an ordered list
/// no duplicate item allowed
/// @tparam T
/// @param file_name
/// @return
template <class T>
bool List342<T>::BuildList(string file_name)
{
}

template <class T>
ostream &operator<<(ostream &stream, List342<T> &list)
{
}