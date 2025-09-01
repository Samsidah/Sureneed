#ifndef DONORINFO_H
#define DONORINFO_H

#include <QDialog>

namespace Ui {
class DonorInfo;
}

class DonorInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DonorInfo(QWidget *parent = nullptr);
    ~DonorInfo();

private:
    Ui::DonorInfo *ui;
};

#endif // DONORINFO_H
