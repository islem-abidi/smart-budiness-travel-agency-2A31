#ifndef ARDUINO1_H
#define ARDUINO1_H
#include <QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>
class Arduino1
{
public:
    Arduino1();
    int connect_arduino1();
    int close_arduino1();
    int write_to_arduino1(QByteArray);
    QByteArray read_from_arduino1();
    QSerialPort* getserial();
    QString getarduino_port_name();

private:
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // ARDUINO_H
