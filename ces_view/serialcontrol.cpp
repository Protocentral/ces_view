#include "serialcontrol.h"
#include <QSemaphore>
#include <QByteArray>
#include <QtCore/QDebug>

#include "ces_cmdif.h"
#include "mtqueue.h"

QSemaphore freeBytes[1024];
QSemaphore usedBytes;
MTQueue<U8> serialRxQ;

SerialProcessThread::SerialProcessThread(QObject *parent)
{

}

void SerialProcessThread::slotInsertRxQ(QByteArray items, int items_length)
{
    for(int i=0;i<items_length;i++)
    {
        //TODO: Add Semaphores
        //freeBytes->acquire();
        serialRxQ.enqueue(items[i]);
        //usedBytes.release();
    }
    //qDebug() << "Inserted Q: " << items_length;
    //qDebug() << "Q Length: " << serialRxQ.count();
}

void SerialProcessThread::Init()
{
    ProcThreadRun=true;
    this->start();
}

void SerialProcessThread::DeInit()
{
    ProcThreadRun=false;
}

void SerialProcessThread::run()
{
    U8 rxch=0;

    int          CurrentState=CESState_Init;
    QByteArray    DataPacket;

    U16  CES_Pkt_Len=0;		//Data Payload length
    //U16 CES_Pkt_EndSeq;
    U8  CES_Pkt_PktType=0;
    U16 CES_Pkt_DestAddr=0;
    //U8  CES_Pkt_LQI;
//    U8  CES_Pkt_FCS;
//    U8  CES_FCS_Calc=0;

    U16 CES_Pkt_Pos_Counter=0;
    U16 CES_Pkt_Data_Counter=0;

    QByteArray DataRcvPacket;
    //DataPacket->resize(255);

    qDebug() << "ProcessThread: Thread Started";

    while(ProcThreadRun==true)
    {
        if(serialRxQ.count()>0)
        {
            //qDebug() << "ProcessThread: Q Length " << serialRxQ.count();
            rxch = serialRxQ.dequeue();
            switch(CurrentState)
            {
                case CESState_Init:
                        if(rxch==CES_CMDIF_PKT_START_1)
                        {
                                CurrentState=CESState_SOF1_Found;
                        }
                        break;
                case CESState_SOF1_Found:
                        if(rxch==CES_CMDIF_PKT_START_2)
                        {
                                CurrentState=CESState_SOF2_Found;
                        }
                        else
                        {
                                //Invalid Packet, reset state to init
                                CurrentState=CESState_Init;
                        }
                        break;
                case CESState_SOF2_Found:
                        CurrentState = CESState_PktLen_Found;
                        CES_Pkt_Len = (U8) rxch;
                        CES_Pkt_Pos_Counter = CES_CMDIF_IND_LEN;
                        CES_Pkt_Data_Counter = 0;
                        break;
                case CESState_PktLen_Found:
                        CES_Pkt_Pos_Counter++;
                        if(CES_Pkt_Pos_Counter<(CES_CMDIF_PKT_OVERHEAD))  //Read Header
                        {
                                if(CES_Pkt_Pos_Counter==CES_CMDIF_IND_LEN_MSB)
                                {
                                        CES_Pkt_Len = (U16) ((rxch<<8)|CES_Pkt_Len);
                                }                                
                                else if(CES_Pkt_Pos_Counter==CES_CMDIF_IND_PKTTYPE)
                                {
                                        CES_Pkt_PktType = (U8) rxch;
                                }
                        }
                        else if((CES_Pkt_Pos_Counter>=(CES_CMDIF_PKT_OVERHEAD))
                                        &&(CES_Pkt_Pos_Counter<(CES_CMDIF_PKT_OVERHEAD+CES_Pkt_Len+1)))  //Read Data
                        {
                                DataRcvPacket[CES_Pkt_Data_Counter]= (U8) rxch;
                                CES_Pkt_Data_Counter++;
                        }
                        else	//All header and data received
                        {
                                //Check for EOF Byte
                                if(rxch==CES_CMDIF_PKT_STOP)
                                {
                                        //Complete valid packet received
                                        qDebug() << "PKT Recieved:";

                                        emit signalPacketReceived(CES_Pkt_PktType, CES_Pkt_DestAddr, DataRcvPacket, CES_Pkt_Len);
                                        CurrentState=CESState_Init;
                                }
                                else
                                {
                                        //Packet end not found, drop packet
                                        CurrentState=CESState_Init;
                                }
                        }
                        break;
                default:
                        //Invalid state
                        //TODO: Error handling for undefined state in packet parser
                        break;
            }
            //this->sleep(1);
        }
    }
}
