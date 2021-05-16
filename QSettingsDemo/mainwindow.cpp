#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColorDialog>
#include<QSettings>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ColorList<<Qt::yellow<<Qt::red<<Qt::blue<<Qt::gray<<Qt::green<<Qt::darkMagenta<<Qt::cyan<<Qt::darkCyan<<Qt::darkYellow<<Qt::magenta;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_1_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[0],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[0]=color;
        ui->Button_1->setStyleSheet("background-color:"+color.name()+";");

      }
}
void MainWindow::on_Button_2_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[1]=color;
        ui->Button_2->setStyleSheet("background-color:"+color.name()+";");

      }

}
void MainWindow::on_Button_3_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[2],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[2]=color;
        ui->Button_3->setStyleSheet("background-color:"+color.name()+";");

      }
}
void MainWindow::on_Button_4_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[3],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[3]=color;
        ui->Button_4->setStyleSheet("background-color:"+color.name()+";");

      }
}
void MainWindow::on_Button_5_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[4],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[4]=color;
        ui->Button_5->setStyleSheet("background-color:"+color.name()+";");

      }
}
void MainWindow::on_Button_6_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[5],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[5]=color;
        ui->Button_6->setStyleSheet("background-color:"+color.name()+";");

      }

}
void MainWindow::on_Button_7_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[6],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[6]=color;
        ui->Button_7->setStyleSheet("background-color:"+color.name()+";");

      }
}
void MainWindow::on_Button_8_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[7],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[7]=color;
        ui->Button_8->setStyleSheet("background-color:"+color.name()+";");

      }
}
void MainWindow::on_Button_9_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[8],this,"Choose Background color");
    if(color.isValid())
      {

        ColorList[8]=color;
        ui->Button_9->setStyleSheet("background-color:"+color.name()+";");

      }
}

void MainWindow::on_savecolor_clicked()
{
    SaveColor("Button 1",ColorList[0]);
    SaveColor("Button 2",ColorList[1]);
    SaveColor("Button 3",ColorList[2]);
    SaveColor("Button 4",ColorList[3]);
    SaveColor("Button 5",ColorList[4]);
    SaveColor("Button 6",ColorList[5]);
    SaveColor("Button 7",ColorList[6]);
    SaveColor("Button 8",ColorList[7]);
    SaveColor("Button 9",ColorList[8]);
}

void MainWindow::on_loadcolor_clicked()
{
    setLoadedColor("button 1",0,ui->Button_1);
    setLoadedColor("button 2",0,ui->Button_2);
    setLoadedColor("button 3",0,ui->Button_3);
    setLoadedColor("button 4",0,ui->Button_4);
    setLoadedColor("button 5",0,ui->Button_5);
    setLoadedColor("button 6",0,ui->Button_6);
    setLoadedColor("button 7",0,ui->Button_7);
    setLoadedColor("button 8",0,ui->Button_8);
    setLoadedColor("button 9",0,ui->Button_9);
}
void MainWindow::SaveColor(QString key, QColor color)
{
        int red=color.red(),green=color.green(),blue=color.blue();
        QSettings settings("MyColors","colors");

        settings.beginGroup("ButtonColor");

        settings.setValue(key +"r",red);
        settings.setValue(key +"g",green);
        settings.setValue(key +"b",blue);

        settings.endGroup();
}
QColor MainWindow::loadColor(QString key)
{
       int red,green,blue;
       QSettings settings("MyColors","colors");

       settings.beginGroup("ButtonColor");

       red=settings.value(key+"r",QVariant(0)).toInt();
       green=settings.value(key+"g",QVariant(0)).toInt();
       blue=settings.value(key+"b",QVariant(0)).toInt();

       settings.endGroup();

       return QColor(red,green,blue);
}
void MainWindow::setLoadedColor(QString key, int index, QPushButton *button)
{
       QColor color=loadColor(key);
        ColorList[index]=color;
        QString css=QString ("Background-color:%1").arg(color.name());

                button->setStyleSheet(css);
}
