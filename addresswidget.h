#ifndef ADDRESSWIDGET_H
#define ADDRESSWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QTableView>
#include "newaddresstab.h"
#include "dialog.h"
#include "model.h"
#include "delegate.h"

namespace Ui {
class addresswidget;
}

class addresswidget : public QWidget
{
    Q_OBJECT

public:
    explicit addresswidget(QWidget *parent = 0);
    ~addresswidget();
signals:
    void senddetail(QString ,QString);
public slots:
    void addentry();

private:
    Ui::addresswidget *ui;
    NewAddressTab *newaddress;
    model *AddressModel;
    QTableView *view;
    Delegate *modelDelgate;

};

#endif // ADDRESSWIDGET_H
