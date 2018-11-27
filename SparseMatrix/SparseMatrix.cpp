template <class T>
SparseMatrix<T>::SparseMatrix(T standardValue)
{
    this->lines = new AvlTree<Line<T> >();
    this->standardValue = standardValue;
}

template <class T>
T SparseMatrix<T>::get(unsigned int line, unsigned int column)
{
    if (this->lines->getRoot() == NULL)
        return this->standardValue;

    if (this->lines->hasNode(line) == NULL)
        return this->standardValue;

    Node<Line<T> >* lineNode = this->lines->hasNode(line);
    if (lineNode->getInfo()->getColumns()->getRoot() == NULL)
        return this->standardValue;

    Node<T>* columnNode = lineNode->getInfo()->getColumns()->hasNode(column);
    if (columnNode != NULL)
        return *columnNode->getInfo();

    return NULL;
}

template <class T>
void SparseMatrix<T>::put(unsigned int line, unsigned int column, T value)
{
    T* clone = new T(value);
    bool remove = false;
    if (*clone == this->standardValue)
        remove = true;

    if (this->lines->hasNode(line) == NULL)
        this->lines->add(line, new Line<T>());

    Node<Line<T> >* lineNode = this->lines->hasNode(line);
    if (!lineNode->getInfo()->getColumns()->has(column) && !remove)
        lineNode->getInfo()->getColumns()->add(column, clone);
    else
    {
        if (!remove)
        {
            Node<T>* aux = lineNode->getInfo()->getColumns()->hasNode(column);
            aux->setInfo(clone);
            return;
        }
        if (lineNode->getInfo()->getColumns()->getRoot() != NULL)
            lineNode->getInfo()->getColumns()->remove(column);
    }
}

template <class T>
ostream& operator<<(ostream &os, const SparseMatrix<T>& matrix)
{
    os << *matrix.lines;
    return os;
}
