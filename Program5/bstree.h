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

    void destroy_tree(Node *current)
    {
        if (current == nullptr)
        {
            return;
        }
        destroy_tree(current->left);
        destroy_tree(current->right);
        current->p_acct->print_account();
        delete (current);
    }

public:
    BSTree() : root(nullptr) {}

    BSTree(const BSTree &tree);
    ~BSTree()
    {
        destroy_tree(root);
        root = nullptr;
    }

    BSTree &operator=(const BSTree &tree) const;

    // friend std::ostream &operator<<(std::ostream &os, const BSTree &tree)
    // {
    //     return os;
    // }

    bool Insert(Account *account)
    {
        return insert(account, root);
    }

    bool insert(Account *account, Node *&p_node)
    {
        // Check if empty
        if (p_node == nullptr)
        {
            p_node = new Node(account);
            count_++;
            return true;
        }
        else if (account->id() < p_node->p_acct->id())
        {
            return insert(account, p_node->left);
        }
        else if (account->id() > p_node->p_acct->id())
        {
            return insert(account, p_node->right);
        }
        else
        {
            // The account is a duplicate
            return false;
        }
        return false;
    }

    int Count() const
    {
        return count_;
    }

    bool Delete(int account_id);
    bool Retrieve(int account_id, Account *&account) const // pointer by reference
    {
        // Empty tree
        if (root == nullptr)
        {
            return false;
        }

        Node *p_node = root;

        return retrieve(p_node, account_id, account);
    }

    bool retrieve(Node *p_node, const int account_id, Account *&account) const
    {
        // check if account exist
        if (p_node == nullptr)
        {
            return false;
        }
        if (account_id < p_node->p_acct->id())
        {
            return retrieve(p_node->left, account_id, account);
        }
        else if (account_id > p_node->p_acct->id())
        {
            return retrieve(p_node->right, account_id, account);
        }
        else
        {
            // found account
            account = p_node->p_acct;
            return true;
        }
    }
};

#endif