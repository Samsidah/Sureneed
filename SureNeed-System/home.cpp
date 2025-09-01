#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    donorlist = new DonorList();
    requests = new Requests ();
    archive=new Archive();
    donors=new Donors;
    file= new File ();

   ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

}
Home::~Home()
{
    delete ui;
    delete donorlist;
}

void Home::on_btnDonorList_clicked()
{
    donorlist->show();
}

void Home::on_btnArchive_clicked()
{
    archive->show();
}


void Home::on_btnRequest_clicked()
{
    requests->show();
}


void Home::on_btnArchive_2_clicked()
{
    donors->show();
}

