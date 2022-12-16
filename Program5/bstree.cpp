#include "bstree.h"

BSTree::BSTree() : root(nullptr) {}

BSTree::BSTree(const BSTree &tree)
{
    Node *p_node = tree.root;
    if (p_node == nullptr)
    {
        root = nullptr;
    }
    root = copy(p_node);
}

BSTree::~BSTree()
{
    destroy_tree(root);
    root = nullptr;
}

bool BSTree::Insert(Account *account)
{
    return insert_(account, root);
}

bool BSTree::insert_(Account *account, Node *&p_node)
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
        return insert_(account, p_node->left);
    }
    else if (account->id() > p_node->p_acct->id())
    {
        return insert_(account, p_node->right);
    }
    else
    {
        // The account is a duplicate
        return false;
    }
    return false;
}

int BSTree::Count() const
{
    return count_;
}

bool BSTree::Delete(int account_id)
{
    Node *p_node = root;
    return delete_(account_id, p_node);
}

bool BSTree::delete_(int account_id, Node *&p_node)
{
    if (p_node == nullptr)
    {
        // Return false, account doesn't exist
        return false;
    }
    else if (account_id < p_node->p_acct->id())
    {
        return delete_(account_id, p_node->left);
    }
    else if (account_id > p_node->p_acct->id())
    {
        return delete_(account_id, p_node->right);
    }
    else // Account found
    {
        if (p_node->left && p_node->right)
        {
            Node *next_node = p_node->right;
            while (next_node->left != nullptr)
            {
                next_node = next_node->left;
            }
            p_node->p_acct = next_node->p_acct;
            return delete_(next_node->p_acct->id(), p_node->right);
        }
        else
        {
            Node *temp = p_node;
            if (p_node->left != nullptr)
            {
                p_node = p_node->left;
            }
            else
            {
                p_node = p_node->right;
            }
            delete temp;
            return true;
        }
    }
}

void BSTree::destroy_tree(Node *current)
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

bool BSTree::Retrieve(int account_id, Account *&account) const // pointer by reference
{
    // Empty tree
    if (root == nullptr)
    {
        return false;
    }

    Node *p_node = root;

    return retrieve_(p_node, account_id, account);
}

bool BSTree::retrieve_(Node *p_node, const int account_id, Account *&account) const
{
    // Check if account exist
    if (p_node == nullptr)
    {
        return false;
    }
    if (account_id < p_node->p_acct->id())
    {
        return retrieve_(p_node->left, account_id, account);
    }
    else if (account_id > p_node->p_acct->id())
    {
        return retrieve_(p_node->right, account_id, account);
    }
    else
    {
        // Found account
        account = p_node->p_acct;
        return true;
    }
}

BSTree::Node *BSTree::copy(const Node *p_node)
{
    if (p_node == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node *insert_node = new Node(p_node->p_acct);
        insert_node->left = copy(p_node->left);
        insert_node->right = copy(p_node->right);
        return insert_node;
    }
}