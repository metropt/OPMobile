#include "stickitem.h"

#include <QSvgRenderer>
#include <QGraphicsSvgItem>

#define OFFSET 25

StickItem::StickItem(bool fixX, bool fixY, QGraphicsItem *parent, QObject *parentObject) :
    QObject(parentObject), QGraphicsEllipseItem(parent)
{
    setPos(0, 0);
    setRect(0,0,50,50);

    QSvgRenderer *m_renderer = new QSvgRenderer(this);
    m_renderer->load(QString(":/images/joystick.svg"));

    QGraphicsSvgItem *m_joystickEnd = new QGraphicsSvgItem(this);
    m_joystickEnd->setSharedRenderer(m_renderer);
    m_joystickEnd->setElementId(QString("joystickEnd"));
    m_joystickEnd->setPos(-25,-25);

    setAcceptTouchEvents(true);

    initialZero = QPointF(parent->scenePos()+QPointF(OFFSET,OFFSET));
    parentRect = new QRectF(parent->boundingRect());
    fixXaxis=fixX;
    fixYaxis=fixY;
}

bool StickItem::sceneEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:
    {
        //rumble.setIntensity(1);
        //rumble.setDuration(50);
        //rumble.start();
        event->accept();
        break;
    }
    case QEvent::TouchUpdate:
    {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        QTouchEvent::TouchPoint touchPoint1 = touchEvent->touchPoints().first();
        QPointF position = touchPoint1.scenePos()-initialZero+QPointF(OFFSET,OFFSET);
        qreal limit = parentRect->width() - OFFSET;
        int x = touchPoint1.scenePos().x()-initialZero.x();
        int y = touchPoint1.scenePos().y()-initialZero.y();
        int newX=x;
        int newY=y;

        if ( position.x() < 0 )
            newX = -OFFSET;

        if ( position.x() > parentRect->width() )
            newX = limit;

        if ( position.y() < 0 )
            newY = -OFFSET;

        if ( position.y() > parentRect->height() )
            newY = limit;

        setPos(newX,newY);
        emit stickUpdated(newX+OFFSET,newY+OFFSET);

        touchEvent->accept();
        break;
    }
    case QEvent::TouchEnd:
    {
        qreal limit = parentRect->width();
        int newX=this->pos().x();
        int newY=this->pos().y();

        if(fixXaxis){
            newY = limit/2-OFFSET;
        }
        if(fixYaxis){
            newX = limit/2-OFFSET;
        }

        setPos(newX,newY);
        emit stickUpdated(newX+OFFSET,newY+OFFSET);

        break;
    }
    default:
        return QGraphicsItem::sceneEvent(event);
    }

    return true;
}
