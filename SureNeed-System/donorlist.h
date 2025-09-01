#ifndef DONORLIST_H
#define DONORLIST_H
#include <QDialog>
#include "donorform.h"
#include "databaseheader.h"
#include "donors.h"

namespace Ui {
class DonorList;
}

class DonorList : public QDialog
{
    Q_OBJECT

public:
    explicit DonorList(QWidget *parent = nullptr);
    ~DonorList();

private slots:

    void on_btnShow_clicked();

    void on_btnUpdate_clicked();

    void on_btnDelete_clicked();

    void on_btnSearch_clicked();

    void on_txtIdentification_windowIconTextChanged(const QString &iconText);

private:
    Ui::DonorList *ui;
    DonorForm*donorform;
    Donors*donors;
    QSqlQueryModel*model;

};

#endif // DONORLIST_H
