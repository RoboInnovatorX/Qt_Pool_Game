#ifndef QTGAME_H
#define QTGAME_H

#include <QMainWindow>
#include <QApplication>
#include <QFileDialog>
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QtGame; }
QT_END_NAMESPACE

class QtGame : public QMainWindow
{
    Q_OBJECT

public:
    QtGame(QWidget *parent = nullptr);
    ~QtGame();
    virtual void paintEvent(QPaintEvent * event);


private slots:
    void on_Radious_Change_valueChanged(int arg1);

    void on_Velocity_Change_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_CheckMark_stateChanged(int arg1);

    void Circle_Move();

    void on_CheckMark_clicked();

private:
    Ui::QtGame *ui;
    QTimer timer;
    QColor mycolor = QColor(Qt::yellow);
    int radious_value=15;
    int PosX = 20;
    int PosY = 20;
    int Velocity =10;

};
#endif // QTGAME_H
