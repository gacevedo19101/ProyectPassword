#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "listpassword.h"

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString& masterPassword, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void clickAdd();
    void clickEdit();
    void clickDelete();
    void clickExport();
    void click_view();

private:
    Ui::MainWindow *ui;
    ListPassword myList;
    void listUpdate();
    void guardarDatos();
    void cargarDatos();
    QString m_masterPassword;
    QByteArray cifrar(const QByteArray& datos);
    QByteArray descifrar(const QByteArray& datosCifrados);
};
#endif // MAINWINDOW_H
