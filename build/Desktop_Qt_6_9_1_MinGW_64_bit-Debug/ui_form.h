/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditId;
    QLineEdit *lineEditMail;
    QLineEdit *lineEditUser;
    QLabel *labelUser;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPassword;
    QLabel *labelId;
    QLabel *labelMail;
    QLabel *labelPassword;
    QLabel *labelPhone;
    QLineEdit *lineEditPhone;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(400, 300);
        gridLayoutWidget = new QWidget(Form);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 0, 351, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditId = new QLineEdit(gridLayoutWidget);
        lineEditId->setObjectName("lineEditId");

        gridLayout->addWidget(lineEditId, 0, 1, 1, 1);

        lineEditMail = new QLineEdit(gridLayoutWidget);
        lineEditMail->setObjectName("lineEditMail");

        gridLayout->addWidget(lineEditMail, 4, 1, 1, 1);

        lineEditUser = new QLineEdit(gridLayoutWidget);
        lineEditUser->setObjectName("lineEditUser");

        gridLayout->addWidget(lineEditUser, 2, 1, 1, 1);

        labelUser = new QLabel(gridLayoutWidget);
        labelUser->setObjectName("labelUser");

        gridLayout->addWidget(labelUser, 2, 0, 1, 1);

        labelName = new QLabel(gridLayoutWidget);
        labelName->setObjectName("labelName");

        gridLayout->addWidget(labelName, 1, 0, 1, 1);

        lineEditName = new QLineEdit(gridLayoutWidget);
        lineEditName->setObjectName("lineEditName");

        gridLayout->addWidget(lineEditName, 1, 1, 1, 1);

        lineEditPassword = new QLineEdit(gridLayoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        gridLayout->addWidget(lineEditPassword, 3, 1, 1, 1);

        labelId = new QLabel(gridLayoutWidget);
        labelId->setObjectName("labelId");

        gridLayout->addWidget(labelId, 0, 0, 1, 1);

        labelMail = new QLabel(gridLayoutWidget);
        labelMail->setObjectName("labelMail");

        gridLayout->addWidget(labelMail, 4, 0, 1, 1);

        labelPassword = new QLabel(gridLayoutWidget);
        labelPassword->setObjectName("labelPassword");

        gridLayout->addWidget(labelPassword, 3, 0, 1, 1);

        labelPhone = new QLabel(gridLayoutWidget);
        labelPhone->setObjectName("labelPhone");

        gridLayout->addWidget(labelPhone, 5, 0, 1, 1);

        lineEditPhone = new QLineEdit(gridLayoutWidget);
        lineEditPhone->setObjectName("lineEditPhone");

        gridLayout->addWidget(lineEditPhone, 5, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(Form);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(190, 260, 181, 41));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnCancel = new QPushButton(gridLayoutWidget_2);
        btnCancel->setObjectName("btnCancel");

        gridLayout_2->addWidget(btnCancel, 0, 0, 1, 1);

        btnSave = new QPushButton(gridLayoutWidget_2);
        btnSave->setObjectName("btnSave");

        gridLayout_2->addWidget(btnSave, 0, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        labelUser->setText(QCoreApplication::translate("Form", "User:", nullptr));
        labelName->setText(QCoreApplication::translate("Form", "Account name:", nullptr));
        labelId->setText(QCoreApplication::translate("Form", "ID:", nullptr));
        labelMail->setText(QCoreApplication::translate("Form", "Mail:", nullptr));
        labelPassword->setText(QCoreApplication::translate("Form", "Password:", nullptr));
        labelPhone->setText(QCoreApplication::translate("Form", "Phone:", nullptr));
        btnCancel->setText(QCoreApplication::translate("Form", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("Form", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
