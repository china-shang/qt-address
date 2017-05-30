#include "model.h"

model::model(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation==Qt::Horizontal)
        {
            switch (section) {
            case 0:
                return tr("name");
            case 1:
                return  tr("address");
            default:
                return QVariant();
            }
        }
    }
    return  QVariant();
}

bool model::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int model::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return  sourcedata.size();

}

int model::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return  2;

}

QVariant model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(role==Qt::DisplayRole)
    {
        if(index.column()==0)
        {
            return sourcedata.at(index.row()).first;
        }
        else if (index.column()==1) {
            return  sourcedata.at(index.row()).second;
        }
    }
    return  QVariant();

}

bool model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        QPair<QString , QString> pair=sourcedata.at(index.row());
        if(index.column()==0)
        {
            pair.first=value.toString();
        }
        else if (index.column()==1) {
            pair.second=value.toString();
        }
        sourcedata.replace(index.row(),pair);
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags model::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool model::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for(int i=0;i<count;i++)
    {
        QPair <QString,QString> pair(" "," ");
        sourcedata.insert(row,pair);
    }
    endInsertRows();
    return  true;
}

bool model::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    endInsertColumns();
    return  true;
}

bool model::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    for(int i=0;i<count;i++)
    {
        sourcedata.removeAt(row);
    }
    endRemoveRows();
    return  true;
}
void model::addnew(QString name,QString address)
{
    auto pair=QPair<QString,QString> (name,address);
    if(!sourcedata.contains(pair))
    {
        insertRows(0,1,QModelIndex());
        QModelIndex index2=this->index(0,0,QModelIndex());
        setData(index2,name,Qt::EditRole);
        QModelIndex index1=this->index(0,1,QModelIndex());
        setData(index1,address,Qt::EditRole);
        emit dataChanged(index1,index2);
    }
}

bool model::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    endRemoveColumns();
    return true;
}

bool model::contain(const QString &name)
{
    for(int i=0;i<sourcedata.size();i++)
    {
       if(sourcedata.at(i).first==name)
           return true;
    }
    return false;
}
