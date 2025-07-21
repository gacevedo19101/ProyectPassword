/********************************************************************************
** Form generated from reading UI file 'setupdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPDIALOG_H
#define UI_SETUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetupDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *linePassword2;
    QLineEdit *linePassword1;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnCancel;
    QPushButton *btnOk;

    void setupUi(QDialog *SetupDialog)
    {
        if (SetupDialog->objectName().isEmpty())
            SetupDialog->setObjectName("SetupDialog");
        SetupDialog->resize(378, 127);
        gridLayoutWidget = new QWidget(SetupDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 361, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        linePassword2 = new QLineEdit(gridLayoutWidget);
        linePassword2->setObjectName("linePassword2");

        gridLayout->addWidget(linePassword2, 1, 1, 1, 1);

        linePassword1 = new QLineEdit(gridLayoutWidget);
        linePassword1->setObjectName("linePassword1");

        gridLayout->addWidget(linePassword1, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 2, 0, 1, 1);

        btnOk = new QPushButton(gridLayoutWidget);
        btnOk->setObjectName("btnOk");

        gridLayout->addWidget(btnOk, 2, 1, 1, 1);

        QWidget::setTabOrder(linePassword1, linePassword2);

        retranslateUi(SetupDialog);

        QMetaObject::connectSlotsByName(SetupDialog);
    } // setupUi

    void retranslateUi(QDialog *SetupDialog)
    {
        SetupDialog->setWindowTitle(QCoreApplication::translate("SetupDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SetupDialog", "Crear Contrase\303\261a Maestra:", nullptr));
        label_2->setText(QCoreApplication::translate("SetupDialog", "Confirmar Contrase\303\261a:", nullptr));
        btnCancel->setText(QCoreApplication::translate("SetupDialog", "Cancel", nullptr));
        btnOk->setText(QCoreApplication::translate("SetupDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetupDialog: public Ui_SetupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPDIALOG_H
