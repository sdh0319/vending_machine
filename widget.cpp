#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdnumber->display(money);
    checkMoney();
    //ui->pbTea->setEnabled(bool);

}

void Widget::checkMoney()
{
    if(money >= 100){
        ui->pbCoffe->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbCola->setEnabled(false);
        if(money >= 150){
            ui->pbTea->setEnabled(true);
            ui->pbCola->setEnabled(false);
            if(money >= 200){
                ui->pbCola->setEnabled(true);
            }
        }
    }
    else {
        ui->pbTea->setEnabled(false);
        ui->pbCola->setEnabled(false);
        ui->pbCoffe->setEnabled(false);
    }
}

void Widget::chMoney(int ch[4])
{
    for(int i=0;i<4;i++){
        if(money >= money_type[i]){
            ch[i]=money/money_type[i];
            money = money%money_type[i];
        }
    }
}

void Widget::on_pb10_clicked()
{
    //QMessageBox msg;
    //msg.warning(nullptr,"titlebox","Hello world");
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffe_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCola_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbreset_clicked()
{
    QMessageBox msg;
    int len{0};
    char buf[256]={0};
    int ch[4]={0};
    chMoney(ch);
    for(int i=0;i<4;i++){
        if( ch[i] >= 1){
            len+=sprintf(buf+len,"%dwon:%d\n",money_type[i],ch[i]);
        }
    }
    msg.information(nullptr,"titlebox",buf);
    ui->lcdnumber->display(0);
    checkMoney();
}
