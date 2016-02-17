#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    //获取UI实例
    fileMenu = ui->menuBar;
    source_view = ui->view1;
    destination_view = ui->view2;
    addNoise_view = ui->view3;

    //创建菜单栏动作
    openFile = new QAction("&Open", this);
    add = new QAction("&Add Noise", this);
    amf = new QAction("&Median Filter", this);

    //构建菜单栏
    fileMenu->addAction(openFile);
    fileMenu->addAction(add);
    fileMenu->addAction(amf);

    //链接菜单栏动作和响应函数
    connect(openFile, SIGNAL(triggered()), this, SLOT(open()));
    connect(add, SIGNAL(triggered()), this, SLOT(addn()));
    connect(amf, SIGNAL(triggered()), this, SLOT(cut()));
}

MainWindow::~MainWindow(){
    delete ui;
}

/*响应菜单操作函数（SLOT函数）
 */
//打开文件操作
void MainWindow::open(){
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"),"",
                                                tr("Images (*.png *.xpm *.jpg)"));
    if(!file.isNull()){
        QImage *cimage;
        cimage = new QImage(file);
        mf = new MedianFilter(cimage);
        displaySource(cimage);
    }
}

//添加噪声操作
void MainWindow::addn(){
    mf->addNoise();
    QImage cimage("addnoise.jpg");
    displayNoise(&cimage);
}

//去除噪声操作
void MainWindow::cut(){
    mf->AMF();
    QImage cimage("result.jpg");
    displayResult(&cimage);
}


/*显示图像函数
 */
//源图像
void MainWindow::displaySource(QImage *img){
    source_view->setPixmap(QPixmap::fromImage(*img));
}
//添加噪声图像
void MainWindow::displayNoise(QImage *img){
    addNoise_view->setPixmap(QPixmap::fromImage(*img));
}
//中值滤波后图像
void MainWindow::displayResult(QImage *img){
    destination_view->setPixmap(QPixmap::fromImage(*img));
}
