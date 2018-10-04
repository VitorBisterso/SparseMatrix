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

    Node<Line<T> >* lineNode = this->lines->hasNode(line);
    if (lineNode->getInfo()->getColumns()->getRoot() == NULL)
        return this->standardValue;

    Node<T>* columnNode = lineNode->getInfo()->getColumns()->hasNode(column);
    return *columnNode->getInfo();
}

template <class T>
void SparseMatrix<T>::put(unsigned int line, unsigned int column, T value)
{
    if (this->lines->hasNode(line) == NULL)
        this->lines->add(line, new Line<T>());

    Node<Line<T> >* lineNode = this->lines->hasNode(line);
    if (!lineNode->getInfo()->getColumns()->has(column))
        lineNode->getInfo()->getColumns()->add(column, &value);
    else
    {
        Node<T>* aux = lineNode->getInfo()->getColumns()->hasNode(column);
        aux->setInfo(&value);
    }
}
