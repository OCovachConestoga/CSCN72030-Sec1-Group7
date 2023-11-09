#include "Camera.h"

// Constructors
Camera::Camera()
{
	this->cameraID = 0;
	this->nightVision = false;
}
Camera::Camera(int ID, bool nightVision)
{
	this->cameraID = ID;
	this->nightVision = nightVision;
}

// Getters and Setters
void Camera::setCameraID(int ID)
{
	this->cameraID = ID;
}
int Camera::getCameraID()
{
	return this->cameraID;
}
void Camera::setNightVision(bool nightVision)
{
	this->nightVision = nightVision;
}

bool Camera::getNightVision()
{
	return this->nightVision;
}
// void Camera::setX(int);
// int Camera::getX();
// void Camera::setY(int);
// int Camera::getY();

// Destructor
Camera::~Camera()
{
	delete this;
}

// button event handlers using the main SCADA class function definitions
void JurassicSCADA::on_camerabtn1_clicked()
{
	ui.cameraLabel->setText("Camera 1 Footage");
}
void JurassicSCADA::on_camerabtn2_clicked()
{
	ui.cameraLabel->setText("Camera 2 Footage");
}
void JurassicSCADA::on_camerabtn3_clicked()
{
	ui.cameraLabel->setText("Camera 3 Footage");
}
void JurassicSCADA::on_camerabtn4_clicked()
{
	ui.cameraLabel->setText("Camera 4 Footage");
}
void JurassicSCADA::on_camerabtn5_clicked()
{
	ui.cameraLabel->setText("Camera 5 Footage");
}
void JurassicSCADA::on_camerabtn6_clicked()
{
	ui.cameraLabel->setText("Camera 6 Footage");
}
void JurassicSCADA::on_nightVisionON_clicked()
{
	ui.nigthVisionLabel->setText("Night Vision: ON");
}
void JurassicSCADA::on_nightVisionOFF_clicked()
{
	ui.nigthVisionLabel->setText("Night Vision: OFF");
}
void JurassicSCADA::on_cameraBackbtn_clicked()
{
	ui.cameraScreen->hide();
	ui.mainSCADA->show();
}