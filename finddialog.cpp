#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QString selectedText, QWidget *parent) :
    QDialog(parent), ui(new Ui::FindDialog), m_text(selectedText) {
    ui->setupUi(this);

    init();
    save();
}

FindDialog::~FindDialog() {
    delete ui;
}

void FindDialog::on_buttonBox_accepted() {
    save();
    accept();
}

void FindDialog::on_buttonBox_rejected() {
    reject();
}

void FindDialog::goBack() {
    save();
    m_backwards = true;
    accept();
}

void FindDialog::init() {
    QPushButton *btnBack = new QPushButton("Back", this);
    connect(btnBack, &QPushButton::clicked, this, &FindDialog::goBack);
    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ActionRole);
    ui->lineEdit->setText(m_text);
}

void FindDialog::save() {
    m_text = ui->lineEdit->text();
    m_caseSensitive = ui->checkSensitive->isChecked();
    m_wholeWords = ui->checkWholeWord->isChecked();
    m_backwards = false;
}

bool FindDialog::caseSensitive() const {
    return m_caseSensitive;
}

bool FindDialog::wholeWords() const {
    return m_wholeWords;
}

bool FindDialog::backwards() const {
    return m_backwards;
}

QString FindDialog::text() const {
    return m_text;
}
