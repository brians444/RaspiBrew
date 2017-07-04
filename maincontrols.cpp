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




    ui->fecha1Historico->setDate(QDate::currentDate().addMonths(-1));
    ui->fecha2Historico->setDateTime(QDateTime::currentDateTime());

    salidaAct[0] = ui->habilitadoCheckBox1;
    salidaAct[1] = ui->habilitadoCheckBox2;
    salidaAct[2] = ui->habilitadoCheckBox3;
    salidaAct[3] = ui->habilitadoCheckBox4;
    salidaAct[4] = ui->habilitadoCheckBox5;
    salidaAct[5] = ui->habilitadoCheckBox6;
    salidaAct[6] = ui->habilitadoCheckBox7;
    salidaAct[7] = ui->habilitadoCheckBox8;

    frioHab[0] = ui->frioCheckBox;
    frioHab[1] = ui->frioCheckBox_2;
    frioHab[2] = ui->frioCheckBox_3;
    frioHab[3] = ui->frioCheckBox_4;
    frioHab[4] = ui->frioCheckBox_5;
    frioHab[5] = ui->frioCheckBox_6;
    frioHab[6] = ui->frioCheckBox_7;
    frioHab[7] = ui->frioCheckBox_8;

    calorHab[0] = ui->calorCheckBox;
    calorHab[1] = ui->calorCheckBox_2;
    calorHab[2] = ui->calorCheckBox_3;
    calorHab[3] = ui->calorCheckBox_4;
    calorHab[4] = ui->calorCheckBox_5;
    calorHab[5] = ui->calorCheckBox_6;
    calorHab[6] = ui->calorCheckBox_7;
    calorHab[7] = ui->calorCheckBox_8;

    frioSal[0] = ui->salidaFrioLineEdit;
    frioSal[1] = ui->salidaFrioLineEdit_2;
    frioSal[2] = ui->salidaFrioLineEdit_3;
    frioSal[3] = ui->salidaFrioLineEdit_4;
    frioSal[4] = ui->salidaFrioLineEdit_5;
    frioSal[5] = ui->salidaFrioLineEdit_6;
    frioSal[6] = ui->salidaFrioLineEdit_7;
    frioSal[7] = ui->salidaFrioLineEdit_8;

    calorSal[0] = ui->salidaCalorLineEdit;
    calorSal[1] = ui->salidaCalorLineEdit_2;
    calorSal[2] = ui->salidaCalorLineEdit_3;
    calorSal[3] = ui->salidaCalorLineEdit_4;
    calorSal[4] = ui->salidaCalorLineEdit_5;
    calorSal[5] = ui->salidaCalorLineEdit_6;
    calorSal[6] = ui->salidaCalorLineEdit_7;
    calorSal[7] = ui->salidaCalorLineEdit_8;


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
/*  uint8_t frio;       // Utilizo los bits como booleanos
    uint8_t calor;      // Utilizo los bits como booleanos
    uint8_t salida_frio[8];
    uint8_t salida_calor[8];
    uint8_t habilitado; // Utilizo los bits como booleanos
    uint8_t fulltime;
    float temp[2];
    QCheckBox *salidaAct[CANT];
    QCheckBox *frioHab[CANT];
    QCheckBox *calorHab[CANT];
    QLineEdit *frioSal[CANT];
    QLineEdit *calorSal[CANT];
*/
    uint8_t tmp;
    uint8_t mask = 0x01;
    for(int i = 0; i < CANT; i++)
    {
        qDebug() << "Mascara = "<< (int)mask;
        tmp = configuracion.frio&mask;
        qDebug() << "FRIO Luego de mascara = "<< tmp;
        if(tmp>0)
        {
            frioHab[i]->setChecked(1);
        }
        else
        {
            frioHab[i]->setChecked(0);
        }
        tmp = configuracion.calor&mask;
        qDebug() << "CALOR Luego de mascara = "<< tmp;
        if(tmp>0)
        {
            calorHab[i]->setChecked(1);
        }
        else
        {
            calorHab[i]->setChecked(0);
        }

        tmp = configuracion.habilitado&mask;
        qDebug() << "HABILITADO Luego de mascara = "<< tmp;
        if(tmp>0)
        {
            salidaAct[i]->setChecked(1);
        }
        else
        {
            salidaAct[i]->setChecked(0);
        }
        frioSal[i]->setText(QString::number(configuracion.salida_frio[i]));
        calorSal[i]->setText(QString::number(configuracion.salida_calor[i]));
        mask = mask*2;
    }

    ui->temp9Label->setText(QString::number(configuracion.temp[0]));
    ui->temp10Label->setText(QString::number(configuracion.temp[1]));
    ui->fullTimeCheckBox->setChecked((bool)configuracion.fulltime);

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

