#ifndef SHAPES_H
#define SHAPES_H
#include <QPainter>
#include <QWidget>
#include <QCursor>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>



class Shapes : public QGraphicsItem
{
public:
    Shapes();
    bool moving;
    bool resize;
    bool clicked;
    QPointF curr;
    QPointF old;
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setState(QString x);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsItem* event);


private:

    QColor penColor;
    QPen borderPen;
    QRectF rectangle;
    QString state;
    qreal Px, Py;
    int width, height;
};

#endif // SHAPES_H
