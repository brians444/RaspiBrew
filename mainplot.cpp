#include "mainwindow.hpp"
#include "ui_mainwindow.h"


/******************************************************************************************************************/
/* Crear Grafico 1 */
/******************************************************************************************************************/
void MainWindow::crearGrafico()
{
    colores[0] = QPen(Qt::red);
    colores[1] = QPen(Qt::blue);
    colores[2] = QPen(Qt::green);
    colores[3] = QPen(Qt::cyan);
    colores[4] = QPen(Qt::magenta);
    colores[5] = QPen(Qt::yellow);
    colores[6] = QPen(Qt::gray);
    colores[7] = QPen(Qt::black);

    ui->plot->setNotAntialiasedElements(QCP::aeAll);                                      // used for higher performance (see QCustomPlot real time example)
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    ui->plot->xAxis->setTickLabelFont(font);
    ui->plot->yAxis->setTickLabelFont(font);
    ui->plot->legend->setFont(font);
    ui->plot->yAxis->setAutoTickStep(false);                                              // User can change tick step with a spin box
    ui->plot->yAxis->setTickStep(500);                                                    // Set initial tick step
    ui->plot->xAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->setInteraction(QCP::iRangeDrag, true);
    ui->plot->setInteraction(QCP::iRangeZoom, true);

    ui->plot->clearItems();                                                              // Remove everything from the plot

    ui->plot->yAxis->setTickStep(ui->spinYStep->value());                                // Set tick step according to user spin box
    ui->plot->yAxis->setRange(ui->spinAxesMin->value(), ui->spinAxesMax->value());       // Set lower and upper plot range
    ui->plot->xAxis->setRange(0, NUMBER_OF_POINTS);                                      // Set x axis range for specified number of points
    ui->plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // Labl coordinates along the X axis as the Date and Time
    ui->plot->xAxis->setDateTimeFormat("hh:mm:ss");  // Set the date and time format

    qDebug()<<"Numero de ejes: "<<numberOfAxes;

    for(int i = 0; i < CANT; i++)
    {
        ui->plot->addGraph();
        ui->plot->graph(i)->setPen(colores[i]);
    }

}
/******************************************************************************************************************/


void MainWindow::colourSetup()
{

    /***********   Seteo de colores GRAFICO 1******/
/*
    ui->plot->setBackground(QBrush(QColor(48,47,47)));                                    // Background for the plot area
    ui->plot->xAxis->setTickLabelColor(QColor(170,170,170));                              // Tick labels color
    ui->plot->yAxis->setTickLabelColor(QColor(170,170,170));                              // See QCustomPlot examples / styled demo
    ui->plot->xAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::DotLine));
    ui->plot->xAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::DotLine));
    ui->plot->xAxis->setBasePen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setBasePen(QPen(QColor(170,170,170)));
    ui->plot->xAxis->setTickPen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setTickPen(QPen(QColor(170,170,170)));
    ui->plot->xAxis->setSubTickPen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setSubTickPen(QPen(QColor(170,170,170)));
*/
}



/******************************************************************************************************************/
/* Reiniciar el zoom del grafico a los valores iniciales */
/******************************************************************************************************************/
void MainWindow::on_resetPlotButton_clicked()
{
    /********* GRAFICO 1 ********/
    ui->plot->yAxis->setRange(0, 4095);
    //ui->plot->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
    ui->plot->xAxis->setRange(0, NUMBER_OF_POINTS);
    ui->plot->yAxis->setTickStep(500);
    ui->plot->replot();


}
/******************************************************************************************************************/
