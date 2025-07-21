#include "formcredentials.h"
#include "ui_formcredentials.h"
#include <QPushButton>
#include "credentials.h"

FormCredentials::FormCredentials(int newId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormCredentials)
{
    ui->setupUi(this);
    connect(ui->btnSave, &QPushButton::clicked, this, &FormCredentials::accept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &FormCredentials::reject);
    ui->lineEditId->setText(QString::number(newId));
    ui->lineEditId->setReadOnly(true);
}

FormCredentials::~FormCredentials()
{
    delete ui;
}

int FormCredentials::GetId(){return ui->lineEditId->text().toInt();}
string FormCredentials::GetName(){return ui->lineEditName->text().toStdString();}
string FormCredentials::GetUser(){return ui->lineEditUser->text().toStdString();}
string FormCredentials::GetPassword(){return ui->lineEditPassword->text().toStdString();}
string FormCredentials::GetEmail(){return ui->lineEditMail->text().toStdString();}
int FormCredentials::GetPhone(){return ui->lineEditPhone->text().toInt();}

void FormCredentials::setDatos(Credentials credentials){
    ui->lineEditId->setText(QString::number(credentials.GetId()));
    ui->lineEditId->setReadOnly(true); // Hacemos que el ID no se pueda editar
    ui->lineEditName->setText(QString::fromStdString(credentials.GetName()));
    ui->lineEditUser->setText(QString::fromStdString(credentials.GetUser()));
    ui->lineEditPassword->setText(QString::fromStdString(credentials.GetPassword()));
    ui->lineEditMail->setText(QString::fromStdString(credentials.GetEmail()));
    ui->lineEditPhone->setText(QString::number(credentials.GetPhone()));
}
