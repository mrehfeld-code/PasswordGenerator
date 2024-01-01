#include "passwordgenerator.h"
#include "./ui_passwordgenerator.h"

PasswordGenerator::PasswordGenerator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PasswordGenerator)
{
    ui->setupUi(this);
}

PasswordGenerator::~PasswordGenerator()
{
    delete ui;
}

void PasswordGenerator::on_action_btn_clicked()
{
    QString allowedCharacters;
    if(ui->cb_alphabetical->isChecked()) {
        allowedCharacters.append("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    }
    if(ui->cb_numerical->isChecked()) {
        allowedCharacters.append("0123456789");
    }
    if(ui->cb_mathematical->isChecked()) {
        allowedCharacters.append("+-*/\\%{[(<>)]}=");
    }
    if(ui->cb_punctuation->isChecked()) {
        allowedCharacters.append("¡!¿?\"§$&'`´_:;.,");
    }
    if(ui->cb_special->isChecked()) {
        allowedCharacters.append("ÄÖÜäöüÁÀĆÉÈǴÍÌḾŃÓÒṔŔŚÚÙẂẀÝỲŹáàéèǵíìḿńóòṕŕśúùẃẁýỳź");
    }

    if(allowedCharacters.isEmpty()) {
        ui->output_label->setStyleSheet(ui->output_label->styleSheet().append("color: red;"));
        ui->output_label->setText("No characters were selected!");
        return;
    }

    ui->output_label->setStyleSheet(ui->output_label->styleSheet().remove("color: red;"));

    QString password;
    int length = ui->length->value();
    for(int i = 0; i < length; i++) {
        QChar c = allowedCharacters.at(rand() % allowedCharacters.length());
        while(password.contains(c))
            c = allowedCharacters.at(rand() % allowedCharacters.length());
        password.append(c);
    }

    ui->output_label->setText("Your password is: " + password);
}

