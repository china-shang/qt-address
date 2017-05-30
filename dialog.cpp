#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//void Dialog::on_buttonBox_clicked(QAbstractButton *button)
//{
//}

void Dialog::on_textEdit_textChanged()
{
   address=ui->textEdit-> toPlainText();
}

void Dialog::on_lineEdit_textEdited(const QString &arg1)
{
   name=arg1 ;
}
