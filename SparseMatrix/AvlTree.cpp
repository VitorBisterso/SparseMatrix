template<class T>
AvlTree<T>::AvlTree()
{
    this->root = NULL;
}

template<class T>
Node<T>* AvlTree<T>::getRoot()
{
    return this->root;
}

template<class T>
void AvlTree<T>::add(T info)
{
    if (this->root == NULL)
    {
        this->root = new Node<T>(info);
        return;
    }
    this->root->add(info);
}

template<class T>
void AvlTree<T>::remove(T info)
{
    this->root->remove(info);
    this->root->balance();
}

template<class T>
bool AvlTree<T>::has(T info)
{
    return this->root->has(info);
}

template<class T>
void AvlTree<T>::printTree(ostream &os)
{
    if (this->root != NULL)
        this->root->printTree(os);

    os << endl;
}
