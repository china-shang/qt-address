#include "addresswidget.h"
#include "ui_addresswidget.h"
#include <QTableView>

addresswidget::addresswidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addresswidget)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);

    newaddress =new NewAddressTab;
    ui->tabWidget->addTab(newaddress,tr("new address"));
    connect(newaddress,&NewAddressTab::addentry,this,&addresswidget::addentry);

    AddressModel=new model;
    view=new QTableView;
    view->setModel(AddressModel);
    view->horizontalHeader()->setStretchLastSection(true);
    view->verticalHeader()->hide();
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSortingEnabled(true);
    modelDelgate=new Delegate(view) ;
    view->setItemDelegate(modelDelgate);
    ui->tabWidget->addTab(view,"address");
    connect(this,&addresswidget::senddetail,AddressModel,&model::addnew);

}

addresswidget::~addresswidget()
{
    delete ui;
}
void addresswidget::addentry()
{
    Dialog addDialog;
    if(addDialog.exec()==Dialog::Accepted)
    {
        QString name=addDialog.getname();
        QString address=addDialog.getaddress();
        if(!AddressModel->contain(name)){
            emit senddetail(name,address);
            ui->tabWidget->removeTab(ui->tabWidget->indexOf(newaddress));
        }
        else
        {
            QMessageBox::information(this,tr("name conflict"),tr("name conflict "));
        }
    }
    else
    {
    }
}
