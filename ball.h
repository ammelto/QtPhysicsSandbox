#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>

class Ball : public QGraphicsItem
{
public:
    Ball();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    ~Ball();
private:
    qreal weight;
    qreal elasticity;
    qreal size;
    QColor color;
};

#endif // BALL_H
