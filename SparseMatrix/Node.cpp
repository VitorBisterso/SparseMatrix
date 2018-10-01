template<class T>
Node<T>::Node(T key)
{
    this->key = key;
    this->left = NULL;
    this->right = NULL;
    this->info = NULL;
    this->factor = 0;
}

template<class T>
void Node<T>::add(T key)
{
    if (key == this->key)
        throw "Tree can not have repeated information!";

    if (key < this->key)
    {
        this->factor--;
        if (this->left == NULL)
        {
            this->left = new Node<T>(key);
            return;
        }
        this->left->add(key);
    }
    else
    {
       this->factor++;
       if (this->right == NULL)
        {
            this->right = new Node<T>(key);
            return;
        }
        this->right->add(key);
    }
    this->balance();
}

template<class T>
int Node<T>::getLastKey(unsigned int i) //Menor dos maiores -> 0; Maior dos menores -> 1
{
    if (i == 0)
    {
        if (this->left == NULL)
            return this->key;
        this->left->getLastKey(0);
    }
    else
    {
        if (this->right == NULL)
            return this->key;
        this->right->getLastKey(1);
    }
}

template<class T>
void Node<T>::remove(T key)
{
    if(key == this->key)
    {
        if (this->isLeaf())
        {
            this->key = NULL;
            return;
        }
        else
        {
            if (this->left != NULL)
                key = this->left->getLastKey(1);
            else //direita tem que ser diferente de nula porque n eh folha e esquerda eh nula
                key = this->right->getLastKey(0);

            this->remove(key);
            this->setKey(key);
            this->solveFactor();
            return;
        }
    }
    else if (key < this->key)
    {
        this->left->remove(key);
        if (this->left->key == NULL)
        {
            delete this->left;
            this->left = NULL;
        }
    }
    else
    {
        this->right->remove(key);
        if (this->right->key == NULL)
        {
            delete this->right;
            this->right = NULL;
        }
    }

    this->solveFactor();
}

template<class T>
int Node<T>::getKey()
{
    return this->key;
}

template<class T>
void Node<T>::setKey(int key)
{
    this->key = key;
}

template<class T>
void Node<T>::balance()
{
    if (this->factor > 1)
    {
        if (this->right->factor < 0)
            this->doubleRotateLeft();
        else
            this->rotateLeft();
    }
    else if (this->factor < -1)
    {
        if (this->left->factor > 0)
            doubleRotateRight();
        else
            rotateRight();
    }

    this->solveFactor();
}

template<class T>
void Node<T>::rotateLeft()
{
    Node<T>* aux = this->right;
    this->right = aux->left;
    swap(*this, *aux);

    this->left = aux;
    aux->solveFactor();
}

template<class T>
void Node<T>::rotateRight()
{
    Node<T>* aux = this->left;
    this->left = aux->right;
    swap(*this, *aux);

    this->right = aux;
    aux->solveFactor();
}

template<class T>
void Node<T>::doubleRotateLeft()
{
    this->right->rotateRight();
    this->rotateLeft();
}

template<class T>
void Node<T>::doubleRotateRight()
{
    this->left->rotateLeft();
    this->rotateRight();
}

template<class T>
void Node<T>::solveFactor()
{
    int left = 0;
    if (this->left != NULL)
        left = this->left->height(0);

    int right = 0;
    if (this->right != NULL)
        right = this->right->height(0);

    this->factor = right - left;
}

template<class T>
int Node<T>::height(int height)
{
    int currentHeight = height + 1;
    int result = currentHeight;

    if (this->left != NULL)
    {
        int leftHeight = this->left->height(currentHeight);
        if (leftHeight > result)
            result = leftHeight;
    }

    if (this->right != NULL)
    {
        int rightHeight = this->right->height(currentHeight);
        if (rightHeight > result)
            result = rightHeight;
    }

    return result;
}

template<class T>
bool Node<T>::has(T key)
{
    if (key == this->key)
        return true;
    if (key < this->key)
    {
        if (this->left != NULL)
            this->left->has(key);
        else
            return false;
    }
    else if (this->right != NULL)
        this->right->has(key);
    else
        return false;
}

template<class T>
bool Node<T>::isLeaf()
{
    return (this->left == NULL && this->right == NULL);
}

template<class T>
void Node<T>::printTree(ostream &os)
{
    os << "(";
    if (this->left != NULL)
        this->left->printTree(os);

    os << this->info << ", " << this->factor;

    if (this->right != NULL)
        this->right->printTree(os);
    os << ")";
}

template <class T>
ostream& operator<<(ostream &os, const Node<T>& node)
{
    node.printTree(os);
    return os;
}
