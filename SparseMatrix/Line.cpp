template <class T>
Line<T>::Line()
{
    this->columns = new AvlTree<T>();
}

template <class T>
AvlTree<T>* Line<T>::getColumns()
{
    return this->columns;
}
