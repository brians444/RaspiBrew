#include "mainwindow.hpp"
#include "ui_mainwindow.h"



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
