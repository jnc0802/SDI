#include "headers/shapes.h"

Shapes::Shapes(){
    clicked=false;
    moving = false;
    resize = false;
    Px = 0;
    Py = 0;
    width = 100;
    height = 100;
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsFocusable);
    setFocus(Qt::MouseFocusReason);




}

QRectF Shapes::boundingRect() const
{
    return QRectF(Px,Py,width,height);
}

void Shapes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    rectangle = boundingRect();
    borderPen.setColor(Qt::red);

    if(clicked){
        borderPen.setColor(Qt::green);


    }else{
        borderPen.setColor(Qt::red);
    }

    if(resize){
        this->rectangle.setWidth(curr.x() - rectangle.x());
        this->rectangle.setHeight(curr.y() - rectangle.y());

    }

    //Draws the specified rectangle and text
    painter->setPen(borderPen);
    painter->drawRect(rectangle);
    painter->drawText(rectangle,Qt::AlignLeading,state);

}

void Shapes::setState(QString x)
{
    this->state = x;
}



void Shapes::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clicked = true;
    if(event->button() == Qt::LeftButton){
        moving = true;
    }
    if(event->button() == Qt::RightButton){
        resize = true;
    }


    update();
    event->accept();
}

void Shapes::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    clicked = false;
    moving = false;
    update();
    event->accept();
}

void Shapes::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    old = event->lastPos();
    curr = event->pos();
    int newX=curr.x()-old.x();
    int newY=curr.y()-old.y();





    if (moving){
        this->moveBy(newX,newY);
    }





    update();
    event->accept();
}

void Shapes::hoverEnterEvent(QGraphicsItem *event)
{
    this->borderPen.setColor(Qt::red);
    this->update();
}





