#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class Node
{
    public:
        Node(T);
        T* getInfo();
        void setInfo(T);

        void add(T);
        void remove(T);
        bool has(T);
        void balance();

        void printTree(ostream&);
    private:
        int key;
        T info;
        Node<T>* left;
        Node<T>* right;
        int factor;

        bool isLeaf();
        T getLastInfo(unsigned int); //menor dos maiores -> 0; maior dos menores -> 1

        void rotateLeft();
        void rotateRight();

        void doubleRotateLeft();
        void doubleRotateRight();

        void solveFactor();
        int height(int);
};

#include "Node.cpp"

#endif // NODE_H
