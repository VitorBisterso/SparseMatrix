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
        int getKey();
        void setKey(int);

        void add(T);
        void remove(T);
        bool has(T);
        void balance();

        friend ostream& operator<<(ostream&, const Node<T>&);
    private:
        int key;
        T info;
        Node<T>* left;
        Node<T>* right;
        int factor;

        bool isLeaf();
        int getLastKey(unsigned int); //menor dos maiores -> 0; maior dos menores -> 1

        void rotateLeft();
        void rotateRight();

        void doubleRotateLeft();
        void doubleRotateRight();

        void solveFactor();
        int height(int);

        void printTree(ostream&);
};

#include "Node.cpp"

#endif // NODE_H
