#include "setupdialog.h"
#include "ui_setupdialog.h"
#include <QMessageBox>

SetupDialog::SetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupDialog)
{
    ui->setupUi(this);
    connect(ui->btnOk, &QPushButton::clicked, this, &SetupDialog::accept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}

SetupDialog::~SetupDialog()
{
    delete ui;
}

QString SetupDialog::getPassword() const
{
    // Asegúrate de que el QLineEdit se llama linePassword1 en el .ui
    return ui->linePassword1->text();
}

// Esta es la función que da errores, ahora corregida:
void SetupDialog::accept()
{
    // Usamos los nombres correctos: linePassword1 y linePassword2
    if (ui->linePassword1->text().isEmpty() || ui->linePassword2->text().isEmpty()) {
        QMessageBox::warning(this, "Contraseña Vacía", "La contraseña no puede estar vacía.");
        return;
    }
    if (ui->linePassword1->text() != ui->linePassword2->text()) {
        QMessageBox::warning(this, "Error", "Las contraseñas no coinciden.");
        return;
    }

    // Si todo está bien, llamamos al método accept() original para cerrar el diálogo.
    QDialog::accept();
}
