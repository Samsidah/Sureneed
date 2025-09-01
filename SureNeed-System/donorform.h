#ifndef DONORFORM_H
#define DONORFORM_H
#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class DonorForm;
}

class DonorForm : public QDialog
{
    Q_OBJECT

public:
    explicit DonorForm(QWidget *parent = nullptr);
    ~DonorForm();

private slots:

    void on_btnSubmit_clicked();


private:
    Ui::DonorForm *ui;
};

#endif // DONORFORM_H
