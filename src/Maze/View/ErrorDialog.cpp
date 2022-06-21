#include "ErrorDialog.h"
#include "ui_ErrorDialog.h"

ErrorDialog::ErrorDialog(std::exception& error, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog) {
    ui->setupUi(this);
    ui->errorLabel->setText(error.what());
}

ErrorDialog::~ErrorDialog() {
    delete ui;
}
