#include "account.h"
#include <iostream>

#ifndef BSTREE_H_
#define BSTREE_H_

class BSTree
{
    friend std::ostream &operator<<(std::ostream &os, const BSTree &tree);

public:
    BSTree();
    BSTree(const BSTree &tree);
    ~BSTree();

    BSTree &operator=(const BSTree &tree) const;

    int Count() const;
    bool Add(int account_id, Account *account);
    bool Delete(int account_id);
    bool Retrieve(int account_id, Account *&account) const; // pointer by reference
    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    // Delete object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    // displays the contents of a tree to cout; you could also overload
    void Display() const;
    int Size() const;

    bool Insert(Account *account);
    BSTree &operator=(const BSTree &tree);

private:
    struct Node
    {
        Account *p_acct;
        Node *right;
        Node *left;
    };
    Node *root_;
    int count_ = 0;
};

#endif