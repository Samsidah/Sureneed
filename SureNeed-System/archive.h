#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <QDialog>
#include "databaseheader.h"
#include <QSqlDatabase>
#include <QsqlQuery>

namespace Ui {
class Archive;
}

class Archive : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit Archive(QWidget *parent = nullptr);
    ~Archive();

private slots:

   void on_btnShowA_clicked();


private:
    Ui::Archive *ui;
    QSqlQueryModel*model;

};

#endif // ARCHIVE_H
