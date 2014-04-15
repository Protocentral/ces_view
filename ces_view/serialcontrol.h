#ifndef SERIALCONTROL_H
#define SERIALCONTROL_H

#include <QObject>
#include <QQueue>
#include <QThread>

typedef quint8 U8;
typedef quint16 U16;

class SerialProcessThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialProcessThread(QObject *parent = 0);
    void Init();
    void DeInit();
signals:
    void signalPacketReceived(quint8 CES_Pkt_PktType, quint16 CES_Pkt_DestAddr, QByteArray packet_data, quint16 packet_length);
public slots:
     void slotInsertRxQ(QByteArray items, int items_length);
private:
    bool ProcThreadRun;

protected:
    void run();
};

#endif // SERIALCONTROL_H
