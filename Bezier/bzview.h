#ifndef BZVIEW_H
#define BZVIEW_H

#include <QWidget>
#define NBPTS 4
class BzView : public QWidget
{
    Q_OBJECT
    int nbPoints; // Initialisé à 0 dans le constructeur
    QPoint points[NBPTS]; // Le tableau des points de contrôle
    bool affiche;
    int capturedPoint;
public:
    explicit BzView(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
void mousePos(QPoint pt);
public slots:
       void onEffacer();
       void onConstruire(bool checked);
};

#endif // BZVIEW_H
