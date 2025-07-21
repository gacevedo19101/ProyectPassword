#include "mainwindow.h"
#include "logindialog.h"
#include "setupdialog.h"

#include <QApplication>
#include <QSettings>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSettings settings("MiEmpresa", "PasswordManager");

    if (!settings.contains("master_hash")) {
        SetupDialog setupDialog;
        if (setupDialog.exec() == QDialog::Accepted) {
            QString password = setupDialog.getPassword();
            QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
            settings.setValue("master_hash", hash);
        } else {
            return 0;
        }
    }

    // Declaramos la variable ANTES del bucle
    QString enteredPassword;
    bool loginSuccess = false;

    while (!loginSuccess) {
        LoginDialog loginDialog;
        if (loginDialog.exec() == QDialog::Accepted) {
            // Asignamos el valor a la variable ya existente
            enteredPassword = loginDialog.getPassword();

            QByteArray storedHash = settings.value("master_hash").toByteArray();
            QByteArray enteredHash = QCryptographicHash::hash(enteredPassword.toUtf8(), QCryptographicHash::Sha256);

            if (enteredHash == storedHash) {
                loginSuccess = true;
            } else {
                QMessageBox::warning(nullptr, "Error de Acceso", "Contraseña maestra incorrecta.");
            }
        } else {
            return 0;
        }
    }

    // Ahora 'enteredPassword' sí existe y se la podemos pasar a MainWindow
    MainWindow w(enteredPassword);
    w.show();
    return a.exec();
}
