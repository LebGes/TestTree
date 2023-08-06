#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QTreeWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = new Tree(this);

    // Создаем элементы пользовательского интерфейса
    QLineEdit* lineEdit = new QLineEdit(this);
    QPushButton* addButton = new QPushButton("Add", this);
    QPushButton* editButton = new QPushButton("Edit", this);
    QPushButton* removeButton = new QPushButton("Remove", this);
    QPushButton* loadButton = new QPushButton("Load", this);

    // Связываем сигналы нажатия кнопок с соответствующими слотами
    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(editButton, &QPushButton::clicked, this, &MainWindow::onEditButtonClicked);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveButtonClicked);
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::onLoadButtonClicked);

    // Создаем и настраиваем главный компоновщик
    QGridLayout* layout = new QGridLayout;
    /*layout->addWidget(lineEdit);
    layout->addWidget(addButton);
    layout->addWidget(editButton);
    layout->addWidget(removeButton);
    layout->addWidget(loadButton);
    layout->addWidget(ui->treeWidget); // Предполагается, что QTreeWidget добавлен в Qt Designer*/

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddButtonClicked() {
    // Логика добавления элемента дерева
    int parentId = 0; // Предположим, что parentId по умолчанию 0
    QString name = ui->lineEdit->text(); // Получаем имя из поля ввода

    tree->addNode(parentId, name);
}

void MainWindow::onEditButtonClicked() {
    // Логика редактирования элемента дерева
    int id = 0; // Предположим, что id по умолчанию 0
    QString newName = ui->lineEdit->text(); // Получаем новое имя из поля ввода

    tree->editNode(id, newName);
}

void MainWindow::onRemoveButtonClicked() {
    // Логика удаления элемента дерева
    int id = 0; // Предположим, что id по умолчанию 0

    tree->removeNode(id);
}

void MainWindow::onLoadButtonClicked() {
    // Логика загрузки данных из базы данных и отображения их в интерфейсе
    tree->loadFromDatabase();
}
