#include "deletedonor.h"
#include "ui_deletedonor.h"
#include "QMessageBox"

deletedonor::deletedonor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletedonor)
{
    ui->setupUi(this);
}

deletedonor::~deletedonor()
{
    delete ui;
}

void deletedonor::on_btnDel_clicked()
{
    QString ID = ui->txtID->text();
    qDebug() << "ID:"<<ID;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    if (!database.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open the database"));
        return;
    }

    QSqlQuery query(database);
    query.prepare("DELETE FROM Donor WHERE ID = :ID");
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








