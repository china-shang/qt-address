#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString getname(){
        return name;
    }
    QString getaddress(){
        return address;
    }

private slots:


    //void on_buttonBox_clicked(QAbstractButton *button);

    void on_textEdit_textChanged();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::Dialog *ui;
    QString name;
    QString address;
};

#endif // DIALOG_H
