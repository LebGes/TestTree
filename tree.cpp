#include "tree.h"

Tree::Tree(QString _name, Tree *_Parent)
{
    this->item.insert(count, _name);
    this->Parent = _Parent;
    count++;
}

void Tree::addChild(Tree *_Child)
{
    this->child.append(_Child);
    this->childCount++;
}


void Tree::getTree()
{
    for (int i = 0; i < count; i++)
    {

    }
}

void Tree::changeElement(size_t _id)
{

}

void Tree::deleteElement(size_t _id)
{

}

void Tree::deleteTree()
{

}

