#include <iostream>

#include "Node.hpp"
#include "AvlTree.hpp"
#include "Line.hpp"
#include "SparseMatrix.hpp"

using namespace std;

int main()
{
    SparseMatrix<int>* matrix = new SparseMatrix<int>(0);
    matrix->put(0, 0, 16195);
    cout << matrix->get(0, 0) << endl;

    matrix->put(0, 0, 16168);
    cout << matrix->get(0, 0) << endl;
    return 0;
}
