/********************************************************************************
** Form generated from reading UI file 'viewdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWDIALOG_H
#define UI_VIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewDialog
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnClose;
    QPushButton *btnCopyPassword;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelPassword;
    QLabel *labelMail;
    QLabel *labelId;
    QLabel *labelUser;
    QLabel *labelName;
    QLabel *labelPhone;
    QLabel *labelIdValue;
    QLabel *labelNameValue;
    QLabel *labelUserValue;
    QLabel *labelPasswordValue;
    QLabel *labelMailValue;
    QLabel *labelPhoneValue;

    void setupUi(QDialog *ViewDialog)
    {
        if (ViewDialog->objectName().isEmpty())
            ViewDialog->setObjectName("ViewDialog");
        ViewDialog->resize(400, 300);
        gridLayoutWidget_2 = new QWidget(ViewDialog);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(200, 260, 181, 41));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnClose = new QPushButton(gridLayoutWidget_2);
        btnClose->setObjectName("btnClose");

        gridLayout_2->addWidget(btnClose, 0, 0, 1, 1);

        btnCopyPassword = new QPushButton(gridLayoutWidget_2);
        btnCopyPassword->setObjectName("btnCopyPassword");

        gridLayout_2->addWidget(btnCopyPassword, 0, 1, 1, 1);

        gridLayoutWidget = new QWidget(ViewDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 0, 351, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelPassword = new QLabel(gridLayoutWidget);
        labelPassword->setObjectName("labelPassword");

        gridLayout->addWidget(labelPassword, 3, 0, 1, 1);

        labelMail = new QLabel(gridLayoutWidget);
        labelMail->setObjectName("labelMail");

        gridLayout->addWidget(labelMail, 4, 0, 1, 1);

        labelId = new QLabel(gridLayoutWidget);
        labelId->setObjectName("labelId");

        gridLayout->addWidget(labelId, 0, 0, 1, 1);

        labelUser = new QLabel(gridLayoutWidget);
        labelUser->setObjectName("labelUser");

        gridLayout->addWidget(labelUser, 2, 0, 1, 1);

        labelName = new QLabel(gridLayoutWidget);
        labelName->setObjectName("labelName");

        gridLayout->addWidget(labelName, 1, 0, 1, 1);

        labelPhone = new QLabel(gridLayoutWidget);
        labelPhone->setObjectName("labelPhone");

        gridLayout->addWidget(labelPhone, 5, 0, 1, 1);

        labelIdValue = new QLabel(gridLayoutWidget);
        labelIdValue->setObjectName("labelIdValue");

        gridLayout->addWidget(labelIdValue, 0, 1, 1, 1);

        labelNameValue = new QLabel(gridLayoutWidget);
        labelNameValue->setObjectName("labelNameValue");

        gridLayout->addWidget(labelNameValue, 1, 1, 1, 1);

        labelUserValue = new QLabel(gridLayoutWidget);
        labelUserValue->setObjectName("labelUserValue");

        gridLayout->addWidget(labelUserValue, 2, 1, 1, 1);

        labelPasswordValue = new QLabel(gridLayoutWidget);
        labelPasswordValue->setObjectName("labelPasswordValue");

        gridLayout->addWidget(labelPasswordValue, 3, 1, 1, 1);

        labelMailValue = new QLabel(gridLayoutWidget);
        labelMailValue->setObjectName("labelMailValue");

        gridLayout->addWidget(labelMailValue, 4, 1, 1, 1);

        labelPhoneValue = new QLabel(gridLayoutWidget);
        labelPhoneValue->setObjectName("labelPhoneValue");

        gridLayout->addWidget(labelPhoneValue, 5, 1, 1, 1);


        retranslateUi(ViewDialog);

        QMetaObject::connectSlotsByName(ViewDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewDialog)
    {
        ViewDialog->setWindowTitle(QCoreApplication::translate("ViewDialog", "Dialog", nullptr));
        btnClose->setText(QCoreApplication::translate("ViewDialog", "Close", nullptr));
        btnCopyPassword->setText(QCoreApplication::translate("ViewDialog", "Copy", nullptr));
        labelPassword->setText(QCoreApplication::translate("ViewDialog", "Password:", nullptr));
        labelMail->setText(QCoreApplication::translate("ViewDialog", "Mail:", nullptr));
        labelId->setText(QCoreApplication::translate("ViewDialog", "ID:", nullptr));
        labelUser->setText(QCoreApplication::translate("ViewDialog", "User:", nullptr));
        labelName->setText(QCoreApplication::translate("ViewDialog", "Account name:", nullptr));
        labelPhone->setText(QCoreApplication::translate("ViewDialog", "Phone:", nullptr));
        labelIdValue->setText(QCoreApplication::translate("ViewDialog", "TextLabel", nullptr));
        labelNameValue->setText(QCoreApplication::translate("ViewDialog", "TextLabel", nullptr));
        labelUserValue->setText(QCoreApplication::translate("ViewDialog", "TextLabel", nullptr));
        labelPasswordValue->setText(QCoreApplication::translate("ViewDialog", "TextLabel", nullptr));
        labelMailValue->setText(QCoreApplication::translate("ViewDialog", "TextLabel", nullptr));
        labelPhoneValue->setText(QCoreApplication::translate("ViewDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewDialog: public Ui_ViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWDIALOG_H
