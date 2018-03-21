#include "buffer.h"
#include "ui_buffer.h"

buffer::buffer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buffer)
{
    ui->setupUi(this);
}

buffer::~buffer()
{
    delete ui;
}

void buffer::on_buttonBox_rejected()
{
    this->close();
}
