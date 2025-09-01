#ifndef DELETECONSUMER_H
#define DELETECONSUMER_H
#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class DeleteConsumer;
}

class DeleteConsumer : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteConsumer(QWidget *parent = nullptr);
    ~DeleteConsumer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteConsumer *ui;
};

#endif // DELETECONSUMER_H
