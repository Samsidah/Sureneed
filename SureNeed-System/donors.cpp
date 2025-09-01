#include "donors.h"
#include "ui_donors.h"
#include "QMessageBox"
#include "databaseheader.h"
Donors::Donors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Donors)
{
    ui->setupUi(this);
}

Donors::~Donors()
{
    delete ui;
}

void Donors::on_btnShow_clicked()
{
    QString Identification = ui->lineEdit->text();
    qDebug() << "Identification:" << Identification;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    if (!database.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open the database"));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT FirstName, MiddleName, LastName, Age, DateOfBirth, Gender, AreaOfResidence, Occupation, ContactNumber, EmailAddress, DateDonated, BloodType, Identification FROM Donor WHERE Identification = :identification");
    query.bindValue(":identification", Identification);

    if (query.exec() && query.next()) {
        ui->txtFirstName->setText(query.value("FirstName").toString());
        ui->txtMiddleName->setText(query.value("MiddleName").toString());
        ui->txtLastName->setText(query.value("LastName").toString());
        ui->txtAge->setText(query.value("Age").toString());
        ui->txtDateofBirth->setText(query.value("DateOfBirth").toString());
        ui->txtGender->setText(query.value("Gender").toString());
        ui->txtAreaofResidence->setText(query.value("AreaOfResidence").toString());
        ui->txtOccupation->setText(query.value("Occupation").toString());
        ui->txtContactNumber->setText(query.value("ContactNumber").toString());
        ui->txtEmailAddress->setText(query.value("EmailAddress").toString());
        ui->txtDateDonated->setText(query.value("DateDonated").toString());
        ui->txtBloodType->setText(query.value("BloodType").toString());
        ui->txtIdentification->setText(query.value("Identification").toString());
    } else {
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    database.close();
}

