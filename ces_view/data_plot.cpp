#include <stdlib.h>
#include <qwt_painter.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_scale_widget.h>
#include <qwt_legend.h>
#include <qwt_scale_draw.h>
#include <qwt_math.h>

#include <QDebug>

#include "data_plot.h"

//
//  Initialize main window
//
DataPlot::DataPlot(QWidget *parent):
    QwtPlot(parent),
    d_interval(0),
    d_timerId(-1)
{
    // Disable polygon clipping
    //QwtPainter::setDeviceClipping(false);

    // We don't need the cache here
    //canvas()->setPaintAttribute(QwtPlotCanvas::PaintCached, false);
    //canvas()->setPaintAttribute(QwtPlotCanvas::PaintPacked, false);

#ifdef Q_WS_X11
    /*
       Qt::WA_PaintOnScreen is only supported for X11, but leads
       to substantial bugs with Qt 4.2.x/Windows
     */
    canvas()->setAttribute(Qt::WA_PaintOnScreen, true);
#endif

    alignScales();
    
    //  Initialize data
    for (int i = 0; i< PLOT_SIZE; i++)
    {
        d_x[i] = 1 * i;     // time axis
        d_y[i] = 0;
        d_z[i] = 0;
        d_3[i] = 0;
    }

    // Insert new curves
    QwtPlotCurve *cRight = new QwtPlotCurve("Channel 1");
    cRight->attach(this);

    // Set curve styles
    cRight->setPen(QPen(Qt::blue));

    // Attach (don't copy) data. Both curves use the same x array.
    cRight->setRawSamples(d_x, d_y, PLOT_SIZE);
    //cRight->setRawData(d_x, d_y, PLOT_SIZE);

#if 0
    //  Insert zero line at y = 0
    QwtPlotMarker *mY = new QwtPlotMarker();
    mY->setLabelAlignment(Qt::AlignRight|Qt::AlignTop);
    mY->setLineStyle(QwtPlotMarker::HLine);
    mY->setYValue(0.0);
    mY->attach(this);
#endif

    // Axis 
    //setAxisTitle(QwtPlot::xBottom, "Time/seconds");
     setAxisScale(QwtPlot::xBottom, 0, 1400);
     setAxisScale(QwtPlot::yLeft, 0, 1400);

    //setAxisTitle(QwtPlot::yLeft, "Acceleration (G)");
     setAxisAutoScale(QwtPlot::yLeft,true);
     setAxisAutoScale(QwtPlot::xBottom,true);

     setAxisScale(xBottom, 0, 750);
     setAxisScale(yLeft, -0.2,0.2);
   //  setAxisScale(yLeft, -1, 1);
     setAxisAutoScale(yLeft);
    // setAxisAutoScale(xBottom);

   // setTimerInterval(0.0);
}

void DataPlot::setYTitle(const char* titleText)
{
    setAxisTitle(QwtPlot::yLeft, titleText);
}

void DataPlot::setYExtents(double yLow, double yHigh)
{
    setAxisScale(QwtPlot::yLeft, yLow, yHigh);
}

//
//  Set a plain canvas frame and align the scales to it
//
void DataPlot::alignScales()
{
    // The code below shows how to align the scales to
    // the canvas frame, but is also a good example demonstrating
    // why the spreaded API needs polishing.

    //canvas()->setFrameStyle(QFrame::Box | QFrame::Plain );
    //canvas()->setLineWidth(1);

    for ( int i = 0; i < QwtPlot::axisCnt; i++ )
    {
        QwtScaleWidget *scaleWidget = (QwtScaleWidget *)axisWidget(i);
        if ( scaleWidget )
            scaleWidget->setMargin(0);

        QwtScaleDraw *scaleDraw = (QwtScaleDraw *)axisScaleDraw(i);
        if ( scaleDraw )
            scaleDraw->enableComponent(QwtAbstractScaleDraw::Backbone, false);
    }
}

void DataPlot::setTimerInterval(double ms)
{
    d_interval = qRound(ms);

    if ( d_timerId >= 0 )
    {
        killTimer(d_timerId);
        d_timerId = -1;
    }
    if (d_interval >= 0 )
        d_timerId = startTimer(d_interval);
}

void DataPlot::slotAddData(double data_x)
{
    //qDebug() << "Plotting: " << data_x;
    // Shift y array right and assign new value to y[0].

    for ( int i = PLOT_SIZE - 1; i > 0; i-- )
        d_y[i] = d_y[i-1];
    d_y[0] = data_x;


/*
    for ( int i = 0; i > (PLOT_SIZE - 1); i++ )
        d_y[i-1] = d_y[i];
    d_y[i] = data_x;
*/

    //replot();
}

void DataPlot::slotAddDataRange(double data_x[], int data_len)
{
    for( int j=0; j<data_len;j++)
    {
        for ( int i = PLOT_SIZE - 1; i > 0; i-- )
            d_y[i] = d_y[i-1];


        d_y[0] = data_x[j];
    }
}

