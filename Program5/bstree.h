#include "account.h"
#include <iostream>

#ifndef BSTREE_H_
#define BSTREE_H_

class BSTree
{
    // friend std::ostream &operator<<(std::ostream &os, const BSTree &tree);
private:
    struct Node
    {
        Account *p_acct;
        Node *right;
        Node *left;
    };
    Node *root_ = nullptr;
    int count_ = 0;

public:
    BSTree()
    {
    }

    BSTree(const BSTree &tree);
    ~BSTree();

    BSTree &operator=(const BSTree &tree) const;

    friend std::ostream &operator<<(std::ostream &os, const BSTree &tree)
    {
    }

    void Traverse(Node *root)
    {
        if (root_ == nullptr)
            return;

        Traverse(root_->left);
        std::cout << root_->(*p_acct) << " ";
        Traverse(root_->right);
    }

    void Insert(int account_id, Account *account)
    {
        if (root_ == nullptr)
        {
            Node *ins_node = new Node();
            root_ = ins_node;
        }
    }

    int Count() const
    {
        return count_;
    }

    bool Delete(int account_id);
    bool Retrieve(int account_id, Account *&account) const; // pointer by reference
    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    // Delete object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    // displays the contents of a tree to cout; you could also overload
    void Display() const;
};

#endif