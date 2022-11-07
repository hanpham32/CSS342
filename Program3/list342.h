/*
Program 3 - CSS342
Hannah Pham
Date: 11/11/22
List342.h
*/
#include <string>
#include "child.h"
#include <iostream>
#include <fstream>
using namespace std;

#ifndef LIST342_H_
#define LIST342_H_

template <class T>
struct Node
{
    T *data;
    Node<T> *next = nullptr;
};

template <class T>
class List342
{

public:
    List342();
    List342(const List342<T> &source);
    // ~List342();

    bool BuildList(string file_name);
    bool Insert(T *obj);
    bool Remove(T target, T &result);
    bool Peek(T target, T &result) const;
    int Size() const;
    void DeleteList();
    bool Merge(List342<T> &list1);

    List342<T> operator+(List342<T> &rhs);
    List342<T> operator+=(const List342<T> &rhs);

    template <class U>
    friend ostream &operator<<(ostream &stream, const List342<U> &list);
    bool operator==(const List342<T> &rhs) const;
    bool operator!=(const List342<T> &rhs) const;
    List342<T> &operator=(const List342<T> &rhs);

private:
    Node<T> *head_;
};
#endif

template <class T>
List342<T>::List342() : head_(nullptr)
{
}

// template <class T>
// List342<T>::List342(const List342 &source)
// {
//     return;
// }

// template <class T>
// List342<T> &List342<T>::operator=(const List342<T> &rhs)
// {
//     return;
// }

template <class T>
ostream &operator<<(ostream &stream, const List342<T> &list)
{
    Node<T> *p_node = list.head_;
    while (p_node->next != nullptr)
    {
        stream << p_node->data << " ";
        p_node = p_node->next;
    }
    return stream;
}

/// @brief open and read objects from a file and build an ordered list; no duplicate item allowed
/// @tparam T
/// @param file_name
/// @return true if read successfully
template <class T>
bool List342<T>::BuildList(string file_name)
{
    fstream newfile;
    newfile.open(file_name, ios::in);
    if (newfile.is_open())
    {
        string tp;
        while (getline(newfile, tp))
        {
            cout << tp << " ";
        }
        newfile.close();
        return true;
    }
    return false;
}

/// @brief Insert an object to List342
/// @tparam T
/// @param obj
/// @return true if successfullly inserted, otherwise false
template <class T>
bool List342<T>::Insert(T *obj)
{
    cout << "helloo" << endl;
    Node<T> *ins_node = new Node<T>();
    ins_node->data = obj;
    cout << obj->getName() << endl;
    ins_node->next = head_;
    head_ = ins_node;
    return true;
}