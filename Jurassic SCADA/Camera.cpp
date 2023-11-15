#include "Camera.h"

// Constructors
Camera::Camera(QWidget* parent)
{
	this->cameraID = new int;
	this->nightVision = new bool;
	this->footage = new QString;
	*this->cameraID = 0;
	*this->nightVision = false;
	*this->footage = "No footage";
}
Camera::Camera(int ID, bool nightVision, QString footage)
{
	this->cameraID = new int;
	this->nightVision = new bool;
	this->footage = new QString;
	*this->cameraID = ID;
	*this->nightVision = nightVision;
	*this->footage = footage;
}

// Getters and Setters
void Camera::setCameraID(int ID)
{
	*this->cameraID = ID;
}
int Camera::getCameraID()
{
	return *this->cameraID;
}
void Camera::setNightVision(bool nightVision)
{
	*this->nightVision = nightVision;
}

bool Camera::getNightVision()
{
	return *this->nightVision;
}

void Camera::setFootage(QString footage)
{
	*this->footage = footage;
}

QString Camera::getFootage()
{
	return *this->footage;
}

// Destructor
Camera::~Camera()
{}

// button event handlers using the main SCADA class function definitions
void Camera::displayCameraFootage(Ui::JurassicSCADA* ui)
{
	ui->cameraLabel->setText(this->getFootage());
}

void Camera::displayNightVision(Ui::JurassicSCADA* ui)
{
	if(this->getNightVision() == true)
		ui->nightVisionLabel->setText("ON");
	else
		ui->nightVisionLabel->setText("OFF");
}