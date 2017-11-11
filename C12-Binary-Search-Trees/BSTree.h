/*************************************************************************
 * File Name: btree.hpp
 ************************************************************************/

#ifndef BTREE_INCLUDED
#define BTREE_INCLUDED

#include <iostream>
#include <iomanip>

template <typename T>
class BSTree
{
    struct BinaryNode;
    public:
        BSTree(void): m_root{nullptr}
        {}
        ~BSTree()
        {
            delete_node(m_root);
        }
        bool empty(void) const
        {
            return m_root == nullptr;
        }
        bool find(const T& data) const;
        void insert(const T& data)
        {
            insert(m_root, data);
        }
        void remove(const T& data);

        void inorder(std::ostream& out) const
        {
            inorder(out, m_root);
        }
        void graph(std::ostream& out) const
        {
            graph(out, 0, m_root);
        }

    protected:
        BinaryNode* find_parent(BinaryNode* root, BinaryNode* node) const;
        void delete_node(BinaryNode* a_node);
        BinaryNode* insert(BinaryNode*& a_subRoot, const T& data);
        void inorder(std::ostream& out, BinaryNode* a_subRoot) const;
        void graph(std::ostream& out, int a_indent, BinaryNode* a_subRoot) const;
        void find2(const T& data, bool& found, BinaryNode*& a_locPtr, BinaryNode*& a_parent) const;
    private:
        struct BinaryNode
        {
            BinaryNode* left;
            BinaryNode* right;
            BinaryNode* succ;
            T data;
            BinaryNode():left(NULL), right(NULL), succ(NULL)
            {}
            BinaryNode(T data): data(data), left(NULL), right(NULL), succ(NULL)
            {}
        };
        BinaryNode* m_root;
};
#endif

template <typename T>
inline void BSTree<T>::delete_node(BinaryNode* a_node)
{
    if (a_node->left != NULL)
        delete_node(a_node->left);
    else if (a_node->right != NULL)
        delete_node(a_node->right);
    else if (a_node != NULL)
    {
        delete a_node;
        a_node = NULL;
    }
}

template <typename T>
inline typename BSTree<T>::BinaryNode* BSTree<T>::insert(BinaryNode*& a_subRoot, const T& data)
{
    if (a_subRoot == NULL)
    {
        a_subRoot = new BSTree<T>::BinaryNode(data);
        return a_subRoot;
    }
    else if (data < a_subRoot->data)
    {
        BinaryNode* inserted = insert(a_subRoot->left, data);
        if (a_subRoot->left == inserted)
            inserted->succ = a_subRoot;

        return inserted;
    }
    else if (a_subRoot->data < data)
    {
        BinaryNode* inserted = insert(a_subRoot->right, data);
        if (a_subRoot->right == inserted)
        {
            BinaryNode* tmp = a_subRoot->succ;
            a_subRoot->succ = inserted;
        }
        return inserted;
    }
    else
    {
        std::cerr << "data already in the tree!\n";
        return nullptr;
    }
}

template <typename T>
inline void BSTree<T>::inorder(std::ostream& out, BinaryNode* a_subRoot) const
{
    if (a_subRoot != NULL)
    {
        inorder(out, a_subRoot->left);//L
        out << a_subRoot->data << " ";//V
        inorder(out, a_subRoot->right);//R
    }
}

template <typename T>
inline void BSTree<T>::graph(std::ostream& out, int a_indent, BinaryNode* a_subRoot) const
{
    if (a_subRoot != NULL)
    {
        graph(out, a_indent+8, a_subRoot->right);                //R
        out << std::setw(a_indent) << " " << a_subRoot->data;    //V
        if(a_subRoot->succ)
            out <<"(" << a_subRoot->succ->data << ")";
        out << std::endl;
        graph(out, a_indent+8, a_subRoot->left);                    //L
    }
}

template <typename T>
inline bool BSTree<T>::find(const T& data) const
{
    BinaryNode* locPtr = m_root;
    bool found = false;
    while (!found && locPtr != NULL)
    {
        if (data < locPtr->data)
        {
            locPtr = locPtr->left;
        }
        else if (locPtr->data < data)
        {
            locPtr = locPtr->right;
        }
        else
        {
            found = true;
        }
    }
    return found;
}

template <typename T>
inline void BSTree<T>::find2(const T& data, bool& found, BinaryNode*& a_locPtr, BinaryNode*& a_parent) const
{
    a_locPtr = m_root;
    a_parent = NULL;
    found = false;
    while (!found && a_locPtr != NULL)
    {
        if (data < a_locPtr->data)
        {
            a_parent = a_locPtr;
            a_locPtr = a_locPtr->left;
        }
        else if (a_locPtr->data < data)
        {
            a_parent = a_locPtr;
            a_locPtr = a_locPtr->right;
        }
        else
        {
            found = true;
        }
    }
}
template <typename T>
inline typename BSTree<T>::BinaryNode* BSTree<T>::find_parent(BinaryNode* root, BinaryNode* node) const
{
    if(root)
    {
        if ( root->left == node || root->right == node)
            return root;
        if(node->data < root->data)
            return find_parent(root->left, node );
        else
            return find_parent(root->right, node );
    }
    else
        return nullptr;
}

template <typename T>
inline void BSTree<T>::remove(const T& data)
{
    bool found = false;
    BinaryNode* x;
    BinaryNode* parent;
    find2(data,found,x,parent);
    if (!found)
    {
        std::cerr << "data is not in the tree!\n";
        return;
    }

    if (x->left != NULL && x->right != NULL)
    {
        BinaryNode* xSucc = x->right;
        parent = x;
        while (xSucc->left != NULL)
        {
            parent = xSucc;
            xSucc = xSucc->left;
        }
        x->data = xSucc->data;
        x = xSucc;
    }
    BinaryNode* subTree = x->left;
    if (subTree == NULL)
    {
        subTree = x->right;
    }
    if (parent == NULL)
    {
        m_root = subTree;
    }
    else if (parent->left == x)
    {
        parent->left = subTree;
    }
    else
    {
        parent->right = subTree;
    }
    delete x;
}

