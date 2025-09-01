#include "donorform.h"
#include "ui_donorform.h"

DonorForm::DonorForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DonorForm)
{
    ui->setupUi(this);
}

DonorForm::~DonorForm()
{
    delete ui;
}


void DonorForm::on_btnSubmit_clicked()
{
    QString Identification = ui ->txtIdentification->text();
    QString FirstName = ui ->txtFirstName->text();
    QString  MiddleName= ui ->txtMiddleName ->text();
    QString LastName = ui ->txtLastName ->text();
    QString Age = ui->txtAge->text();
    QString DateofBirth = ui->txtDateofBirth->text();
    QString Gender = ui ->txtGender->text();
    QString AreaofResidence = ui->txtAreaofResidence->text();
    QString Occupation = ui->txtOccupation->text();
    QString ContactNumber = ui ->txtContactNumber ->text();
    QString EmailAddress = ui->txtEmailAddress->text();
    QString DateDonated = ui->txtDateDonated->text();
    QString BloodType= ui->txtBloodType->text();

    qDebug() <<"Identification:"<<Identification<<"FirstName:"<<FirstName<<"MiddleName:"<<MiddleName<<"LastName:"<<LastName<<"Age:"<<Age<<"DateofBirth:"<<DateofBirth<<"Gender:"<<Gender<<"AreaofResidence:"<<AreaofResidence<<"Occupation:"<<Occupation<<"ContactNumber:"<<ContactNumber<<"EmailAddress:"<<EmailAddress<<"DateDonated:"<<DateDonated<<"BloodType:"<<BloodType;

    QSqlDatabase database;
    database= QSqlDatabase:: addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    if(QFile::exists("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db"))
    {
        qDebug() << "Database file exists";
    }
    else
    {
        qDebug() << "Database file does not exists";
        return;
    }

    if(!database.open())
    {
        qDebug() << "Error: Unable to open Database";
        return;
    }
    else
    {
        qDebug() <<"Database open Successfully!!!";
    }

    QSqlQuery query(database);
    query.prepare("insert into Donor (Identification,FirstName, MiddleName, LastName,Age,DateofBirth,Gender,AreaofResidence,Occupation, ContactNumber, EmailAddress,DateDonated,BloodType) values('"+Identification +" ','"+FirstName +" ','" +MiddleName +"','" +LastName +"','"+Age + "','"+DateofBirth +"','"+Gender+"','"+AreaofResidence +"','"+Occupation +"','"+ContactNumber+"','"+EmailAddress+"','"+DateDonated+"','"+BloodType+"')");
    query.exec();
    qDebug()<<"Last error: "<<query.lastError().text();
    database.close();

}


