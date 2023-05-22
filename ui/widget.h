#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "oriwidget.h"
#include <QPixmap>
//#include "clipwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_OpenBtn_clicked();
    void Clip_slot();

    void on_SaveBtn_clicked();

private:
    Ui::Widget *ui;
    OriWidget* oriWgt;
    //ClipWidget* clipWgt;
    QPixmap pixmap;
};
#endif // WIDGET_H
