#pragma once

#include "ui_JurassicSCADA.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <stdbool.h>
#include "Camera.h"
#include "Gate.h"
#include "ElectricFence.h"
#include "FileManagement.h"

#define MAXCAMERAS	6

class JurassicSCADA : public QMainWindow
{
	Q_OBJECT

public:
    JurassicSCADA(QWidget *parent = nullptr);
    ~JurassicSCADA();

private:
    Ui::JurassicSCADA ui;
	Camera* cameraArray;
	Gate* gateArray;
	ElectricFence* fenceArray;
	FileManagement* FileArray;

public slots:
	
	// ********* Camera Button handlers *********
	void on_camerabtn_clicked();
	void on_cameraBackbtn_clicked();
	void on_camerabtn1_clicked();
	void on_camerabtn2_clicked();
	void on_camerabtn3_clicked();
	void on_camerabtn4_clicked();
	void on_camerabtn5_clicked();
	void on_camerabtn6_clicked();
	void on_camerabtnClicked(Camera, FileManagement);
	void on_nightVisionToggle_clicked();
	void on_nightVisionbtnClicked(Camera*, FileManagement);
	// ******************************************

	// ********* Gate Button handlers *********
	void on_gatesbtn_clicked();
	void on_gatebackbtn_clicked();
	void on_gate1btn_clicked();
	void on_gate2btn_clicked();
	void on_gate3btn_clicked();
	void on_gate4btn_clicked();
	void on_gate5btn_clicked();
	void on_gate6btn_clicked();
	void on_gate7btn_clicked();
	void on_gate8btn_clicked();
	void changeGateCountDisplay(Gate[], int);
	// ******************************************

		// ********* Fence Button handlers *********
	void on_fencebtn_clicked();
	void on_fencebackbtn_clicked();
	void on_fence1btn_clicked();
	void on_fence2btn_clicked();
	void on_fence3btn_clicked();
	void on_fence4btn_clicked();
	void on_fence5btn_clicked();
	void on_fence6btn_clicked();
	void on_fence7btn_clicked();
	void on_fence8btn_clicked();
	//void changeFenceCountDisplay(Gate[], int);
	// ******************************************
};
