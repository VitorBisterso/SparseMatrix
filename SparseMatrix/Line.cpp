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

template <class T>
ostream& operator<<(ostream &os, const Line<T>& lines)
{
    os << *lines.columns;
    return os;
}
