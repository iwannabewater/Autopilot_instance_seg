/********************************************************************************
** Form generated from reading UI file 'oriwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORIWIDGET_H
#define UI_ORIWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OriWidget
{
public:

    void setupUi(QWidget *OriWidget)
    {
        if (OriWidget->objectName().isEmpty())
            OriWidget->setObjectName(QString::fromUtf8("OriWidget"));
        OriWidget->resize(753, 578);

        retranslateUi(OriWidget);

        QMetaObject::connectSlotsByName(OriWidget);
    } // setupUi

    void retranslateUi(QWidget *OriWidget)
    {
        OriWidget->setWindowTitle(QApplication::translate("OriWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OriWidget: public Ui_OriWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORIWIDGET_H
