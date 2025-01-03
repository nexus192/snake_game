#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snakegamerender.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMinimumSize(600, 300);

    connect(ui->TetrisButton, &QPushButton::clicked, this, &MainWindow::Push_Button_Tetris);
    connect(ui->SnakeButton, &QPushButton::clicked, this, &MainWindow::Push_Button_Snake);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Push_Button_Tetris(){
    qDebug() << "pushed";
}

void MainWindow::Push_Button_Snake(){
    this->close();
    SnakeGameRender *field = new SnakeGameRender();
    field->setStyleSheet(
        "QWidget {"
        "   background-color: #18191C;"
        "   color: white;"
        "   border: 3px solid #2C2F36;"
        "   border-radius: 10px;"
        "}");
    field->setWindowTitle("Snake");

    field->resize(400, 400);

    field->show();
}

void MainWindow::Push_Button_Exit(){

}

void MainWindow::Spatial_Button(){


}

