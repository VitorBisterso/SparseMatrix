template <class T>
SparseMatrix<T>::SparseMatrix(T standardValue)
{
    this->lines = new AvlTree<AvlTree<T>* >();
    this->standardValue = standardValue;
}

template <class T>
T SparseMatrix<T>::get(unsigned int line, unsigned int column)
{
    Node<T>* node = this->lines->has(line);
    if (node != NULL)
    {
        node = node->has(column);
        if (node != NULL)
            return node->getInfo();
    }

    return this->standardValue;
}

template <class T>
void SparseMatrix<T>::put(unsigned int line, unsigned int column, T value)
{

}
