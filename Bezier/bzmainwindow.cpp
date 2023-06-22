#include "bzmainwindow.h"
#include "ui_bzmainwindow.h"
#include <QContextMenuEvent>
BzMainWindow::BzMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BzMainWindow)
{
    ui->setupUi(this);
    statusText.setText("X=... Y=...");
    statusBar()->addWidget(&statusText);
    connect(ui->bzview,SIGNAL(mousePos(QPoint)),SLOT(updateStatus(QPoint)));
}

BzMainWindow::~BzMainWindow()
{
    delete ui;
}

void BzMainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.insertAction(nullptr,ui->actionEffacer);
    menu.insertAction(nullptr,ui->actionConstruire);
    menu.exec(event->globalPos());
}

void BzMainWindow::updateStatus(QPoint pt)
{
    statusText.setText(QString("X=%1 Y=%2").arg(pt.x()).arg(pt.y()));
}
