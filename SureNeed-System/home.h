#ifndef HOME_H
#define HOME_H
#include <QDialog>
#include "donorlist.h"
#include "requests.h"
#include "file.h"
#include "archive.h"
#include "donors.h"
namespace Ui {
class Home;
}

class Home : public QDialog
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_btnDonorList_clicked();

    void on_btnRequest_clicked();

    void on_btnArchive_clicked();

    void on_btnArchive_2_clicked();

private:
    Ui::Home *ui;
    DonorList*donorlist;
    Requests*requests;
    Archive*archive;
    Donors*donors;
    File*file;
};

#endif // HOME_H
