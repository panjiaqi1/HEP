#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class ParameterDialog;
}

class ParameterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParameterDialog(QWidget *parent = nullptr);
    ~ParameterDialog();

private:
    Ui::ParameterDialog *ui;
};

#endif // DIALOG_H
