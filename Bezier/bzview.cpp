#include "bzview.h"

#include <QPainter>
#include<QDebug>
#include <QMouseEvent>
BzView::BzView(QWidget *parent) : QWidget(parent)
{
    nbPoints=0;
    affiche=false;
    capturedPoint=-1;
}

void BzView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPainterPath path(points[0]);
    path.cubicTo(points[1],points[2],points[3]);
    if(affiche&&nbPoints==4)
        painter.drawPath(path);
    QPen pen(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);


    for(int i=0;i<nbPoints;i++)
        painter.drawEllipse(points[i],6,6);
}

void BzView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if(nbPoints<4)
        {
            points[nbPoints]=event->pos();
            nbPoints++;
            update();

        }
        else
        {
            for(int i=0;i<nbPoints;i++)
            {
                QPoint dPt=points[i]-event->pos();
                int d2=dPt.x()*dPt.x()+dPt.y()*dPt.y();
                if(d2<=6*6)
                {
                    capturedPoint=i;
                    points[i]=event->pos();
                    update();
                    break;
                }
            }
        }
    }
}

void BzView::mouseMoveEvent(QMouseEvent *event)
{
    mousePos(event->pos());
    if(capturedPoint>-1 &&  points[capturedPoint]!=event->pos())
    {
        points[capturedPoint]=event->pos();
        update();
    }
}
void BzView::mouseReleaseEvent(QMouseEvent *event)
{
    capturedPoint=-1;
}
void BzView::onEffacer()
{
    nbPoints=0;
    qDebug()<<"Effacer";
    update();
}

void BzView::onConstruire(bool checked)
{
    qDebug()<<"Construire"<<checked;
    affiche=checked;
    update();
}
