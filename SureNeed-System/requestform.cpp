#include "requestform.h"
#include "ui_requestform.h"

RequestForm::RequestForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RequestForm)
{
    ui->setupUi(this);
}

RequestForm::~RequestForm()
{
    delete ui;
}

void RequestForm::on_pushButton_clicked()
{
    QString FirstName = ui ->txtFirstName->text();
    QString  MiddleName= ui ->txtLastName ->text();
    QString LastName = ui ->txtMiddleName ->text();
    QString Gender = ui ->txtGender->text();
    QString Age = ui->txtAge->text();
    QString DateofBirth = ui->txtDateofBirth->text();
    QString Address = ui->txtAddress->text();
    QString ContactNumber = ui ->txtContactNumber ->text();
    QString EmailAddress = ui->txtEmailAddress->text();
    QString Occupation = ui->txtOccupation->text();
    QString BloodTypeNeeded= ui->txtBloodTypeNeeded->text();
    QString DateRequested = ui->txtDateRequested->text();
    QString CID=ui->txtCID->text();

    qDebug() <<"FirstName:"<<FirstName<<"MiddleName:"<<MiddleName<<"LastName:"<<LastName<<"Gender:"<<Gender<<"Age:"<<Age<<"DateofBirth:"<<DateofBirth<<"Address:"<<Address<<"Contact Number:"<<ContactNumber<<"EmailAddress:"<<EmailAddress<<"Occupation:"<<Occupation<<"BloodTypeNeeded:"<<BloodTypeNeeded<<"DateRequested:"<<DateRequested<<"C-ID:"<<CID;

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
    query.prepare("insert into Consumer (FirstName, MiddleName, LastName,Gender, Age,DateofBirth,Address,ContactNumber, EmailAddress, Occupation,BloodTypeNeeded,DateRequested,CID) values('"+FirstName +" ','" +MiddleName +"','" +LastName +"','"+Gender + "','"+Age +"','"+DateofBirth+"','"+Address +"','"+ContactNumber +"','"+EmailAddress+"','"+Occupation+"','"+BloodTypeNeeded+"','"+DateRequested+"','"+CID+"')");
    query.exec();
    qDebug()<<"Last error: "<<query.lastError().text();
    database.close();

}

