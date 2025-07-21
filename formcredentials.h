#ifndef FORMCREDENTIALS_H
#define FORMCREDENTIALS_H

#include <QDialog>
#include "credentials.h"
#include <string>
namespace Ui {
class FormCredentials;
}

class FormCredentials : public QDialog
{
    Q_OBJECT

public:
    explicit FormCredentials(int newId, QWidget *parent = nullptr);
    ~FormCredentials();
    int GetId();
    string GetName();
    string GetUser();
    string GetPassword();
    string GetEmail();
    int GetPhone();
    void setDatos(Credentials credentials);

private:
    Ui::FormCredentials *ui;
};

#endif // FORMCREDENTIALS_H
