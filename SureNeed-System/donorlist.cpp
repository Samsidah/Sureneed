#include "donorlist.h"
#include "ui_donorlist.h"
#include "home.h"
#include "QMessageBox"


DonorList::DonorList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DonorList)
{
    ui->setupUi(this);
    donors = new Donors();
    donorform = new DonorForm();

}

DonorList::~DonorList()
{
    delete ui;
}

void DonorList::on_btnShow_clicked()
{

    QSqlDatabase sureneedbmsdb = QSqlDatabase:: addDatabase("QSQLITE");
    sureneedbmsdb.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    if (!sureneedbmsdb.open()){
        qDebug() <<"Error opening database:"<<sureneedbmsdb.lastError().text();
        return;
    }
    QSqlQuery q;
    QString data = "";
    q.exec("Select FirstName,MiddleName,LastName,BloodType,DateDonated,DateofBirth FROM Donor");

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(q);
    ui->tableView->setModel(model);

    sureneedbmsdb.close();
}


void DonorList::on_btnUpdate_clicked()
{
    donorform->show();
}

void DonorList::on_btnDelete_clicked()
{

    QString DateofBirth = ui->txtDateofBirth->text();
        qDebug() <<"DateofBirth:" << DateofBirth;

        // Remove the existing custom connection if it exists
        QSqlDatabase::removeDatabase("my_custom_connection");

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "my_custom_connection");
        database.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

        if (!database.open()) {
            QMessageBox::critical(this, tr("Error"), tr("Failed to open the database"));
            return;
        }

        QSqlQuery query(database);
        query.prepare("DELETE FROM Donor WHERE DateofBirth = :DateofBirth");
        query.bindValue(":DateofBirth", DateofBirth);

        if (query.exec())
        {
            QSqlTableModel *model = new QSqlTableModel(this, database);
            model->setTable("Donor");
            model->select(); // Refresh the model to reflect the changes

            if (model->submitAll()) {
                QMessageBox::information(this, tr("Delete"), tr("Deleted"));
            } else {
                QMessageBox::critical(this, tr("Error"), model->lastError().text());
            }

            delete model; // Clean up the model
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), query.lastError().text());
        }

        database.close();
    }


void DonorList::on_btnSearch_clicked()
{
        donors->show();
}

