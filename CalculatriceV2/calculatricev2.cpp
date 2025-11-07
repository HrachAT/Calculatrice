#include "calculatricev2.h"
#include "ui_calculatricev2.h"
#include <QJSEngine>

CalculatriceV2::CalculatriceV2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatriceV2)
{
    ui->setupUi(this);

    // connect(ui->pushButton0, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton1, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton2, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton3, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton4, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton5, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton6, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton7, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton8, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButton9, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButtonAdditionner, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButtonSoustration, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButtonMultiplier, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    // connect(ui->pushButtonDiviser, &QPushButton::clicked,this,&CalculatriceV2::onQPushButtonClicked);
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, allButtons) {
        if(button->text() != "=" && button->text() != "C") {
            connect(button, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
        }
    }
}

CalculatriceV2::~CalculatriceV2()
{
    delete ui;
}

void CalculatriceV2::onQPushButtonClicked()
{
    QPushButton *touche;
    touche = qobject_cast<QPushButton*>(sender());
    QString valTouche = touche->text();
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+valTouche);


}

void CalculatriceV2::on_pushButtonEffacer_clicked()
{
    ui->lineEditAfficheur->clear();
}


void CalculatriceV2::on_pushButtonEgal_clicked()
{
    QJSEngine expression;
    ui->lineEditAfficheur->setText(expression.evaluate(ui->lineEditAfficheur->text()).toString());
}

