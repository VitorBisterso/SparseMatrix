#ifndef LINE_HPP
#define LINE_HPP

#include "Node.hpp"
#include "AvlTree.hpp"

template <class T>
class Line
{
    public:
        Line();
        AvlTree<T>* getColumns();
    private:
        AvlTree<T>* columns;
};

#include "Line.cpp"

#endif // LINE_HPP
