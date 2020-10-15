#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::SettingsDialog) {
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog() {
    delete ui;
}

QString SettingsDialog::color() const {
    return m_color;
}

void SettingsDialog::on_pushButton_11_clicked() {
    m_color = "#1abc9c";
}

void SettingsDialog::on_pushButton_19_clicked() {
    m_color = "#2ecc71";
}

void SettingsDialog::on_pushButton_18_clicked() {
    m_color = "#3498db";
}

void SettingsDialog::on_pushButton_17_clicked() {
    m_color = "#9b59b6";
}

void SettingsDialog::on_pushButton_10_clicked() {
    m_color = "#34495e";
}

void SettingsDialog::on_pushButton_9_clicked() {
    m_color = "#f1c40f";
}

void SettingsDialog::on_pushButton_8_clicked() {
    m_color = "#e67e22";
}

void SettingsDialog::on_pushButton_7_clicked() {
    m_color = "#e74c3c";
}

void SettingsDialog::on_buttonBox_accepted() {
    accept();
}

void SettingsDialog::on_buttonBox_rejected() {
    reject();
}
