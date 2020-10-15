#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

    QString color() const;

private slots:
    void on_pushButton_11_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::SettingsDialog *ui;

    QString m_color = "";
};

#endif // SETTINGSDIALOG_H
