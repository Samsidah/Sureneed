#include "deleteconsumer.h"
#include "ui_deleteconsumer.h"
#include<QMessageBox>

DeleteConsumer::DeleteConsumer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConsumer)
{
    ui->setupUi(this);
}

DeleteConsumer::~DeleteConsumer()
{
    delete ui;
}

void DeleteConsumer::on_pushButton_clicked()
{
    QString ID = ui->txtID->text();
    qDebug() << "ID:" << ID;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    if (!database.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open the database"));
        return;
    }

    QSqlQuery query(database);
    query.prepare("DELETE FROM Consumer WHERE ID = :ID");
    query.bindValue(":ID", ID);

    if (query.exec())
    {
        QMessageBox::information(this, tr("Delete"), tr("Deleted"));
        return;
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
    }

    database.close();
}


