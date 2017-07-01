#include "mainwindow.hpp"
#include "ui_mainwindow.h"

void MainWindow::on_showHistButton_clicked()
{
    // Obtengo los datos de la base de datos entre las fechas
    int fermentador = ui->numberFermHistoric->currentText().toInt();
    QDateTime f1, f2;
    f1 = ui->fecha1Historico->dateTime();
    f2 = ui->fecha2Historico->dateTime();
    QList<historic_record> lista = db->getHistory(fermentador, f1, f2);

    crearGraficoHistorico();


    int tam = lista.size();

    double inf, max;
    inf = lista[0].ti;
    max = lista[tam-1].ti;

    #ifdef DEBUG
    qDebug()<< "Tamaño de lista recibida: "<<tam;
    qDebug()<< "Current TIMESTAMP ="<<QDateTime::currentDateTime().toTime_t();
    qDebug()<< "Limite Inferior ="<<f1.toTime_t()<<" Fecha = "<<f1.toString();
    qDebug()<< "Limite Superior ="<<f2.toTime_t()<<" Fecha = "<<f2.toString();
    #endif

    ui->plot_historico->xAxis->setRangeLower(inf);
    ui->plot_historico->xAxis->setRangeUpper(max);
    for(int i = 0; i<tam; i++)
    {
        ui->plot_historico->graph(0)->addData(lista[i].ti, lista[i].value);
        #ifdef DEBUG
        qDebug() << "Graficando Historico X="<<lista[i].ti<<" Y="<<lista[i].value;
        #endif
    }


    ui->plot_historico->xAxis->rescale();
    ui->plot_historico->rescaleAxes();
    ui->plot_historico->replot();


}


void MainWindow::crearGraficoHistorico()
{

    ui->plot_historico->setNotAntialiasedElements(QCP::aeAll);                                      // used for higher performance (see QCustomPlot real time example)
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    ui->plot_historico->xAxis->setTickLabelFont(font);
    ui->plot_historico->yAxis->setTickLabelFont(font);
    ui->plot_historico->legend->setFont(font);
    ui->plot_historico->yAxis->setAutoTickStep(false);                                              // User can change tick step with a spin box
    ui->plot_historico->xAxis->grid()->setSubGridVisible(true);
    ui->plot_historico->yAxis->grid()->setSubGridVisible(true);
    ui->plot_historico->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot_historico->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot_historico->setInteraction(QCP::iRangeDrag, true);
    ui->plot_historico->setInteraction(QCP::iRangeZoom, true);

    ui->plot_historico->clearGraphs();
    ui->plot_historico->clearItems();
                                                                 // Remove everything from the plot

    ui->plot_historico->yAxis->setTickStep(10);                                // Set tick step according to user spin box
    ui->plot_historico->yAxis->setRange(-10.00, 40.00);       // Set lower and upper plot range
    //ui->plot_historico->xAxis->setRange(0, NUMBER_OF_POINTS);                                      // Set x axis range for specified number of points
    ui->plot_historico->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // Labl coordinates along the X axis as the Date and Time
    ui->plot_historico->xAxis->setDateTimeFormat("dd-MM-yy hh:mm:ss");  // Set the date and time format


    ui->plot_historico->xAxis->setLabel("Tiempo");
    ui->plot_historico->yAxis->setLabel("Temperatura ( ºC )");

    ui->plot_historico->addGraph();

}



/******************************************************************************************************************/
/* Save a JPG image of the plot to current EXE directory */
/******************************************************************************************************************/
void MainWindow::on_saveJPGButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Exportar Grafico", QString(), "*.jpg");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".jpg");
    }
    fileName = QFileInfo(fileName).baseName();


    // ui->plot->saveBmp();
    // ui->plot->savePdf();
    ui->plot->saveJpg(fileName);

}
/******************************************************************************************************************/


/************************ PAGINA DE CALIBRACION *****************/


void MainWindow::on_signal1Check_clicked(bool checked)
{
    habilitado[0] = checked;
}

void MainWindow::on_signal2Check_clicked(bool checked)
{
    habilitado[1] = checked;
}

void MainWindow::on_signal3Check_clicked(bool checked)
{
    habilitado[2] = checked;
}

void MainWindow::on_signal4Check_clicked(bool checked)
{
    habilitado[3] = checked;
}

void MainWindow::on_signal5Check_clicked(bool checked)
{
    habilitado[4] = checked;
}

void MainWindow::on_signal6Check_clicked(bool checked)
{
    habilitado[5] = checked;
}
