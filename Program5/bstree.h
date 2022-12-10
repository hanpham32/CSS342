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
    }

    BSTree &operator=(const BSTree &tree) const;

    friend std::ostream &operator<<(std::ostream &os, const BSTree &tree)
    {
        return os;
    }

    bool Insert(Account *account)
    {
        return insert(account, root);
    }

    bool insert(Account *account, Node *&p_node)
    {
        if (!p_node)
        {
            p_node = new Node(account);
            count_++;
            return true;
        }
        else if (account->id() < p_node->p_acct->id())
        {
            // If there is no left child, insert the node here.
            if (p_node->left == nullptr)
            {
                p_node->left = new Node(account);
                count_++;
                return true;
            }
            // Otherwise, insert the node recursively.
            else
            {
                insert(account, p_node->left);
            }
        }
        else if (account->id() > p_node->p_acct->id())
        {
            // If there is no right child, insert the node here.
            if (p_node->right == nullptr)
            {
                p_node->right = new Node(account);
                count_++;
                return true;
            }
            // Otherwise, insert the node recursively.
            else
            {
                insert(account, p_node->right);
            }
        }
        else
        {
            // the account is a duplicate
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
    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    // Delete object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    // displays the contents of a tree to cout; you could also overload

    // void AllAccounts() const
    // {
    //     Node *p_node = root;
    //     allaccounts(p_node);
    // }
    // void allaccounts(Node *p_node) const
    // {
    //     if (p_node == nullptr)
    //     {
    //         return;
    //     }
    //     allaccounts(p_node->left);
    //     allaccounts(p_node->right);
    //     p_node->p_acct->print_account();
    // }
};

#endif