#include <QApplication>
//#include <qapplication.h>

#include "data_plot.h"
#include "ces_view.h"

QApplication *a;
int main(int argc, char **argv)
{
    a = new QApplication(argc, argv);

    ces_view *cview = new ces_view;

    //cview->resize(800,600);

    //cview->resize(cview->maximumSize());
    cview->setWindowTitle("CES View - EEG");
    cview->show();

    a->connect(a, SIGNAL(aboutToQuit()),cview,SLOT(slotCloseApp()));

    return a->exec();
}
