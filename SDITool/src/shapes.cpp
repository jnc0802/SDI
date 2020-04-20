#include "headers/shapes.h"

Shapes::Shapes(){
    pressed=false;
    setFlag(ItemIsSelectable);
    setFlag(ItemIsMovable);
}

QRectF Shapes::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void Shapes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rectangle = boundingRect();
    QPen redPen(Qt::red);
    if(pressed){
        redPen.setColor(Qt::green);
    }else{
        redPen.setColor(Qt::red);
    }
    painter->setPen(redPen);
    painter->drawRect(rectangle);
}

void Shapes::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Shapes::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
