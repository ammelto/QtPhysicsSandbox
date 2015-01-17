#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>

class Ball : public QGraphicsItem
{
public:
    Ball(qreal grams, qreal cm, QColor c, qreal pascals, qreal cof, bool mag);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

    ~Ball();
private:
    const qreal mass;
    const qreal elasticity;
    const qreal radius;
    const QColor color;
    const qreal friction;
    bool magnetic;
};

#endif // BALL_H
