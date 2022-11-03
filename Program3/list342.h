/*
Program 3 - CSS342
Hannah Pham
Date: 11/11/22
List342.h
*/
#include <string>

#ifndef LIST342_H_
#define LIST342_H_

struct Node
{
    int value = 0;
    Node *next = nullptr;
};

template <class T>
class List342
{
public:
    List342();
    List342(const List342 &source);
    ~List342();

    bool BuildList(std::string file_name);
    bool Insert(T *obj);
    bool Remove(T target, T &result);
    bool Peek(T target, T &result) const;
    int Size() const;
    void DeleteList();
    bool Merge(List342 &list1);

    List342 operator+(List342 &rhs);
    List342 operator+=(const List342 &rhs);

    friend ostream &operator<<(ostream &stream, const List342 &list);
    bool operator==(const List342 &rhs) const;
    bool operator!=(const List342 &rhs) const;
    List342 &operator=(const List342 &source);

private:
    Node *head_;
};
#endif