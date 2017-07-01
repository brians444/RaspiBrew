/***************************************************************************
**  This file is part of Serial Port Plotter                              **
**                                                                        **
**                                                                        **
**  Serial Port Plotter is a program for plotting integer data from       **
**  serial port using Qt and QCustomPlot                                  **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
****************************************************************************/

#include "mainwindow.hpp"
#include "ui_mainwindow.h"


/******************************************************************************************************************/
/* Constructor */
/******************************************************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    connected(false), plotting(false), dataPointNumber(0), numberOfAxes(1), STATE(WAIT_START), NUMBER_OF_POINTS(500)
{
    ui->setupUi(this);
    createUI();                                                                           // Create the UI
    ui->tabWidget->setCurrentIndex(0);

    crearGrafico();                                                                          // Setup plot area                                                                      // Setup plot area
    colourSetup();
                                                                                          // Slot for printing coordinates
    connect(ui->plot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(onMouseMoveInPlot(QMouseEvent*)));

    h = 0;

    serialPort = NULL;                                                                    // Set serial port pointer to NULL initially
    //connect(&updateTimer, SIGNAL(timeout()), this, SLOT(replot()));                       // Connect update timer to replot slot
    ui->saveJPGButton->setEnabled(1);
//    ui->comboAxes->setEnabled(1);

    for(int i = 0; i < CANT; i++)
    {
        habilitado[i] = true;
    }
    db = new DataBase();
    tiempo = new QTime();
    tiempo->restart();


    task = new nRFTask();
    // Conectar señales
    connect(task, SIGNAL(TempGetReady(sensores)), this, SLOT(TempReceived(sensores)));
    connect(task, SIGNAL(TargetGetReady(target)), this, SLOT(TargetReceived(target)));
    connect(task, SIGNAL(ConfigGetReady(conf)), this, SLOT(ConfigReceived(conf)));
    connect(this, SIGNAL(newData(sensores)), this, SLOT(onNewDataArrived(sensores)));
    // Conectar Slots
    // Inicio Tarea
    task->start();
    /*
    updateTimer.setInterval(5000);
    updateTimer.start();
    */

}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Destructor */
/******************************************************************************************************************/
MainWindow::~MainWindow()
{
    if(serialPort != NULL)
        delete serialPort;

    task->quit();
    delete task;
    delete db;
    delete ui;
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Replot */
/******************************************************************************************************************/
void MainWindow::replot()
{
    qDebug() <<"Replot";
    ui->plot->replot();
    // La siguiente funcion va eliminando los puntos viejos.
    // ui->plot->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
    qDebug() <<"END Replot";
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for new data from serial port . Data is comming in QStringList and needs to be parsed */
/******************************************************************************************************************/
void MainWindow::onNewDataArrived(sensores newData)
{
    if(1)
    {
        dataPointNumber++;                                                                    // Increment data number
        qDebug() <<"Adding data plot 1";
        for(int i=0; i < CANT; i++)
        {
            if(habilitado[i] == true)
	    {
		double tmp = newData.temp[i];
		if(tmp > -50.00)
		{
        	        double now = QDateTime::currentDateTime().toTime_t();
                    //ui->plot->graph(i)->setPen(colores[i]);
	                ui->plot->graph(i)->addData(now, tmp);
                    // ui->plot->rescaleAxes();
                    ui->plot->xAxis->rescale();
        	        //ui->plot->graph(i)->setValueAxis();
	                //ui->plot->graph(i)->removeDataBefore(dataPointNumber - NUMBER_OF_POINTS);
                	ui->plot->replot();
		}
            }
        }
        qDebug() <<"END Data Arrive";
    }
}
/******************************************************************************************************************/

void MainWindow::TempReceived(sensores t)
{
    this->temperaturas = t;
    if(tiempo->elapsed() >= 1000*60)
    {
        qDebug()<<"Agregando a la base de datos. msElapsed = "<<tiempo->elapsed();
        db->addTemperatures(t);
        tiempo->restart();
    }
    emit newData(t);
    UpdateTemps();

}

void MainWindow::TargetReceived(target t)
{
    this->temp_target = t;
    UpdateTargets();
}

void MainWindow::ConfigReceived(conf t)
{
    this->configuracion = t;
    UpdateConfig();
}

double MainWindow::CalcRange(int value)
{
    double resultado = (value-20)*res;
    return resultado;
}

int MainWindow::CalcRange(double value)
{
    return (int)((value/res)+20);
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    edit_target[0]->setValue(CalcRange(value));
    ui->progressBar->setValue(value);
}

void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
    edit_target[1]->setValue(CalcRange(value));
    //ui->progressBar->setValue(value);
}

void MainWindow::on_verticalSlider_3_valueChanged(int value)
{
    edit_target[2]->setValue(CalcRange(value));
    //ui->progressBar->setValue(value);
}

void MainWindow::on_verticalSlider_4_valueChanged(int value)
{
    edit_target[3]->setValue(CalcRange(value));
    //ui->progressBar->setValue(value);
}

void MainWindow::on_verticalSlider_5_valueChanged(int value)
{
    edit_target[4]->setValue(CalcRange(value));
    //ui->progressBar->setValue(value);
}

void MainWindow::on_verticalSlider_6_valueChanged(int value)
{
    edit_target[5]->setValue(CalcRange(value));
    //ui->progressBar->setValue(value);
}

void MainWindow::on_verticalSlider_7_valueChanged(int value)
{
    edit_target[6]->setValue(CalcRange(value));
    //ui->progressBar->setValue(value);
}

void MainWindow::on_verticalSlider_8_valueChanged(int value)
{
    edit_target[7]->setValue(CalcRange(value));
    //ui->progressBar->setValue(value);
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    sliders[0]->setValue(CalcRange(arg1));
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    sliders[1]->setValue(CalcRange(arg1));
}

void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    sliders[2]->setValue(CalcRange(arg1));
}

void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    sliders[3]->setValue(CalcRange(arg1));
}

void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
    sliders[4]->setValue(CalcRange(arg1));
}

void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    sliders[5]->setValue(CalcRange(arg1));
}

void MainWindow::on_doubleSpinBox_7_valueChanged(double arg1)
{
    sliders[6]->setValue(CalcRange(arg1));
}

void MainWindow::on_doubleSpinBox_8_valueChanged(double arg1)
{
    sliders[7]->setValue(CalcRange(arg1));
}

void MainWindow::on_showHistButton_clicked()
{
    // Obtengo los datos de la base de datos entre las fechas
    int fermentador = ui->numberFermHistoric->currentText().toInt();
    QDateTime f1, f2;
    f1 = ui->fecha1Historico->dateTime();
    f2 = ui->fecha2Historico->dateTime();
    qDebug() <<"Mostrando Historico del fermentador"<<fermentador<<" entre "<<f1.toString()<<" hasta "<<f2.toString();
    QList<historic_record> lista = db->getHistory(fermentador, f1, f2);
    qDebug()<< "Tamaño de lista recibida: "<<lista.size();

}
