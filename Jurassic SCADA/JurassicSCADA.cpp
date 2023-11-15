#include "JurassicSCADA.h"


JurassicSCADA::JurassicSCADA(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.mainText->hide();
    ui.cameraScreen->hide();

	//					************* Initialization of camera objects ******************
	Camera c1(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1.jpg\"/></p></body></html>");
	Camera c2(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2.jpg\"/></p></body></html>");
	Camera c3(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3.jpg\"/></p></body></html>");
	Camera c4(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4.jpg\"/></p></body></html>");
	Camera c5(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5.jpg\"/></p></body></html>");
	Camera c6(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6.jpg\"/></p></body></html>");
	this->cameraArray[0] = c1;
	this->cameraArray[1] = c2;
	this->cameraArray[2] = c3;
	this->cameraArray[3] = c4;
	this->cameraArray[4] = c5;
	this->cameraArray[5] = c6;
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

// *************** Main menu camera module buttons*****************
void JurassicSCADA::on_camerabtn_clicked()
{
    ui.mainSCADA->hide();
    ui.cameraScreen->show();
}

void JurassicSCADA::on_cameraBackbtn_clicked()
{
	ui.cameraScreen->hide();
	ui.mainSCADA->show();
}
//*****************************************************************

// ********* Camera button handlers ***************
void JurassicSCADA::on_camerabtn1_clicked() {
	
	on_camerabtnClicked(this->cameraArray[0]);
}
void JurassicSCADA::on_camerabtn2_clicked()
{
	on_camerabtnClicked(this->cameraArray[1]);
}
void JurassicSCADA::on_camerabtn3_clicked()
{
	on_camerabtnClicked(this->cameraArray[2]);
}
void JurassicSCADA::on_camerabtn4_clicked()
{
	on_camerabtnClicked(this->cameraArray[3]);
}
void JurassicSCADA::on_camerabtn5_clicked()
{
	on_camerabtnClicked(this->cameraArray[4]);
}
void JurassicSCADA::on_camerabtn6_clicked()
{
	on_camerabtnClicked(this->cameraArray[5]);
}

void JurassicSCADA::on_camerabtnClicked(Camera camera)
{
	camera.displayCameraFootage(&ui);
}

void JurassicSCADA::on_nightVisionON_clicked()
{
	//on_nightVisionbtnClicked();
}
void JurassicSCADA::on_nightVisionOFF_clicked()
{
	ui.nightVisionLabel->setText("Night Vision: OFF");
}

void JurassicSCADA::on_nightVisionbtnClicked(Camera camera)
{
	camera.displayNightVision(&ui);
}
// **********************************************************



