#include "delegate.h"


QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
       QLineEdit *editor=new QLineEdit(parent) ;
       return  editor;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString data=index.model()->data(index).toString();
    if(index.column()==0)
    {
        QLineEdit *lineEdit=static_cast<QLineEdit*>(editor);
        lineEdit->setText(data);
    }
    else
    {
        static_cast<QLineEdit*>(editor)->setText("new");
    }

}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

    QLineEdit *lineEdit=static_cast<QLineEdit*>(editor);
    QString data=lineEdit->text();
    model->setData(index,data,Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}





