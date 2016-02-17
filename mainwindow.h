#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QAction>

#include "MedianFilter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    QMenuBar * fileMenu;//文件操作菜单栏
    QLabel * source_view;//源图片显示区
    QLabel * addNoise_view;//加噪图片显示区
    QLabel * destination_view;//去噪图片显示区

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void displaySource(QImage *);//显示源图像
    void displayNoise(QImage *);//显示添加噪声
    void displayResult(QImage *);//显示滤波结果


    MedianFilter *mf;

private:
    Ui::MainWindow *ui;

    QAction * openFile;//打开图片动作
    QAction * add;//添加噪声动作
    QAction * amf;//去除噪声动作


public slots:
    void open();//打开图片函数(具体操作)
    void addn();//添加噪声(具体操作)
    void cut();//去除噪声(具体操作)
};

#endif // MAINWINDOW_H
