#ifndef SPARSEMATRIX_HPP
#define SPARSEMATRIX_HPP

#include "Node.hpp"
#include "AvlTree.hpp"
#include "Line.hpp"

template <class T>
class SparseMatrix
{
    public:
        SparseMatrix(T);

        T get(unsigned int, unsigned int);
        void put(unsigned int, unsigned int, T);
    private:
        AvlTree<Line<T> >* lines;
        T standardValue;
};

#include "SparseMatrix.cpp"

#endif // SPARSEMATRIX_HPP
