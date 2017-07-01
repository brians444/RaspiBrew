#include "mainwindow.hpp"
#include "ui_mainwindow.h"

/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for port opened successfully */
/******************************************************************************************************************/
/*void MainWindow::portOpenedSuccess()
{
    //qDebug() << "Port opened signal received!";
    ui->statusBar->showMessage("Conectado!");                                                               // Disable controls if port is open

    ui->saveJPGButton->setEnabled(true);                                                  // Enable button for saving plot
    crearGrafico1();                                                                          // Create the QCustomPlot area                                                                        // Create the QCustomPlot area
    updateTimer.setInterval(500);                                                                // Slot is refreshed 20 times per second
    /********* Modificacion
     * ui->stopPlotButton->setText("Stop Plot");                                             // Enable button for stopping plot
     * ui->stopPlotButton->setEnabled(true);
     *  updateTimer.stop();             // Stop updating plot timer
     *
     * Con la modificacion no inicia solo el grafico
     *

    plotting = false;
    ui->stopPlotButton->setEnabled(true);
    ui->stopPlotButton->setText("Iniciar! ");

    connected = true;                                                                     // Set flags
    //plotting = true;
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for fail to open the port */
/******************************************************************************************************************/
/*void MainWindow::portOpenedFail()
{
    //qDebug() << "Port cannot be open signal received!";
    ui->statusBar->showMessage("No se puede abrir el puerto!");
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for closing the port */
/******************************************************************************************************************/
/*void MainWindow::onPortClosed()
{
    //qDebug() << "Port closed signal received!";
    updateTimer.stop();
    connected = false;
    disconnect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
    disconnect(this, SIGNAL(portOpenOK()), this, SLOT(portOpenedSuccess()));             // Disconnect port signals to GUI slots
    disconnect(this, SIGNAL(portOpenFail()), this, SLOT(portOpenedFail()));
    disconnect(this, SIGNAL(portClosed()), this, SLOT(onPortClosed()));
    disconnect(this, SIGNAL(newData(QStringList)), this, SLOT(onNewDataArrived(QStringList)));
}


/******************************************************************************************************************/
/* Number of axes combo; when changed, display axes colors in status bar */
/******************************************************************************************************************/
void MainWindow::on_comboAxes_currentIndexChanged(int index)
{
    if(index == 0) {
      ui->statusBar->showMessage("Axis 1: Red");
    } else if(index == 1) {
        ui->statusBar->showMessage("Axis 1: Red; Axis 2: Yellow");
    } else {
        ui->statusBar->showMessage("Axis 1: Red; Axis 2: Yellow; Axis 3: Green");
    }
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Imprime las coordenadas del puntero del mouse en el barra de estado */
/******************************************************************************************************************/
void MainWindow::onMouseMoveInPlot(QMouseEvent *event)
{
    int xx = ui->plot->xAxis->pixelToCoord(event->x());
    double yy = ui->plot->yAxis->pixelToCoord(event->y());
    QDateTime tt;
    tt.fromTime_t(xx);
    QString coordinates("X: %1 Y: %2");
    coordinates = coordinates.arg(tt.fromTime_t(xx).toString()).arg(yy);
    ui->statusBar->showMessage(coordinates);
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Shows a window with instructions */
/******************************************************************************************************************/
void MainWindow::on_actionHow_to_use_triggered()
{
    helpWindow = new HelpWindow(this);
    helpWindow->setWindowTitle("Como usar esta aplicacion!");
    helpWindow->show();
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/**Create the GUI */
/******************************************************************************************************************/
void MainWindow::createUI()
{

    max_slider = 100;
    min_slider = 0;

    high = 40.00;
    lower = -10.00;
    res = (high-lower)/max_slider; // Que me permita variar de 40ºC hasta -10ºC

    termometros[0] = ui->Thermo;
    termometros[1] = ui->Thermo_2;
    termometros[2] = ui->Thermo_3;
    termometros[3] = ui->Thermo_4;
    termometros[4] = ui->Thermo_5;
    termometros[5] = ui->Thermo_6;
    termometros[6] = ui->Thermo_7;
    termometros[7] = ui->Thermo_8;
    temps_actuales[0] = ui->label_t1;
    temps_actuales[1] = ui->label_t2;
    temps_actuales[2] = ui->label_t3;
    temps_actuales[3] = ui->label_t4;
    temps_actuales[4] = ui->label_t5;
    temps_actuales[5] = ui->label_t6;
    temps_actuales[6] = ui->label_t7;
    temps_actuales[7] = ui->label_t8;

    for(int i = 0; i<8; i++)
    {
        temperaturas.temp[i] = 18.00;
        termometros[i]->setMaximum(35.00);
        termometros[i]->setMinimum(-5.00);

    }

    UpdateTemps();

    sliders[0] = ui->verticalSlider;
    sliders[1] = ui->verticalSlider_2;
    sliders[2] = ui->verticalSlider_3;
    sliders[3] = ui->verticalSlider_4;
    sliders[4] = ui->verticalSlider_5;
    sliders[5] = ui->verticalSlider_6;
    sliders[6] = ui->verticalSlider_7;
    sliders[7] = ui->verticalSlider_8;


    edit_target[0] = ui->doubleSpinBox;
    edit_target[1] = ui->doubleSpinBox_2;
    edit_target[2] = ui->doubleSpinBox_3;
    edit_target[3] = ui->doubleSpinBox_4;
    edit_target[4] = ui->doubleSpinBox_5;
    edit_target[5] = ui->doubleSpinBox_6;
    edit_target[6] = ui->doubleSpinBox_7;
    edit_target[7] = ui->doubleSpinBox_8;

    for(int i = 0; i<8; i++)
    {
        edit_target[i]->setMaximum(40.00);
        edit_target[i]->setMinimum(-10.00);

    }
}
/******************************************************************************************************************/




/******************************************************************************************************************/
/* Slot for spin box for plot maximum value on y axis */
/******************************************************************************************************************/
void MainWindow::on_spinAxesMax_valueChanged(int arg1)
{
    ui->plot->yAxis->setRangeUpper(arg1);
    ui->plot->replot();
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Slot for spin box for plot minimum value on y axis */
/******************************************************************************************************************/
void MainWindow::on_spinAxesMin_valueChanged(int arg1)
{
    ui->plot->yAxis->setRangeLower(arg1);
    ui->plot->replot();
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Spin box controls how many data points are collected and displayed */
/******************************************************************************************************************/
void MainWindow::on_spinPoints_valueChanged(int arg1)
{
    NUMBER_OF_POINTS = arg1;
    ui->plot->replot();
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Spin box for changing the Y Tick step */
/******************************************************************************************************************/
void MainWindow::on_spinYStep_valueChanged(int arg1)
{
    ui->plot->yAxis->setTickStep(arg1);
    ui->plot->replot();
}
/******************************************************************************************************************/

void MainWindow::SetActualTemp(int fermentador, double temp)
{
    if( fermentador >=0 && fermentador<8)
    {
        termometros[fermentador]->setValue(temp);
        temps_actuales[fermentador]->setText(QString::number(temp)+" ºC");
    }

}

void MainWindow::UpdateTemps()
{

    for(int i = 0; i < CANT; i++)
    {
        SetActualTemp(i, temperaturas.temp[i]);
    }
    emit newData(temperaturas);
}

void MainWindow::UpdateTargets()
{
    for(int i = 0; i < CANT; i++)
    {
        edit_target[i]->setValue(temp_target.set_temp[i]);
    }

}

void MainWindow::UpdateConfig()
{

}
