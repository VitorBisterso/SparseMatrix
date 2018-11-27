template<class T>
AvlTree<T>::AvlTree()
{
    this->root = NULL;
    this->nodeCount++;
}

template<class T>
Node<T>* AvlTree<T>::getRoot()
{
    return this->root;
}

template<class T>
void AvlTree<T>::add(unsigned int key, T* info)
{
    if (this->root == NULL)
    {
        this->root = new Node<T>(key, info);
        return;
    }
    this->root->add(key, info);
    this->nodeCount++;
}

template<class T>
void AvlTree<T>::remove(int key)
{
    this->root->remove(key);
    if (this->root->getInfo() == NULL)
    {
        this->root = NULL;
        return;
    }
    this->root->balance();
    this->nodeCount--;
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
int AvlTree<T>::getNodeCount()
{
    return this->nodeCount;
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
