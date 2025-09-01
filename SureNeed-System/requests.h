#ifndef REQUESTS_H
#define REQUESTS_H
#include <QDialog>
#include "databaseheader.h"
#include "requestform.h"
#include "archive.h"
namespace Ui {
class Requests;
}

class Requests : public QDialog
{
    Q_OBJECT

public:
    explicit Requests(QWidget *parent = nullptr);
    ~Requests();

private slots:

    void on_btnShow_clicked();

    void on_btnUpdate_clicked();

    void on_btnDelete_clicked();

    void on_btnSearch_clicked();

private:
    Ui::Requests *ui;
    RequestForm*requestform;
    Archive*archive;
    QSqlQueryModel*model;
};

#endif // REQUESTS_H
