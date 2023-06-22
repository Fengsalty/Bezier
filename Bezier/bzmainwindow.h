#ifndef BZMAINWINDOW_H
#define BZMAINWINDOW_H

#include <QLabel>
#include <QMainWindow>

namespace Ui {
class BzMainWindow;
}

class BzMainWindow : public QMainWindow
{
    Q_OBJECT
    QLabel statusText;
public:
    explicit BzMainWindow(QWidget *parent = 0);
    ~BzMainWindow();
    void contextMenuEvent(QContextMenuEvent *event);
private slots:
    void updateStatus(QPoint pt);
private:
    Ui::BzMainWindow *ui;
};

#endif // BZMAINWINDOW_H
