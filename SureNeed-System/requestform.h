#ifndef REQUESTFORM_H
#define REQUESTFORM_H
#include <QDialog>
#include "databaseheader.h"
namespace Ui {
class RequestForm;
}

class RequestForm : public QDialog
{
    Q_OBJECT

public:
    explicit RequestForm(QWidget *parent = nullptr);
    ~RequestForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RequestForm *ui;
};

#endif // REQUESTFORM_H
