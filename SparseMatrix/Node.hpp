#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class Node
{
    public:
        Node(int, T);
        int getKey();
        void setKey(int);

        T getInfo();
        void setInfo(T);

        void add(int, T);
        void remove(int);
        Node<T>* has(int);
        void balance();

        template <class U>
        friend ostream& operator<<(ostream&, const Node<U>&);
    private:
        int key;
        T info;
        Node<T>* left;
        Node<T>* right;
        int factor;

        bool isLeaf();
        int getLastKey(unsigned int); //menor dos maiores -> 0; maior dos menores -> 1
        T getLastInfo(unsigned int);//

        void rotateLeft();
        void rotateRight();

        void doubleRotateLeft();
        void doubleRotateRight();

        void solveFactor();
        int height(int);

        /*void printTree(ostream&);*/
};

#include "Node.cpp"

#endif // NODE_H
