#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddButtonClicked();
    void onEditButtonClicked();
    void onRemoveButtonClicked();
    void onLoadButtonClicked();

private:
    Ui::MainWindow *ui;
    class Tree* tree;
};

#endif // MAINWINDOW_H
