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
void AvlTree<T>::add(unsigned int key, T info)
{
    T* clone = new T(info);
    if (this->root == NULL)
    {
        this->root = new Node<T>(key, info);
        return;
    }
    if (!this->root->has(key))
        this->root->add(key, info);
}

template<class T>
void AvlTree<T>::remove(int key)
{
    if (this->root != NULL)
    {
        this->root->remove(key);
        if (this->root->getInfo() == NULL)
        {
            this->root = NULL;
            return;
        }
        this->root->balance();
    }
}

template<class T>
bool AvlTree<T>::has(int key)
{
    if (this->root == NULL)
        return false;

    return this->root->has(key);
}

template<class T>
Node<T>* AvlTree<T>::hasNode(int key)
{
    if (this->root != NULL)
        return this->root->hasNode(key);

    return NULL;
}

template<class T>
ostream& operator<<(ostream &os, const AvlTree<T>& tree)
{
    if (tree.root != NULL)
        os << *tree.root;
    else
        os << "(null)";

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
