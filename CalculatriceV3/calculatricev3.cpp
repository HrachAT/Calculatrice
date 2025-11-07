#include "calculatricev3.h"
#include "ui_calculatricev3.h"
#include <QJSEngine>

CalculatriceV3::CalculatriceV3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatriceV3)
    , NB_TOUCHES(16)
{
    ui->setupUi(this);
    const QString tableDesSymboles[ ] = {"7", "8", "9", "+" ,"4", "5", "6", "-", "1", "2", "3", "*",
                                         "C", "0", "=", "/"};
    grille = new QGridLayout;
    afficheur = new QLineEdit;
    afficheur->setMinimumHeight(50);
    afficheur->setStyleSheet("background-color: rgb(143, 240, 164);"
                             "color: rgb(0, 0, 0);");
    touches = new QPushButton*[NB_TOUCHES];
    grille->addWidget(afficheur,0,0,1,4);

    int indice = 0;

    for (int ligne = 1; ligne < 5; ligne ++)
    {
        for (int colonne = 0; colonne < 4; colonne ++)
        {
            touches[indice] = new QPushButton;
            touches[indice]->setText(tableDesSymboles[indice]);
            touches[indice]->setStyleSheet("background-color: rgb(128, 128, 128); "
                                           "color: rgb(0, 0, 0); font: bold;");
            touches[indice]->setMinimumSize(50, 50);
            grille->addWidget(touches[indice], ligne, colonne);
            QObject::connect(touches[indice], &QPushButton::clicked, this,
                             &CalculatriceV3::onQPushButtonClicked);
            indice++;
        }
    }

    this->setLayout(grille);
}

CalculatriceV3::~CalculatriceV3()
{
    delete ui;
}

void CalculatriceV3::onQPushButtonClicked()
{
    QPushButton *touche;
    touche = qobject_cast<QPushButton*>(sender());

    QString valTouche = touche->text();

    if (valTouche == "=")
    {
        QJSEngine expression;
        afficheur->setText(expression.evaluate(afficheur->text()).toString());
    }
    else
    {
        afficheur->setText(afficheur->text()+valTouche);
    }

    if (valTouche == "C")
    {
        afficheur->clear();
    }
}

