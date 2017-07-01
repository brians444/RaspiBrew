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
**           Author: Borislav                                             **
**           Contact: b.kereziev@gmail.com                                **
**           Date: 29.12.14                                               **
****************************************************************************/

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QSlider>
#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include "helpwindow.hpp"

#include "qcustomplot.h"
#include <QFileDialog>

#include "nrftask.h"
// Analog Widgets
#include "thermometer.h"
// Base de datos
#include "database.h"
#include <QTime>

#define CANALES 10


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CrearGrafico();

private slots:
    void replot();                                                                        // Slot for repainting the plot
    void onNewDataArrived(sensores newData);                                           // Slot for new data from serial port
    void on_spinAxesMin_valueChanged(int arg1);                                           // Changing lower limit for the plot
    void on_spinAxesMax_valueChanged(int arg1);                                           // Changing upper limit for the plot
    void on_comboAxes_currentIndexChanged(int index);                                     // Display number of axes and colors in status bar
    void on_spinYStep_valueChanged(int arg1);                                             // Spin box for changing Y axis tick step
    void on_saveJPGButton_clicked();                                                      // Button for saving JPG
    void on_resetPlotButton_clicked();                                                    // Resets plot to initial zoom and coordinates
    void onMouseMoveInPlot(QMouseEvent *event);                                           // Displays coordinates of mouse pointer when clicked in plot in status bar
    void on_spinPoints_valueChanged(int arg1);                                            // Spin box controls how many data points are collected and displayed
    void on_actionHow_to_use_triggered();

    /***********************************************************/

    void on_signal1Check_clicked(bool checked);
    void on_signal2Check_clicked(bool checked);
    void on_signal3Check_clicked(bool checked);
    void on_signal4Check_clicked(bool checked);
    void on_signal5Check_clicked(bool checked);
    void on_signal6Check_clicked(bool checked);

    void TempReceived(sensores );
    void TargetReceived(target t);
    void ConfigReceived(conf t);



    void on_verticalSlider_valueChanged(int value);

    void on_verticalSlider_2_valueChanged(int value);

    void on_verticalSlider_3_valueChanged(int value);

    void on_verticalSlider_4_valueChanged(int value);

    void on_verticalSlider_5_valueChanged(int value);

    void on_verticalSlider_6_valueChanged(int value);

    void on_verticalSlider_7_valueChanged(int value);

    void on_verticalSlider_8_valueChanged(int value);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_doubleSpinBox_6_valueChanged(double arg1);

    void on_doubleSpinBox_7_valueChanged(double arg1);

    void on_doubleSpinBox_8_valueChanged(double arg1);

    void on_showHistButton_clicked();
signals:
    void newData(sensores data);                                                       // Emitted when new data has arrived

private:
    Ui::MainWindow *ui;

    ThermoMeter *termometros[CANT];
    QLabel *temps_actuales[CANT];

    bool connected;                                                                       // Status connection variable
    bool plotting;                                                                        // Status plotting variable
    int dataPointNumber;                                                                  // Keep track of data points
    QTimer updateTimer;                                                                   // Timer used for replotting the plot
    int numberOfAxes, numberOfAxes2;                                                                     // Number of axes for the plot
    QTime timeOfFirstData;                                                                // Record the time of the first data point
    double timeBetweenSamples;                                                            // Store time between samples
    QSerialPort *serialPort;                                                              // Serial port; runs in this thread
    QString receivedData;                                                                 // Used for reading from the port
    int STATE;                                                                            // State of recieiving message from port
    int NUMBER_OF_POINTS;                                                                 // Number of points plotted
    HelpWindow *helpWindow;

    QCustomPlot *pl;

    QPen colores[CANT];
    bool habilitado[CANT];


    void exportarExcel();
    void colourSetup();

    int h;
    void createUI();                                                                      // Populate the controls
    void crearGrafico();                                                                     // Setup the QCustomPlot

    void SetActualTemp(int fermentador, double temp);
    void UpdateTemps();
    void UpdateTargets();
    void UpdateConfig();

    double CalcRange(int value) ;
    int CalcRange(double value);

    double high;
    double lower;
    double res;
    int max_slider, min_slider;

    QSlider *sliders[CANT];
    QDoubleSpinBox *edit_target[CANT];


    /******* fin ********/

    QSettings setting;

    QThread tarea;
    nRFTask *task;
    sensores temperaturas;
    conf configuracion;
    target temp_target;

    // Base de datos
    DataBase *db;
    QTime *tiempo;
                                                                                          // Open the inside serial port with these parameters
};


#endif                                                                                    // MAINWINDOW_HPP
