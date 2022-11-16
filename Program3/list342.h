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
#include <vector>
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
    ~List342();

    bool BuildList(string file_name);
    bool Insert(T *obj);
    bool Remove(T target, T &result);
    bool Peek(T target, T &result) const;
    int Size() const;
    void DeleteList();
    bool Merge(List342<T> &list1);
    bool Pop(T &value);
    bool isEmpty() const;

    // TODO
    List342<T> operator+(List342<T> &rhs);
    List342<T> &operator+=(const List342<T> &rhs);

    template <class U>
    friend ostream &operator<<(ostream &stream, const List342<U> &list);
    bool operator==(const List342<T> &rhs) const;
    bool operator!=(const List342<T> &rhs) const;
    void operator=(const List342<T> &rhs);

private:
    Node<T> *head_;
};
#endif

/// @brief List342 constructor
/// @tparam T
template <class T>
List342<T>::List342() : head_(nullptr)
{
}

/// @brief List342 destructor
/// @tparam T
template <class T>
List342<T>::~List342()
{
    T a;
    while (Pop(a))
        ;
}

// TODO
template <class T>
List342<T>::List342(const List342 &source) : head_(nullptr)
{
    *this = source;
}

// TODO
template <class T>
void List342<T>::operator=(const List342<T> &rhs)
{
    if (rhs.head_->next == nullptr)
    {
        this->Insert(rhs.head_->data);
    }
    else
    {
        Node<T> *p_node = rhs.head_;
        this->Insert(p_node->data);
        while (p_node->next != nullptr)
        {
            this->Insert(p_node->next->data);
            p_node = p_node->next;
        }
    }
}

template <class T>
List342<T> &List342<T>::operator+=(const List342<T> &rhs)
{
    if (rhs.head_ == nullptr)
    {
        return *this;
    }
    if (head_ == nullptr)
    {
        *this = rhs;
        return *this;
    }
    Node<T> *p_node = rhs.head_;
    while (p_node != nullptr)
    {
        this->Insert(p_node->data);
        p_node = p_node->next;
    }
    return *this;
}

template <class T>
List342<T> List342<T>::operator+(List342<T> &rhs)
{
    List342<T> result = *this;
    result += rhs;
    return result;
}

template <class T>
bool List342<T>::operator==(const List342<T> &rhs) const
{
    if (this->Size() != rhs.Size())
    {
        return false;
    }
    Node<T> *p_node_rhs = rhs.head_;
    Node<T> *p_node = head_;
    while ((p_node->next != nullptr) && (*p_node->next->data == *p_node_rhs->next->data))
    {
        p_node = p_node->next;
        p_node_rhs = p_node_rhs->next;
    }
    // reached the end of list
    if ((p_node->next == nullptr) && (p_node_rhs->next == nullptr))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool List342<T>::operator!=(const List342<T> &rhs) const
{
    if (*this == rhs)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
ostream &operator<<(ostream &stream, const List342<T> &list)
{
    Node<T> *p_node = list.head_;
    while (p_node != nullptr)
    {
        stream << *p_node->data;
        p_node = p_node->next;
    }
    return stream;
}

template <class T>
bool List342<T>::isEmpty() const
{
    if (Size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// @brief open and read objects from a file and build an ordered list; no duplicate item allowed
/// @tparam T
/// @param file_name
/// @return true if read successfully
template <class T>
bool List342<T>::BuildList(string file_name)
{
    ifstream in_file(file_name);
    if (in_file.is_open())
    {
        while (!in_file.eof())
        {
            T obj;
            in_file >> obj;
            T *new_obj = new T(obj);
            this->Insert(new_obj);
            delete new_obj;
        }
        in_file.close();
        return true;
    }
    else
    {
        cout << "File could not open!" << endl;
        return false;
    }
}

/// @brief pop the first value in the list
/// @tparam T
/// @param value
/// @return return by passed in reference
template <class T>
bool List342<T>::Pop(T &value)
{
    if (head_ == nullptr)
    {
        return false;
    }
    Node<T> *temp = head_;
    head_ = head_->next;
    value = (*temp->data);
    delete temp;
    return true;
}

// [x] check for duplicate
/// @brief Insert object to list in sorted order
/// @tparam T
/// @param *obj
/// @return true if successfullly inserted, otherwise false
template <class T>
bool List342<T>::Insert(T *obj)
{
    if (obj == nullptr)
    {
        return false;
    }
    // chekc if list is empty
    if (head_ == nullptr)
    {
        Node<T> *ins_node = new Node<T>();
        ins_node->data = obj;
        head_ = ins_node;
        return true;
    }
    // check for dup for first element
    if (*obj == *head_->data)
    {
        return false;
    }
    // check first element
    if (*obj < *head_->data)
    {
        Node<T> *ins_node = new Node<T>();
        ins_node->data = obj;
        ins_node->next = head_;
        head_ = ins_node;
        return true;
    }
    Node<T> *p_node = head_;
    while ((p_node->next != nullptr) && (*p_node->next->data < *obj))
    {
        p_node = p_node->next;
    }
    // check duplicate
    if ((p_node->next != nullptr) && (*p_node->next->data == *obj))
    {
        return false;
    }
    Node<T> *ins_node = new Node<T>();
    ins_node->data = obj;
    ins_node->next = p_node->next;
    p_node->next = ins_node;
    return true;
}

// [] Check for peeking non-existing
//   [] Segmentation fault core dumped with non-existing target
/// @brief Find target and update passed in reference result
/// @tparam T
/// @param target
/// @param result
/// @return true if found, false otherwise
template <class T>
bool List342<T>::Peek(T target, T &result) const
{
    if (head_ == nullptr)
    {
        return false;
    }
    if (*head_->data == target)
    {
        result = *head_->data;
        return true;
    }
    Node<T> *p_node = head_;
    while ((p_node->next != nullptr) && (*p_node->next->data != target))
    {
        p_node = p_node->next;
    }
    if (*p_node->next->data == target)
    {
        result = *p_node->next->data;
        return true;
    }
    return false;
}

/// @brief Delete all items in the list, include node(s) and item(s) being pointed
/// @tparam T
template <class T>
void List342<T>::DeleteList()
{
    T a;
    while (Pop(a))
        ;
}

/// @brief Return size of the list
/// @tparam T
/// @return size of list
template <class T>
int List342<T>::Size() const
{
    Node<T> *p_node = head_;
    if (p_node == nullptr)
    {
        return 0;
    }
    else
    {
        int count = 0;
        while (p_node != nullptr)
        {
            count++;
            p_node = p_node->next;
        }
        return count;
    }
}

// [x] Check for remove non-existing item
// [x] return if iterating target greater than p_node->next->data
/// @brief remove target value
/// @tparam T
/// @param target
/// @param result
/// @return return passed in reference if found
template <class T>
bool List342<T>::Remove(T target, T &result)
{
    if (head_ == nullptr)
    {
        return false;
    }
    if (*head_->data == target)
    {
        Node<T> *temp = head_;
        head_ = temp->next;
        result = *temp->data;
        delete temp;
        return true;
    }
    Node<T> *p_node = head_;
    while ((p_node->next != nullptr) && (*p_node->next->data != target) && (*p_node->next->data < target))
    {
        p_node = p_node->next;
    }
    if (*p_node->next->data > target)
    {
        return false;
    }
    // If reached the end of list
    if ((p_node->next == nullptr) && (*p_node->data == target))
    {
        result = *p_node->data;
        delete p_node;
        return true;
    }
    else if ((p_node->next == nullptr) && (*p_node->data != target))
    {
        return false;
    }
    else
    {

        Node<T> *next = p_node->next->next;
        result = *p_node->next->data;
        delete p_node->next;
        p_node->next = next;
        return true;
    }
}

template <class T>
bool List342<T>::Merge(List342<T> &list1)
{
    // if passed in list is empty
    if (list1.Size() == 0)
    {
        return false;
    }
    if (*this == list1)
    {
        return false;
    }
    T value;
    while (list1.Pop(value))
    {
        T *new_obj = new T(value);
        this->Insert(new_obj);
        delete new_obj;
    }
    return true;
}
