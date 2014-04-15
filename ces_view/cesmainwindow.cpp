#include "cesmainwindow.h"
#include "ui_cesmainwindow.h"

cesMainWindow::cesMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cesMainWindow)
{
    ui->setupUi(this);
}

cesMainWindow::~cesMainWindow()
{
    delete ui;
}
