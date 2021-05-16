#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPushButton>
#include <QMainWindow>
#include<QList>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();

    void on_savecolor_clicked();

    void on_loadcolor_clicked();

private:
    Ui::MainWindow *ui;
    QList<QColor>ColorList;
    void SaveColor(QString key,QColor color);
    QColor loadColor(QString key);
    void setLoadedColor(QString key,int index,QPushButton *button);
};
#endif // MAINWINDOW_H
