#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_button_text(const QString text) {
    ui->hex_button->setText(text);
}

void MainWindow::on_hex_button_clicked()
{
    this->change_button_text("Hello, World!");
}

