template <class T>
SparseMatrix<T>::SparseMatrix(T standardValue)
{
    this->lines = new AvlTree<AvlTree<T> >();
    this->standardValue = standardValue;
    this->lines->add(standardValue);
}

template <class T>
T SparseMatrix<T>::get(unsigned int line, unsigned int column)
{

}

template <class T>
void SparseMatrix<T>::put(unsigned int line, unsigned int column, T value)
{

}
