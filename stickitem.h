#ifndef STICKITEM_H
#define STICKITEM_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QTouchEvent>
#include <QFeedbackHapticsEffect>

QTM_USE_NAMESPACE

class StickItem : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit StickItem(bool fixX = false, bool fixY = false, QGraphicsItem *parent = 0, QObject *parentObject = 0);
    bool sceneEvent(QEvent *event);
    
signals:
     void stickUpdated(int x, int y);

private:
    QRectF *parentRect;
    QPointF initialZero;
    bool fixXaxis;
    bool fixYaxis;
    //QFeedbackHapticsEffect rumble;
};

#endif // STICKITEM_H
