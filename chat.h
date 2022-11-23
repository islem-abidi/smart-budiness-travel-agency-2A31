#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include<QTcpServer>
#include<QTcpSocket>
namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();
private slots:

    void conexion_nueva();
    void leer_socket();
    void on_sendButton_clicked();

private:
    Ui::Chat *ui;
    QTcpSocket *mSocket;
     QTcpServer *mServer;
};

#endif // CHAT_H
