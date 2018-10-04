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

        void add(unsigned int, T*);
        void remove(int);
        bool has(int);
        Node<T>* hasNode(int);
        template <class U>
        friend ostream& operator<<(ostream&, const AvlTree<U>&);
    private:
        Node<T>* root;
        /*void printTree(ostream&);*/
};

#include "AvlTree.cpp"

#endif // AVLTREE_H
