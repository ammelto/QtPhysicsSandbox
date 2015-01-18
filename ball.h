#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>

class Ball : public QGraphicsItem
{
public:
    Ball();

    void setProperties(int type);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

    ~Ball();
private:
    enum categories{plastic,rubber,ice};
    const qreal mass;
    const qreal elasticity;
    const qreal radius;
    const QColor color;
    const qreal friction;
    bool magnetic;
};

#endif // BALL_H
