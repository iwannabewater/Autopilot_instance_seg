#ifndef ORIWIDGET_H
#define ORIWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPixmap>
namespace Ui {
class OriWidget;
}

class OriWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OriWidget(QWidget *parent = nullptr);
    ~OriWidget();

    void setPixMap(QString picPath);

private:
    Ui::OriWidget *ui;


    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);

    QPoint pointPress;
    QPoint pointRelease;

signals:
    void sigReady();
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    QPixmap m_pixMap;
    bool m_bPress;

        QPoint pointMove;
};

#endif // ORIWIDGET_H