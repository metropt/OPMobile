#include <QApplication>
#include <QGraphicsView>
#include <joystick.h>
#include <stickitem.h>
#include <cccom.h>
#include <QSvgRenderer>
#include <QGraphicsSvgItem>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0,0,854,480);

    QGraphicsView view(&scene);
    view.viewport()->setAttribute(Qt::WA_AcceptTouchEvents);

    view.setFixedSize(854,480);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setStyleSheet( "QGraphicsView { border-style: none; }" );
    scene.setBackgroundBrush(QBrush(QColor(100,100,100), Qt::SolidPattern));

    QSvgRenderer *m_renderer = new QSvgRenderer();
    m_renderer->load(QString(":/images/joystick.svg"));

    QGraphicsSvgItem *m_logo = new QGraphicsSvgItem();
    m_logo->setSharedRenderer(m_renderer);
    m_logo->setElementId(QString("opheader"));
    m_logo->setPos(283,415);
    scene.addItem(m_logo);

    //inverted left and right
    Joystick *left = new Joystick(464,65,350,350,false,true);
    scene.addItem(left);

    Joystick *right = new Joystick(38,65,350,350,true,true);
    scene.addItem(right);

    cccom teste;
    QObject::connect(left,SIGNAL(JoystickUpdate(int,int)),&teste,SLOT(updateSticksTY(int,int)));
    QObject::connect(right,SIGNAL(JoystickUpdate(int,int)),&teste,SLOT(updateSticksPR(int,int)));

    view.showFullScreen();
    return app.exec();
}

