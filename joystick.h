#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>
#include <QGraphicsRectItem>

class Joystick : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Joystick(int posX, int posY, int rectWidth, int rectHeight, bool fixX, bool fixY);
    
signals:
    void JoystickUpdate(int y, int x);

public slots:
    void updateJoystick(int x, int y);

};

#endif // JOYSTICK_H
