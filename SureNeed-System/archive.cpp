#include "archive.h"
#include "ui_archive.h"

#include <QMessageBox>
#include <QStringListModel>
#include <QSqlQuery>
#include <QsqlError>
#include <QDebug>

Archive::Archive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Archive)
{
    ui->setupUi(this);
}

Archive::~Archive()
{
    delete ui;
}

void Archive::on_btnShowA_clicked()
{
    QString CID = ui->txtCID->text();
    qDebug() << "CID:" << CID;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    if (!database.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open the database"));
        return;
    }
    QSqlQuery query(database);
    query.prepare("SELECT FirstName,MiddleName,LastName,Gender,Age,DateofBirth,Address,ContactNumber,EmailAddress,Occupation,BloodTypeNeeded,DateRequested FROM Consumer WHERE CID = :CID");
    query.bindValue(":CID", CID);

    if (query.exec())
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);
        ui->tableView->setModel(model);
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
    }

    database.close();
    }


