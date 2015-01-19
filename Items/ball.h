#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>

class Ball : public QGraphicsItem
{
public:
    Ball(int type);

    void setProperties(int type);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

    ~Ball();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);

private:
    enum categories{plastic,rubber,ice};
    qreal mass;
    qreal elasticity;
    qreal radius;
    QColor color;
    qreal friction;
    bool magnetic;
};

#endif // BALL_H
