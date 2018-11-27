template <class T>
SparseMatrix<T>::SparseMatrix(T standardValue)
{
    this->lines = new AvlTree<Line<T> >();
    this->standardValue = standardValue;
    this->maxLine = -1;
    this->maxColumn = -1;
}

template <class T>
T SparseMatrix<T>::get(int line, int column) const
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
void SparseMatrix<T>::put(int line, int column, T value)
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

        if (this->lines->hasNode(line)->getInfo() == NULL)
            this->lines->remove(line);
    }

    if (line > this->maxLine)
        this->maxLine = line;
    if (column > this->maxColumn)
        this->maxColumn = column; 
}

template <class T>
ostream& operator<<(ostream &os, const SparseMatrix<T>& matrix)
{
    if (matrix.maxLine > -1 && matrix.maxColumn > -1)
    {
        for (int i = 0; i < matrix.maxLine + 1; i++)
        {
            for (int j = 0; j < matrix.maxColumn + 1; j++)
                os << matrix.get(i, j) << "  ";
            
            os << endl;
        }
    }
    return os;
}
