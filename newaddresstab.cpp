#include "newaddresstab.h"
#include "ui_newaddresstab.h"

NewAddressTab::NewAddressTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewAddressTab)
{
    ui->setupUi(this);
}

NewAddressTab::~NewAddressTab()
{
    delete ui;
}


void NewAddressTab::on_pushButton_clicked()
{
    emit addentry();
}
