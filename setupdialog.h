#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>

namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupDialog(QWidget *parent = nullptr);
    ~SetupDialog();
    QString getPassword() const;

public slots:
    void accept() override; // Declaramos que vamos a sobreescribir la función accept

private:
    Ui::SetupDialog *ui;
};

#endif // SETUPDIALOG_H
