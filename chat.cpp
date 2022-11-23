#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    mServer=new QTcpServer(this);
        mServer->listen(QHostAddress::Any,2000);
        mSocket=new QTcpSocket(this);
        connect(mServer,SIGNAL(newConnection()),this,SLOT(conexion_nueva()));
}

Chat::~Chat()
{
    delete ui;
}
void Chat::conexion_nueva()
{
    mSocket=mServer->nextPendingConnection();
    connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer_socket()));
}

void Chat::leer_socket()
{
    QByteArray buffer;
    buffer.resize(mSocket->bytesAvailable());
    mSocket->read(buffer.data(),buffer.size());
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->appendPlainText(QString(buffer));
}


void Chat::on_sendButton_clicked()
{
    mSocket->write(ui->lineEdit->text().toLatin1().data(),ui->lineEdit->text().size());
    ui->plainTextEdit->appendPlainText(ui->lineEdit->text());
    ui->lineEdit->clear();
}
