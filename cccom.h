#ifndef CCCOM_H
#define CCCOM_H

#include <QObject>

#include <QtEndian>
#include <QByteArray>
#include <QDataStream>
#include <QPushButton>
#include <QTimer>
#include <QtNetwork>
#include <QString>

class cccom : public QObject
{
    Q_OBJECT
public:
    explicit cccom(QObject *parent = 0);
    quint8 updateCRC(quint8 crc, const quint8 data);
    quint8 updateCRC(quint8 crc, const quint8* data, qint32 length);
    float mapValues(float x, float in_min, float in_max, float out_min, float out_max);

private:
    QUdpSocket *socketCCOut;
    QTimer *timer;
    quint16 throttleStick;
    quint16 rollStick;
    quint16 pitchStick;
    quint16 yawStick;

signals:
    
public slots:
     void timerUpdate();
     void updateSticksTY(int t, int y);
     void updateSticksPR(int p, int r);
    
};

#endif // CCCOM_H
