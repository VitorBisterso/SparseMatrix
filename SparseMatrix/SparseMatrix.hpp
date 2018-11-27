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

        T get(int, int) const;
        void put(int, int, T);

        template <class U>
        friend ostream& operator<<(ostream&, const SparseMatrix<U>&);
    private:
        AvlTree<Line<T> >* lines;
        T standardValue;

        int maxLine, maxColumn;
};

#include "SparseMatrix.cpp"

#endif // SPARSEMATRIX_HPP
