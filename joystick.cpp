#include "joystick.h"
#include <stickitem.h>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QSvgRenderer>
#include <QGraphicsSvgItem>

Joystick::Joystick(int posX, int posY, int rectWidth, int rectHeight, bool fixX, bool fixY) :
    QGraphicsRectItem(0, 0, rectWidth, rectHeight)
{
    setPos(posX, posY);

    QSvgRenderer *m_renderer = new QSvgRenderer(this);
    m_renderer->load(QString(":/images/joystick.svg"));

    QGraphicsSvgItem *m_background = new QGraphicsSvgItem(this);
    m_background->setSharedRenderer(m_renderer);
    m_background->setElementId(QString("background"));

    StickItem *stick = new StickItem(fixX, fixY, this);

    connect(stick,SIGNAL(stickUpdated(int,int)),this,SLOT(updateJoystick(int,int)));
}

void Joystick::updateJoystick(int x, int y){
    emit JoystickUpdate(y,x);
}
