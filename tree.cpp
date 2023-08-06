#include "tree.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Tree::Tree(QObject* parent) : QObject(parent) {
    initDatabase();
}

bool Tree::addNode(int parentId, const QString& name) {
    QSqlQuery query;
    query.prepare("INSERT INTO tree (parent_id, name) VALUES (:parent_id, :name)");
    query.bindValue(":parent_id", parentId);
    query.bindValue(":name", name);

    if (!query.exec()) {
        qDebug() << "Failed to add node:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Tree::removeNode(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM tree WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to remove node:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Tree::editNode(int id, const QString& newName) {
    QSqlQuery query;
    query.prepare("UPDATE tree SET name = :name WHERE id = :id");
    query.bindValue(":name", newName);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to edit node:" << query.lastError().text();
        return false;
    }

    return true;
}

void Tree::loadFromDatabase() {
    QSqlQuery query;
    query.prepare("SELECT id, parent_id, name FROM tree ORDER BY id");
    if (!query.exec()) {
        qDebug() << "Failed to load data:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        int parentId = query.value(1).toInt();
        QString name = query.value(2).toString();

        // Вывод информации об элементе в консоль с учетом его уровня в иерархии
        QString indentation = QString(parentId, ' '); // отступ от начала строки
        qDebug() << indentation << "ID:" << id << ", Name:" << name;
    }
}

void Tree::initDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("TreeDB.db");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS tree (id INTEGER PRIMARY KEY AUTOINCREMENT, parent_id INTEGER, name TEXT)");
}
