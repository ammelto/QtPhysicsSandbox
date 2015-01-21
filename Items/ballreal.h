#ifndef BALLREAL_H
#define BALLREAL_H

#include <QGraphicsItem>

class BallReal : public QGraphicsItem
{
public:
    BallReal(int type);

    void setProperties(int type);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

    ~BallReal();

private:
    enum categories{plastic,rubber,ice};
    qreal mass;
    qreal elasticity;
    qreal radius;
    QColor color;
    qreal friction;
    bool magnetic;
};

#endif // BALLREAL_H
