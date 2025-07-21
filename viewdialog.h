#ifndef VIEWDIALOG_H
#define VIEWDIALOG_H
#include <QTimer>
#include <QDialog>
#include "credentials.h" // Incluimos la definición de Credentials

namespace Ui {
class ViewDialog;
}

class ViewDialog : public QDialog
{
    Q_OBJECT

public:
    // El constructor ahora recibe la credencial a mostrar
    explicit ViewDialog(const Credentials& credential, QWidget *parent = nullptr);
    ~ViewDialog();

private slots:
    // Slot para el clic del botón de copiar
    void on_btnCopyPassword_clicked();

private:
    Ui::ViewDialog *ui;
    QString m_password; // Variable para guardar la contraseña
};

#endif // VIEWDIALOG_H
