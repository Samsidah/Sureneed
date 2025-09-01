#include "file.h"
#include "ui_file.h"
#include "QMessageBox"

File::File(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);
}

File::~File()
{
    delete ui;
}


void File::on_lineEdit_windowIconTextChanged(const QString &iconText)
{
    QString CID = ui->lineEdit->text();
    qDebug() << "CID:" << CID;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/clint/Desktop/SYSTEM/Database/SureneedBMS.db");

    if (!database.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open the database"));
        return; }

    QSqlQuery query;
    query.prepare("SELECT FROM Consumer WHERE CID '"+CID+"'");

    if(query.exec()) {
        while (query.next())
        {
            ui->txtCID->setText(query.value(0).toString());
            ui->txtFirstName->setText(query.value(1).toString());
            ui->txtMiddleName->setText(query.value(2).toString());
            ui->txtLastName->setText(query.value(3).toString());
            ui->txtGender->setText(query.value(6).toString());
            ui->txtAge->setText(query.value(4).toString());
            ui->txtDateofBirth->setText(query.value(5).toString());
            ui->txtAddress->setText(query.value(7).toString());
            ui->txtContactNumber->setText(query.value(9).toString());
            ui->txtEmailAddress->setText(query.value(10).toString());
            ui->txtOccupation->setText(query.value(8).toString());
            ui->txtBloodTypeNeeded->setText(query.value(11).toString());
            ui->txtDateRequested->setText(query.value(12).toString());
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
    database.close();
}

void File::on_btnShare_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

