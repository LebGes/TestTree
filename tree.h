#ifndef TREE_H
#define TREE_H

#include <QObject>

class Tree : public QObject {
    Q_OBJECT

public:
    explicit Tree(QObject* parent = nullptr);
    bool addNode(int parentId, const QString& name);
    bool removeNode(int id);
    bool editNode(int id, const QString& newName);
    void loadFromDatabase();

private:
    void initDatabase();
};

#endif // TREE_H
