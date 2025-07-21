#include "viewdialog.h"
#include "ui_viewdialog.h"
#include <QClipboard>
#include <QApplication>

ViewDialog::ViewDialog(const Credentials& credential, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewDialog)
{
    ui->setupUi(this);

    // Conectamos el botón de cerrar
    connect(ui->btnClose, &QPushButton::clicked, this, &ViewDialog::accept);

    // Llenamos todas las etiquetas con los datos de la credencial
    ui->labelIdValue->setText(QString::number(credential.GetId()));
    ui->labelNameValue->setText(QString::fromStdString(credential.GetName()));
    ui->labelUserValue->setText(QString::fromStdString(credential.GetUser()));
    ui->labelPasswordValue->setText(QString::fromStdString(credential.GetPassword()));
    ui->labelMailValue->setText(QString::fromStdString(credential.GetEmail()));
    ui->labelPhoneValue->setText(QString::number(credential.GetPhone()));
    m_password = QString::fromStdString(credential.GetPassword());
}

ViewDialog::~ViewDialog()
{
    delete ui;
}

// viewdialog.cpp

void ViewDialog::on_btnCopyPassword_clicked()
{
    // 1. Obtenemos una referencia al portapapeles del sistema
    QClipboard *clipboard = QApplication::clipboard();
    // Ponemos el texto de nuestra contraseña en el portapapeles
    clipboard->setText(m_password);

    // 2. Damos una señal visual al usuario de que se copió
    ui->btnCopyPassword->setText("¡Copiado!");
    ui->btnCopyPassword->setEnabled(false); // Desactivamos el botón temporalmente

    // Inicia un temporizador que se ejecutará una sola vez después de 20 segundos (20000 ms).
    QTimer::singleShot(10000, this, [=]() {
        // Esta acción se ejecuta cuando pasan los 20 segundos.

        // Verificamos si el portapapeles todavía contiene nuestra contraseña.
        // Esto es por si el usuario ya copió otra cosa.
        if (clipboard->text() == m_password) {
            clipboard->clear(); // Si es así, lo limpiamos.
            qDebug() << "Portapapeles limpiado automáticamente.";
        }

        // Restauramos el botón a su estado original.
        ui->btnCopyPassword->setText("Copiar Contraseña");
        ui->btnCopyPassword->setEnabled(true);
    });
}
