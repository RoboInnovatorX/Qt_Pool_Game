#include "QtGame.h"
#include "ui_qtgame.h"
#include <qpoint.h>


QtGame::QtGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtGame)
{
    ui->setupUi(this);
    ui->Radious_Change->setValue(radious_value);
    ui->Velocity_Change->setValue(Velocity);
    connect(&timer,SIGNAL(timeout()),this, SLOT(Circle_Move()));
    timer.start(100);
}

QtGame::~QtGame()
{
    delete ui;
}

void QtGame::paintEvent(QPaintEvent *event)
{

}


void QtGame::on_Radious_Change_valueChanged(int arg1)
{
    radious_value= ui->Radious_Change->value();

}


void QtGame::on_Velocity_Change_valueChanged(int arg1)
{
    Velocity = ui->Velocity_Change->value();
}


void QtGame::on_pushButton_clicked()
{
   mycolor = QColorDialog::getColor(Qt::yellow,this,"Choose color");

}


void QtGame::on_CheckMark_stateChanged(int arg1)
{

}

void QtGame::Circle_Move()
{


    PosX += Velocity;

    if (PosX - radious_value <= 0)
    {
    PosX = -PosX + 2*radious_value;
     Velocity = - Velocity;
    }
    if (PosX+radious_value>=ui->My_table->width())
    {
    PosX = ui->My_table->width() - (PosX - ui->My_table->width())-2*radious_value;
    Velocity=-Velocity;
    }

    PosY += Velocity;
    if (PosY - radious_value <= 0)
    {
    PosY = -PosY + 2*radious_value;
     Velocity = - Velocity;
    }
    if (PosY+radious_value>=ui->My_table->height())
    {
    PosY = ui->My_table->height() - (PosY - ui->My_table->height())-2*radious_value;
    Velocity=-Velocity;
    }

    QPixmap my_pixmap = QPixmap("MyTable.jpg").scaled(ui->My_table->size());

    QPainter painter(&my_pixmap);
    painter.setBrush(mycolor);
    painter.drawEllipse(QPoint(PosX,PosY),radious_value,radious_value);
    ui->My_table->setPixmap(my_pixmap);
}


void QtGame::on_CheckMark_clicked()
{
    if(ui->CheckMark->isChecked())
    {
        timer.stop();
    }
    else
        timer.start();

}

