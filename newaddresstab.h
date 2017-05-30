#ifndef NEWADDRESSTAB_H
#define NEWADDRESSTAB_H

#include <QWidget>

namespace Ui {
class NewAddressTab;
}

class NewAddressTab : public QWidget
{
    Q_OBJECT

public:
    explicit NewAddressTab(QWidget *parent = 0);
    ~NewAddressTab();
signals:
    void addentry();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewAddressTab *ui;
};

#endif // NEWADDRESSTAB_H
