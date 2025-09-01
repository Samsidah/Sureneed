#include "donorinfo.h"
#include "ui_donorinfo.h"

DonorInfo::DonorInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DonorInfo)
{
    ui->setupUi(this);
}

DonorInfo::~DonorInfo()
{
    delete ui;
}
