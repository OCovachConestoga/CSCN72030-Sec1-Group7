#pragma once

#include "ui_JurassicSCADA.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <stdbool.h>
#include "Camera.h"
#include "Gate.h"
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
	// ******************************************
};
