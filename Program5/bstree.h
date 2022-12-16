/*
FileName: bstree.h
Description: header and implementation of binary search tree
Created On: November 7th, 2022
Author: Hannah Pham
Course: CSS 342 B Fall 22
Instructor: Robert Dimpsey
*/
#include "account.h"
#include <iostream>

#ifndef BSTREE_H_
#define BSTREE_H_

class BSTree
{
private:
    struct Node
    {
        Account *p_acct;
        Node *right;
        Node *left;

        Node(Account *acct)
        {
            p_acct = acct;
            right = nullptr;
            left = nullptr;
        };
    };

    Node *root;
    int count_ = 0;

    void destroy_tree(Node *current);

public:
    BSTree();

    BSTree(const BSTree &tree);
    ~BSTree();

    BSTree &operator=(const BSTree &tree) const;

    bool Insert(Account *account);

    bool insert_(Account *account, Node *&p_node);

    int Count() const;

    bool Delete(int account_id);

    bool delete_(int account_id, Node *&p_node);

    bool Retrieve(int account_id, Account *&account) const; // pointer by reference

    bool retrieve_(Node *p_node, const int account_id, Account *&account) const;

    Node *copy(const BSTree::Node *node);
};

#endif