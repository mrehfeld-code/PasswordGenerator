#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class PasswordGenerator;
}
QT_END_NAMESPACE

class PasswordGenerator : public QMainWindow
{
    Q_OBJECT

public:
    PasswordGenerator(QWidget *parent = nullptr);
    ~PasswordGenerator();

private slots:
    void on_action_btn_clicked();

private:
    Ui::PasswordGenerator *ui;
};
#endif // PASSWORDGENERATOR_H
