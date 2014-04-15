#include <qapplication.h>
#include <QtGui>
#include <QtCore/QDebug>
#include <QtCore/QStringList>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QLabel>
#include <iostream>
#include <qwt_thermo.h>
#include <qwt_scale_engine.h>


#include "ces_view.h"
#include "data_plot.h"
#include "serialcontrol.h"

ces_view::ces_view(QWidget *parent):QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QPixmap pixmap(":/images/logo.png");

    QGridLayout *devControlLayout = new QGridLayout;

    QGroupBox *grpSensorControl = new QGroupBox();

    QLabel *lblTemp = new QLabel("Temperature:");
    QLabel *lblPerf = new QLabel("| Perfusion:");
    QLabel *lblHeartRate = new QLabel("| Heart Rate: ");
    QLabel *lblRespRate = new QLabel("| Respiration Rate: ");
    QFont labelFont( "Arial", 14);


    QVBoxLayout *sideLayout = new QVBoxLayout;

    QVBoxLayout *layout = new QVBoxLayout;


    QGroupBox *grpSideLayout = new QGroupBox();
    QGroupBox *grpPlots;

    grpPlots = new QGroupBox(tr("EEG Plots"));

    //Side layout components


    QGridLayout *plotsLayout = new QGridLayout;

    menuBar = new QMenuBar;
    fileMenu = new QMenu(tr("&File"), this);

    lblPorts = new QLabel("Coordinator Port:");
    lblDeviceType = new QLabel("Device Type:");

    cmbPorts = new QComboBox;
    cmbDeviceTypes = new QComboBox;

    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    cmdOpenPort = new QPushButton("Open Device");
    connect(cmdOpenPort, SIGNAL(clicked()), this, SLOT(slotOpenPort()));

    cmdClosePort = new QPushButton("Close Device");
    connect(cmdClosePort, SIGNAL(clicked()), this, SLOT(slotClosePort()));
    cmdClosePort->setEnabled(false);

    cmdStartLog = new QPushButton("Start Log");
    connect(cmdStartLog, SIGNAL(clicked()), this, SLOT(slotStartLog()));

    cmdStopLog = new QPushButton("Stop Log");
    connect(cmdStopLog, SIGNAL(clicked()), this, SLOT(slotStopLog()));
    cmdStopLog->setEnabled(false);

  //  plot-> setItemAttribute(QwtPlot::AutoScale, true);

    plot = new DataPlot(this);
    plot->setAxisTitle(QwtPlot::xBottom, "ECG");
   // plot->setAxisAutoScale(QwtPlot::xBottom,true);
    //plot->setAxisAutoScale(QwtPlot::yLeft, true);

    plot2 = new DataPlot(this);
    plot2->setAxisTitle(QwtPlot::xBottom, "Respiration");
    //plot2->setAxisAutoScale(QwtPlot::xBottom,true);
    //plot->setAxisAutoScale(QwtPlot::yLeft, true);
    plot->setAxisScale(QwtPlot::yLeft, -0.02,0.02);
    plot2->setAxisScale(QwtPlot::yLeft, -0.02,0.02);
   //plot2-> QwtScaleEngine.autoScale(50,0.0001,0.00045,50);




  /*  // Don't use auto-scaling,
    plot2->setAxisAutoScale(QwtPlot::xBottom, false);
    // Get the lower-bound, upper-bound of the x axis,
    //plot2->axisScaleDiv(QwtPlot::xBottom).lowerBound();
   //plot2->axisScaleDiv(QwtPlot::xBottom).upperBound();
    // Calculate your min/max y values between the date bounds.
    double min;
    double max;
    // Set it,
    plot2->setAxisScale(QwtPlot::xBottom, min, max);
*/
    lblLogo = new QLabel(this);
    lblLogo->setPixmap(pixmap);


    grpDeviceControl = new QGroupBox(tr("Device Control"));

    layout->addWidget(cmdStartLog);
    layout->addWidget(cmdStopLog);
    layout->addWidget(lblLogo);

    grpSensorControl->setLayout(layout);
    grpDeviceControl->setLayout(devControlLayout);

    lblTemp->setFont(labelFont);
    lblPerf->setFont(labelFont);
    lblHeartRate->setFont(labelFont);
    lblRespRate->setFont(labelFont);

    devControlLayout->addWidget(lblPorts,1,0);
    devControlLayout->addWidget(cmbPorts,1,1);

    devControlLayout->addWidget(cmdOpenPort,2,0);
    devControlLayout->addWidget(cmdClosePort,2,1);

    grpDeviceControl->setFixedWidth(250);
    grpDeviceControl->setFixedHeight(100);

    plotsLayout->addWidget(plot);
    plotsLayout->addWidget(plot2);

    grpPlots->setLayout(plotsLayout);

    sideLayout->addWidget(grpDeviceControl);
    sideLayout->addWidget(grpSensorControl);

    grpSideLayout->setLayout(sideLayout);

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(grpSideLayout);
    mainLayout->addWidget(grpPlots);

    setLayout(mainLayout);

    InDataBufferCounter=0;

    port = new QSerialPort();

    sProcThread = new SerialProcessThread;

    connect(port, SIGNAL(readyRead()), this, SLOT(slotSerialRead()));
    connect(this, SIGNAL(signalSerialRxDataReceived(QByteArray,int)), sProcThread, SLOT(slotInsertRxQ(QByteArray,int)));
    connect(sProcThread, SIGNAL(signalPacketReceived(quint8,quint16,QByteArray,quint16)), this, SLOT(slotSerialPacketReceived(quint8,quint16,QByteArray,quint16)));
    connect(this, SIGNAL(destroyed()), this, SLOT(slotClosePort()));

    connect(this, SIGNAL(signalCh1Received(double)), plot, SLOT(slotAddData(double)));
    connect(this, SIGNAL(signalCh2Received(double)), plot2, SLOT(slotAddData(double)));

    logEnabled=false;

    cmbPorts->clear();

     foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
     {
         QString s =  info.portName();
         cmbPorts->addItem(s);
     }

}

void ces_view::slotCloseApp()
{
    qDebug() << "App closing";
    if(port->isOpen())
    {
        port->close();
    }
    if(logEnabled==true)
    {
        slotStopLog();
    }
}

void ces_view::slotOpenPort()
{
    QByteArray datapkt;
    if(cmbPorts->currentText().isEmpty())
    {
        qDebug() << "Device not selected";
        return;
    }
    else
    {
        port->setPortName(cmbPorts->currentText());
    }

    if(!port->open(QSerialPort::ReadWrite))
    {
   //     qDebug() << "Port open failed" << port->deviceName();
        return;

    }

    if(!port->setBaudRate(QSerialPort::Baud57600))
    {
        qDebug() << "Set baud rate failed";
        return;
    }


    if(!port->setDataBits(QSerialPort::Data8))
    {
        qDebug() << "Set data bits failed";
        return;
    }

    if(!port->setParity(QSerialPort::NoParity))
    {
        qDebug() << "Set parity failed";
        return;
    }

    if(!port->setStopBits(QSerialPort::OneStop))
    {
        qDebug() << "Set stop bits failed";
        return;
    }

    if(!port->setFlowControl(QSerialPort::NoFlowControl))
    {
        qDebug() << "Set flowcontrol OFF failed";
        return;
    }

    port->flush();

    //Start Serial Data Processing Thread
    sProcThread->Init();

    //Set buttons status
    cmdOpenPort->setEnabled(false);
    cmdClosePort->setEnabled(true);
}

void ces_view::slotClosePort()
{
    port->close();

    sProcThread->DeInit();

    //Set buttons status
    cmdOpenPort->setEnabled(true);
    cmdClosePort->setEnabled(false);
}

void ces_view::slotStartLog()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Select log file"), ".", tr("Waves Log files (*.txt)"));

    logFile = new QFile(fileName);
    logFile->setFileName(fileName);

    if(!logFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug()<<"File open failed";
        return;
    }

    logStream.setDevice(logFile);
    logStream << "Begin Waves Log File | Started at: " << QTime::currentTime().toString(tr("hh:mm:ss")) << "\n\n";
    logEnabled=true;

    cmdStartLog->setEnabled(false);
    cmdStopLog->setEnabled(true);
}

void ces_view::slotStopLog()
{
    if(logEnabled==true)
    {
        logEnabled=false;
          logStream << "\n" << "End Log File";
        logFile->close();

        cmdStartLog->setEnabled(true);
        cmdStopLog->setEnabled(false);
    }
}

void ces_view::slotSerialRead()
{
    QByteArray ba = port->readAll();
   emit signalSerialRxDataReceived(ba, ba.size());
}

void ces_view::slotSerialPacketReceived(quint8 PktType, quint16 SrcAddr, QByteArray packet_data, quint16 packet_len)
{
    QByteArray args;
    int i=0;

    //qDebug() << "Packet Received: " << packet_len << " bytes, Type:" << PktType;

    switch(PktType)
    {
        case CES_CMDIF_TYPE_DATA:
            for(i=0;i<(packet_len);i++)
            {
                args[i]=packet_data[i];
            }
            //qDebug() << "Data Packet received:" << packet_len << " bytes";
            ces_cmdif_DataHandler(args, packet_len);
            break;
    }
}

void ces_view::ces_cmdif_DataHandler(QByteArray data, U16 data_len)
{
    double SensVal1=0;
    double SensVal2=0;

    quint16 u8data[24];

    qint32 SensVal1Int=0;
    qint32 SensVal2Int=0;


    quint32 SensVal1uint=0;
    quint32 SensVal2uint=0;


    qDebug() << "AN Data Packet Received: " << data.length();

    if(135==data_len)
    {
        for (int i = 0; i < 135; i+=9)
        {
            for(int j=0; j < 9;j++)
            {
                u8data[j] = (quint8) data[i+j] ;
            }

            SensVal1uint = (quint32)((u8data[6]<<16)|(u8data[7]<<8)|u8data[8]);
            SensVal1uint = (quint32)(SensVal1uint<<8);
            SensVal1Int  = (qint32) (SensVal1uint);

            SensVal2uint = (quint32)((u8data[3]<<16)|(u8data[4]<<8)|u8data[5]);
            SensVal2uint = (quint32)(SensVal2uint<<8);
            SensVal2Int  = (qint32) (SensVal2uint);


            SensVal1 = SensVal1Int*0.0000000004656612873077392578125;
            SensVal2 = SensVal2Int*0.0000000004656612873077392578125;


            if(logEnabled==true)
            {
                logStream << SensVal1 << "," << SensVal2 << "\n";
            }

            emit signalCh1Received(SensVal1);
            emit signalCh2Received(SensVal2);

        }
        plot->replot();
        plot2->replot();
    }
}
