#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QString replaceText, QWidget *parent) :
    QDialog(parent), ui(new Ui::ReplaceDialog), m_text(replaceText) {
    ui->setupUi(this);

    init();
    save();
}

ReplaceDialog::~ReplaceDialog() {
    delete ui;
}

void ReplaceDialog::on_buttonBox_rejected() {
    reject();
}

void ReplaceDialog::replace() {
    save();
    accept();
}

void ReplaceDialog::replaceAll() {
    save();
    m_all = true;
    accept();
}

void ReplaceDialog::init() {
    QPushButton* btnReplace = new QPushButton("Replace", this);
    QPushButton* btnReplaceAll = new QPushButton("Replace all", this);

    ui->txtFind->setText(m_text);
    ui->buttonBox->addButton(btnReplace, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnReplaceAll, QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnReplaceAll, &QPushButton::clicked, this, &ReplaceDialog::replaceAll);
    connect(btnReplace, &QPushButton::clicked, this, &ReplaceDialog::replace);
}

void ReplaceDialog::save() {
    m_text = ui->txtFind->text();
    m_replaceText = ui->txtReplace->text();
    m_all = false;
}

QString ReplaceDialog::replaceText() const {
    return m_replaceText;
}

QString ReplaceDialog::text() const {
    return m_text;
}

bool ReplaceDialog::all() const {
    return m_all;
}
