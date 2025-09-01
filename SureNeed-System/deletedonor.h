#ifndef DELETEDONOR_H
#define DELETEDONOR_H
#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class deletedonor;
}

class deletedonor : public QDialog
{
    Q_OBJECT

public:
    explicit deletedonor(QWidget *parent = nullptr);
    ~deletedonor();

private slots:
    void on_btnDel_clicked();

private:
    Ui::deletedonor *ui;
};

#endif // DELETEDONOR_H
