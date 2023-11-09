#pragma once

#include "JurassicSCADA.h"

class Camera : public JurassicSCADA
{
	int cameraID;
	bool nightVision;
	// int x;
	// int y;

private:

	// Constructors
	Camera();
	Camera(int, bool);

	// Getters and Setters
	void setCameraID(int);
	int getCameraID();
	void setNightVision(bool);
	bool getNightVision();
	// void setX(int);
	// int getX();
	// void setY(int);
	// int getY();

	// Destructor
	~Camera();

	// Camera functions
	// void panUp(int);
	// void panDown(int);
	// void panLeft(int);
	// void panRight(int);
};