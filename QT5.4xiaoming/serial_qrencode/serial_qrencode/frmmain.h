#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QDialog>
#include <QPainter>
#include <QSerialPort>
#include <QPrinter>

namespace Ui
{
    class frmMain;
}

class frmMain : public QDialog
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_btnMenu_Max_clicked();
    void check_serial_port();
    void serialport_recv();
    void on_cboxStyle_currentIndexChanged(const QString &arg1);

    void on_open_port_Button_clicked();
    void on_prit_button_clicked();

    void on_print_button_clicked();
    void plotPic(QPrinter *printer);

private:
    Ui::frmMain *ui;

    void InitStyle();   //初始化无边框窗体
    void InitForm();    //初始化窗体数据
    void port_param_init();
    void open_serialport();
    void close_serialport();
    void QRcode_Encode(QByteArray &text);
    bool max;           //是否处于最大化状态
    QRect location;     //鼠标移动窗体后的坐标位置
    QColor foreground;
    QColor background;
    QByteArray rencode_text;
    quint8 state=0;
    QByteArray recv_arr;
    void log_output(QString info);
    void FrameParse(char c);
    QSerialPort *serialport;
};

#endif // FRMMAIN_H
