#include "JurassicSCADA.h"

JurassicSCADA::JurassicSCADA(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.mainText->hide();
    ui.cameraScreen->hide();
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

void JurassicSCADA::on_camerabtn_clicked()
{
    ui.mainSCADA->hide();
    ui.cameraScreen->show();
}