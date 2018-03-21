#ifndef BUFFER_H
#define BUFFER_H

#include <QDialog>

namespace Ui {
class buffer;
}

class buffer : public QDialog
{
    Q_OBJECT

public:
    explicit buffer(QWidget *parent = 0);
    ~buffer();

private slots:
    void on_buttonBox_rejected();

private:
    Ui::buffer *ui;
};

#endif // BUFFER_H
