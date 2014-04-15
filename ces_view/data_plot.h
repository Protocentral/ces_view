#ifndef _DATA_PLOT_H
#define _DATA_PLOT_H 1

#include <qwt_plot.h>

const int PLOT_SIZE = 1250;      // 0 to 200

class DataPlot : public QwtPlot
{
    Q_OBJECT

public:
    DataPlot(QWidget* = NULL);
    void setYTitle(const char* titleText);
    void setYExtents(double yLow, double yHigh);

public slots:
    void setTimerInterval(double interval);
    void slotAddData(double data_x);
    void slotAddDataRange(double data_x[],int data_len);
protected:

private:
    void alignScales();

    double d_x[PLOT_SIZE]; 
    double d_y[PLOT_SIZE]; 
    double d_z[PLOT_SIZE];
    double d_3[PLOT_SIZE];

    int d_interval; // timer in ms
    int d_timerId;
};

#endif
