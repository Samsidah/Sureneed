#include "requests.h"
#include "ui_requests.h"
#include "home.h"
#include "QMessageBox"


Requests::Requests(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Requests)
{
    ui->setupUi(this);
    requestform= new RequestForm();
    archive= new Archive();

}

Requests::~Requests()
{
    delete ui;
}

void Requests::on_btnShow_clicked()
{
    QSqlDatabase sureneedbmsdb = QSqlDatabase:: addDatabase("QSQLITE");
    sureneedbmsdb.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    if (!sureneedbmsdb.open()){
        qDebug() <<"Error opening database:"<<sureneedbmsdb.lastError().text();
        return;
    }
    QSqlQuery q;
    QString data = "";
    q.exec("Select CID,FirstName,MiddleName,LastName,BloodTypeNeeded,DateRequested FROM Consumer");

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(q);
    ui->tableView->setModel(model);

    sureneedbmsdb.close();
}


void Requests::on_btnUpdate_clicked()
{
    requestform->show();
}


void Requests::on_btnDelete_clicked()
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
    query.prepare("DELETE FROM Consumer WHERE CID = :CID");
    query.bindValue(":CID", CID);

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


void Requests::on_btnSearch_clicked()
{
    QString CID = ui->txtCID->text();
    qDebug() << "CID:" << CID;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    archive->show();
}

