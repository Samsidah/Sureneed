#ifndef DONORS_H
#define DONORS_H
#include <QSqlDatabase>
#include <QDialog>

namespace Ui {
class Donors;
}

class Donors : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit Donors(QWidget *parent = nullptr);
    ~Donors();

private slots:


    void on_btnShow_clicked();

private:
    Ui::Donors *ui;
};

#endif // DONORS_H
