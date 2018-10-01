#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.hpp"

#include <iostream>

using namespace std;

template <class T>
class AvlTree
{
    public:
        AvlTree();
        Node<T>* getRoot();

        void add(T);
        void remove(T);
        bool has(T);

        void printTree(ostream&);
    private:
        Node<T>* root;
};

#include "AvlTree.cpp"

#endif // AVLTREE_H
