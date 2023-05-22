#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout* layout = new QHBoxLayout;
    oriWgt= new OriWidget(this);
    layout->addWidget(oriWgt);
    ui->label->setLayout(layout);

    connect(oriWgt,&OriWidget::sigReady,this,&Widget::Clip_slot);//当oriwgt发送截取完毕信号的时候，Clip_slot函数进行处理

}

Widget::~Widget()
{
    delete ui;
}

//左下角显示文件名
void Widget::on_OpenBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"open picture","","Images (*.png *.xpm *.jpg)");
    QFileInfo fileInfo(fileName);

    ui->label_pic_name->setText(fileInfo.fileName());
    oriWgt->setPixMap(fileName);
    oriWgt->update();
}

//当左侧的oriwidget发送截图信号的时候
//这个地方进行图片的截取和保存
void Widget::Clip_slot()
{
    //根据oriwiget获取的第一次点击点的位置和鼠标释放的位置获取截取位置和大小
    qDebug()<<"success";
   // QPoint leftTop = oriWgt->pointPress
    int left,right,top,buttom;
    if(oriWgt->pointRelease.x()>oriWgt->pointPress.x()){
        left= oriWgt->pointPress.x();
        right = oriWgt->pointRelease.x();
    }

    if(oriWgt->pointRelease.y()>oriWgt->pointPress.y()){
        top= oriWgt->pointPress.y();
        buttom = oriWgt->pointRelease.y();
    }

    //根据截取位置和大小进行图片的截取
    pixmap = QPixmap::grabWidget(oriWgt,left,top,right-left,buttom-top);

    qDebug()<<right-left<<buttom-top;
    ui->label_clip->setPixmap(pixmap);

}
//图片保存
void Widget::on_SaveBtn_clicked()
{
   // QString fileName = QFileDialog::getSaveFileName(this);
    pixmap.save("roi.jpg");
    QApplication::quit();
}
