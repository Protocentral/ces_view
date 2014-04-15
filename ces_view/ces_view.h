#ifndef CES_VIEW_H
#define CES_VIEW_H

#include <QWidget>
#include <QtWidgets/QToolButton>
#include <QtGui>

#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QGroupBox>
#include <QMenuBar>
#include <QtSerialPort/QSerialPort>

#include "serialcontrol.h"
#include "ces_cmdif.h"


class DataPlot;
class DataPlotFFT;

class ces_view : public QWidget
{
    Q_OBJECT
public:
    explicit ces_view(QWidget *parent = 0);

signals:
    void signalSerialRxDataReceived(QByteArray items, int items_length);
    void signalDataPacketReceived(double data_x, double data_y, double data_z);

    void signalCh1Received(double data_x);
    void signalCh2Received(double data_x);

public slots:
    void slotOpenPort();
    void slotClosePort();

    void slotStartLog();
    void slotStopLog();

    void slotSerialRead();
    void slotSerialPacketReceived(quint8 PktType, quint16 SrcAddr, QByteArray packet_data, quint16 packet_len);

    void slotCloseApp();

private:
    DataPlot *plot;
    DataPlot *plot2;

    QSerialPort *port;
    SerialProcessThread *sProcThread;

    U16 SetNet;

    QMenuBar *menuBar;

    QGroupBox *grpDeviceControl;

    QLabel *lblPorts;
    QComboBox *cmbPorts;
    QLabel *lblDeviceType;
    QComboBox *cmbDeviceTypes;

    QPushButton *cmdOpenPort;
    QPushButton *cmdClosePort;

    QPushButton *cmdStartLog;
    QPushButton *cmdStopLog;

    QWidget *hBox;
    QLabel *label;

    QMenu *fileMenu;
    QAction *exitAction;

    QLabel *lblLogo;
    QLabel *lblMessages;

    QStringList messageListData;
    QStringListModel *messageListModel;

    QFile *logFile;
    QTextStream logStream;
    bool logEnabled;

    double InDataBuffer[250];
    int     InDataBufferCounter;

    void ces_cmdif_EventHandler(U16 SrcAddr, U8 evt_cat, U8 evt_code, QByteArray args, U8 arg_len);
    void ces_cmdif_ResponseHandler(U16 SrcAddr, U8 cmd_cat, U8 cmd_code, QByteArray args, U8 arg_len);
    void ces_cmdif_DataHandler(QByteArray data, U16 data_len);

    QString logContent;

    // array to hold input samples
    double insamp[ BUFFER_LEN ];
    double coeffs[ FILTER_LEN ];
    double floatOutput[SAMPLES];
    double eeg_ch1[250];
};

#endif // CES_VIEW_H
