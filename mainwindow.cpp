#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formcredentials.h"
#include <QMessageBox>
#include <QDebug>
#include <typeinfo>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "viewdialog.h"
#include <QCryptographicHash>
MainWindow::MainWindow(const QString& masterPassword, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_masterPassword(masterPassword)
{
    ui->setupUi(this);
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::clickAdd);
    connect(ui->btnEdit, &QPushButton::clicked, this, &MainWindow::clickEdit);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MainWindow::clickDelete);
    connect(ui->btnExport, &QPushButton::clicked, this, &MainWindow::clickExport);
    connect(ui->btnView, &QPushButton::clicked, this, &MainWindow::click_view);
    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::close);
    cargarDatos();
    listUpdate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listUpdate()
{
    ui->listAccount->clear(); // Limpiamos la lista visual
    for(const auto& credential : myList.getList()) {
        QListWidgetItem* item = new QListWidgetItem();
        // Mostramos el nombre de la cuenta en la lista
        item->setText(QString::fromStdString(credential.GetName()));
        // Guardamos el ID de forma oculta para saber a quién editar/borrar
        item->setData(Qt::UserRole, credential.GetId());
        ui->listAccount->addItem(item);
    }
}

void MainWindow::clickAdd()
{
    // 1. Generamos el nuevo ID ANTES de abrir el formulario.
    int newId = myList.generateNewId();

    // 2. Le pasamos el nuevo ID al formulario al crearlo.
    FormCredentials form(newId, this);

    int resultado = form.exec();

    if(resultado == QDialog::Accepted){
        // El ID ya está definido, lo tomamos del formulario (que es de solo lectura).
        Credentials newCredential(
            form.GetId(),
            form.GetName(),
            form.GetUser(),
            form.GetPassword(),
            form.GetEmail(),
            form.GetPhone()
            );

        myList.addAccount(newCredential);
        listUpdate();
    }
}

void MainWindow::clickEdit()
{
    QListWidgetItem* selectedItem = ui->listAccount->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Sin selección", "Por favor, selecciona una cuenta para editar.");
        return;
    }

    int id = selectedItem->data(Qt::UserRole).toInt(); // Obtenemos el ID oculto

    // Buscamos la credencial en nuestra lista lógica
    Credentials credentialToEdit(0, "", "", "", "", 0); // Credencial temporal
    for (const auto& c : myList.getList()) {
        if (c.GetId() == id) {
            credentialToEdit = c;
            break;
        }
    }

    FormCredentials form(id, this);
    form.setWindowTitle("Editar Credencial");
    form.setDatos(credentialToEdit); // Llenamos el formulario con los datos actuales

    if (form.exec() == QDialog::Accepted) {
        Credentials updatedCredential(
            id, // Mantenemos el ID original
            form.GetName(),
            form.GetUser(),
            form.GetPassword(),
            form.GetEmail(),
            form.GetPhone()
            );
        myList.editAccount(updatedCredential);
        listUpdate();
    }
}

void MainWindow::clickDelete()
{
    QListWidgetItem* selectedItem = ui->listAccount->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Sin selección", "Por favor, selecciona una cuenta para eliminar.");
        return;
    }

    int id = selectedItem->data(Qt::UserRole).toInt();
    QString name = selectedItem->text();

    int respuesta = QMessageBox::question(this, "Confirmar Eliminación",
                                          "¿Estás seguro de que quieres eliminar la cuenta '" + name + "'?",
                                          QMessageBox::Yes | QMessageBox::No);

    if (respuesta == QMessageBox::Yes) {
        myList.removeAccount(id);
        listUpdate();
    }
}

void MainWindow::clickExport()
{
    QString rutaArchivo = QFileDialog::getSaveFileName(this, "Exportar Cuentas", "", "Archivo de Texto (*.txt)");
    if (rutaArchivo.isEmpty()) {
        return;
    }

    QString contenido;
    for (const auto& c : myList.getList()) {
        contenido += "---------------------------------\n";
        contenido += "Account: " + QString::fromStdString(c.GetName()) + "\n";
        contenido += "ID: " + QString::number(c.GetId()) + "\n";
        contenido += "User: " + QString::fromStdString(c.GetUser()) + "\n";
        contenido += "Password: " + QString::fromStdString(c.GetPassword()) + "\n";
        contenido += "Email: " + QString::fromStdString(c.GetEmail()) + "\n";
        contenido += "Phone: " + QString::number(c.GetPhone()) + "\n";
    }
    contenido += "---------------------------------\n";

    QFile archivo(rutaArchivo);
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&archivo);
        stream << contenido;
        archivo.close();
        QMessageBox::information(this, "Exportación Exitosa", "Cuentas exportadas a:\n" + rutaArchivo);
    } else {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo.");
    }
}

void MainWindow::click_view()
{
    QListWidgetItem* selectedItem = ui->listAccount->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Sin selección", "Por favor, selecciona una cuenta para visualizar.");
        return;
    }

    int id = selectedItem->data(Qt::UserRole).toInt();

    Credentials credentialToShow(0, "", "", "", "", 0);
    bool found = false;
    for (const auto& c : myList.getList()) {
        if (c.GetId() == id) {
            credentialToShow = c;
            found = true;
            break;
        }
    }

    if (found) {
        ViewDialog dialog(credentialToShow, this);
        dialog.exec();
    } else {
        QMessageBox::critical(this, "Error", "No se encontró la credencial seleccionada.");
    }
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    // Esta función se activa al cerrar la ventana.
    guardarDatos(); // Llama a nuestra función de guardado.
    event->accept(); // Permite que la ventana se cierre.
}

void MainWindow::guardarDatos()
{
    QJsonArray credencialesArray;
    for (const auto& c : myList.getList()) {
        QJsonObject credencialObject;
        credencialObject["id"] = c.GetId();
        credencialObject["name"] = QString::fromStdString(c.GetName());
        credencialObject["user"] = QString::fromStdString(c.GetUser());
        credencialObject["password"] = QString::fromStdString(c.GetPassword());
        credencialObject["email"] = QString::fromStdString(c.GetEmail());
        credencialObject["phone"] = c.GetPhone();
        credencialesArray.append(credencialObject);
    }


    QJsonDocument doc(credencialesArray);
    QFile archivo("credenciales.json");

    if (archivo.open(QIODevice::WriteOnly)) {
        // Convertimos el documento JSON a bytes
        QByteArray datosJsonSinCifrar = doc.toJson();
        // Ciframos esos bytes usando nuestra función
        QByteArray datosCifrados = cifrar(datosJsonSinCifrar);
        // Guardamos los datos CIFRADOS
        archivo.write(datosCifrados);
        // -------------------------
        archivo.close();
    }
}

void MainWindow::cargarDatos()
{
    QFile archivo("credenciales.json");
    if (!archivo.open(QIODevice::ReadOnly)) {
        qDebug() << "No se encontró el archivo de credenciales.";
        return;
    }

    // Leemos los datos que están cifrados
    QByteArray datosCifrados = archivo.readAll();
    archivo.close();

    // Si no hay nada que leer, salimos.
    if(datosCifrados.isEmpty()){
        return;
    }

    // Desciframos los datos para obtener el JSON en texto plano
    QByteArray datosJsonDescifrados = descifrar(datosCifrados);
    // -------------------------

    QJsonDocument doc = QJsonDocument::fromJson(datosJsonDescifrados);
    QJsonArray credencialesArray = doc.array();

    // El resto de la función para leer el array no cambia
    for (const QJsonValue &valor : credencialesArray) {
        QJsonObject obj = valor.toObject();
        Credentials c(
            obj["id"].toInt(),
            obj["name"].toString().toStdString(),
            obj["user"].toString().toStdString(),
            obj["password"].toString().toStdString(),
            obj["email"].toString().toStdString(),
            obj["phone"].toInt()
            );
        myList.addAccount(c);
    }
}

QByteArray MainWindow::cifrar(const QByteArray& datos)
{
    // Generamos una clave a partir del hash de la contraseña maestra
    QByteArray clave = QCryptographicHash::hash(m_masterPassword.toUtf8(), QCryptographicHash::Sha256);
    QByteArray resultado;
    resultado.reserve(datos.size());

    for(int i = 0; i < datos.size(); ++i) {
        // Operación XOR: simple pero efectiva para demostración
        resultado.append(datos[i] ^ clave[i % clave.size()]);
    }
    return resultado;
}

QByteArray MainWindow::descifrar(const QByteArray& datosCifrados)
{
    // La operación XOR es simétrica, así que la función es idéntica
    return cifrar(datosCifrados);
}
