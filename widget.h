#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    int money_type[4]={500,100,50,10};
    void changeMoney(int diff);
    void checkMoney();
    void chMoney(int ch[4]);

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffe_clicked();

    void on_pbTea_clicked();

    void on_pbCola_clicked();

    void on_pbreset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
