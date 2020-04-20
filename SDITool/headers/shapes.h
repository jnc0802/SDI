#ifndef SHAPES_H
#define SHAPES_H
#include <QPainter>
#include <QDebug>
#include <QGraphicsItem>


class Shapes : public QGraphicsItem
{
public:
    Shapes();

    bool pressed;
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // SHAPES_H
