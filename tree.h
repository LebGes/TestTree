#ifndef TREE_H
#define TREE_H
#include <qstring.h>
#include <QMap>
#include <QList>

class Tree
{
public:
    Tree(QString _name, Tree *_Parent = nullptr);
    virtual ~Tree();
    void addChild(Tree *_Child);
    void getTree();
    void changeElement(size_t _id);
    void deleteElement(size_t _id);
    void deleteTree();
private:
    Tree *Parent;
    QList <Tree*> child;
    static size_t count;
    QMap <size_t, QString> item;
    size_t childCount;
};

#endif // TREE_H
