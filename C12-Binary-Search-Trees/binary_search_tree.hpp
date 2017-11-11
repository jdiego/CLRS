#ifndef BINARY_SEARCH_TREE_INCLUDED
#define BINARY_SEARCH_TREE_INCLUDED

#include <cstdio>
template< typename T>
class BinarySearchTree
{
    struct BinaryNode;
public:
    BinarySearchTree (void): m_root{nullptr}
    {}
    virtual ~BinarySearchTree()
    {
        make_empty(m_root);
        delete m_root;
    }
    bool find(const T& data) const
    {
        return find(m_root, data) != nullptr;
    }
    void insert(const T& data)
    {
        insert(m_root, data);
    }
    void inorder(void)
    {
        inorder(m_root);
    }
    void remove(const T& data)
    {
        auto* node = find(m_root, data);
        remove(m_root, node);
    }
protected:
    void make_empty(BinaryNode*& root)
    {
        if (root)
        {
            make_empty(root->left);
            make_empty(root->right);
            delete root;
        }
        root = nullptr;
    }

    void inorder(BinaryNode* root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            printf("Node : %d, ", root->data);
            if (root->parent == nullptr)
                printf("Parent : NULL \n");
            else
                printf("Parent : %d \n", root->parent->data);
            inorder(root->right);
        }
    }
    void insert(BinaryNode*& root, const T& data)
    {
        if (root == nullptr)
        {
            root = new BinaryNode(data);
        }
        else if (data < root->data)
        {
            insert(root->left, data);
            root->left->parent = root;
        }
        else if (data > root->data)
        {
            insert(root->right, data);
            root->right->parent = root;
        }
        else
            return;
    }
    void transplant(BinaryNode*& root, BinaryNode* u, BinaryNode* v)
    {
        if(u->parent == nullptr)
        {
            root = v;
        }
        else if(u->parent->left == u)
        {
            u->parent->left = v;
        }
        else
            u->parent->right = v;
        if(v)
            v->parent = u->parent;
    }
    BinaryNode* find_min(BinaryNode* node)
    {
        while(node->left)
        {
            node = node->left;
        }
        return node;
    }
    BinaryNode* find_max(BinaryNode* node)
    {
        while(node->right)
        {
            node = node->right;
        }
        return node;
    }

    void remove(BinaryNode*& root, BinaryNode* node)
    {
        if (node->left == nullptr)
            transplant(root, node, node->right);
        else if (node->right == nullptr)
            transplant(root, node, node->left);
        else
        {
            auto y = find_min(node->right);
            if(y->parent != node)
            {
                transplant(root, y, y->right);
                y->right = node->right;
                y->right->parent = y;
            }
            transplant(root, node, y);
            y->left = node->left;
            y->left->parent = y;
            delete node;
        }
    }
    BinaryNode* find(BinaryNode* root, const T& data) const
    {
        if (root == nullptr)
            return nullptr;
        else if (data < root->data)
            return find(root->left, data);
        else if (data > root->data)
            return find(root->right, data);
        else
            return root;
    }
private:
    /* data */
    struct BinaryNode
    {
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode* parent;
        T data;
        BinaryNode(void): left(nullptr), right(nullptr), parent(nullptr)
        {}
        BinaryNode(const T& data): data(data), left(nullptr), right(nullptr), parent(nullptr)
        {}
    };
    BinaryNode* m_root;

};
#endif /* ifndef BINARY_SEARCH_TREE_INCLUDED */
