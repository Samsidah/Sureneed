#ifndef FILE_H
#define FILE_H
#include "databaseheader.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QsqlQuery>

namespace Ui {
class File;
}

class File : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit File(QWidget *parent = nullptr);
    ~File();

private slots:
    void on_lineEdit_windowIconTextChanged(const QString &iconText);

    void on_btnSearch_clicked();

    void on_btnShare_clicked();

private:
    Ui::File *ui;
};

#endif // FILE_H
