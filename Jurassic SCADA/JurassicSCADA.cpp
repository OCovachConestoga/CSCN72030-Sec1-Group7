#include "JurassicSCADA.h"

JurassicSCADA::JurassicSCADA(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.mainText->hide();
}

JurassicSCADA::~JurassicSCADA()
{}

void JurassicSCADA::on_btnOne_clicked()
{
    ui.mainText->show();
}

void JurassicSCADA::on_btnTwo_clicked()
{
    ui.mainText->hide();
}