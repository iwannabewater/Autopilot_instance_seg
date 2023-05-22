#include "oriwidget.h"
#include "ui_oriwidget.h"
#include <QPainter>
#include <QDebug>
OriWidget::OriWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OriWidget),m_bPress(false),pointPress(0,0),pointRelease(0,0),pointMove(0,0)
{
    ui->setupUi(this);
    //事件过滤器，所有针对该widget的信号都通过eventFIlter处理
    installEventFilter(this);
}

OriWidget::~OriWidget()
{
    delete ui;
}

void OriWidget::setPixMap(QString picPath)
{
    m_pixMap.load(picPath);
}


//这个用来截获widget上的消息，主要就是获取鼠标左键按下的坐标；按下并移动时鼠标的坐标用来绘制红色框图
//左键释放时的坐标用来和之前鼠标第一次点击的坐标进行截图、
//鼠标松开后发送emit sigReady();信号，通知主界面widget进行截图
bool OriWidget::eventFilter(QObject *watched, QEvent *event)
{
    qDebug()<<event->type();
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent * evt = static_cast<QMouseEvent*>(event);
        pointPress = evt->pos();
        m_bPress=true;
        //qDebug()<<pointPress;
        return true;
    }else if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent * evt = static_cast<QMouseEvent*>(event);
        pointRelease = evt->pos();
        m_bPress=false;
        update();
        emit sigReady();
        //qDebug()<<pointRelease;
        return true;
    }else if(event->type() == QEvent::MouseMove)
    {
        QMouseEvent * evt = static_cast<QMouseEvent*>(event);
        pointMove = evt->pos();
        update();
        //qDebug()<<pointMove;
        return true;
    }
    return false;

}

//这部分用于绘制左侧原始图片和方框
void OriWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!m_pixMap.isNull()){
        auto pixmap = m_pixMap.scaled(this->rect().width(),this->rect().height(),Qt::KeepAspectRatio);
        painter.drawPixmap(0,0,pixmap/*m_pixMap*/);
    }

    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    painter.setPen(pen);

    //根据左键第一次点击和移动点绘制方框
    if(m_bPress)
        painter.drawRect(QRect(pointPress,pointMove));

}
