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
void AvlTree<T>::add(int key, T info)
{
    if (this->root == NULL)
    {
        this->root = new Node<T>(key, info);
        return;
    }
    this->root->add(key, info);
}

template<class T>
void AvlTree<T>::remove(int key)
{
    this->root->remove(key);
    this->root->balance();
}

template<class T>
Node<T>* AvlTree<T>::has(int key)
{
    return this->root->has(key);
}

template<class T>
ostream& operator<<(ostream &os, const AvlTree<T>& tree)
{
    if (tree.root != NULL)
        os << *tree.root;

    os << endl;
    return os;
}

/*template<class T>
void AvlTree<T>::printTree(ostream &os)
{
    if (this->root != NULL)
        os << *this->root;

    os << endl;
}*/
