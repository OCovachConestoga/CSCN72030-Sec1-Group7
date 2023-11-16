#pragma once

#include "ui_JurassicSCADA.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <stdbool.h>
#include "Camera.h"

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

public slots:
    void on_btnOne_clicked();
    void on_btnTwo_clicked();
	
	// ********* Camera Button handlers *********
	void on_camerabtn_clicked();
	void on_cameraBackbtn_clicked();
	void on_camerabtn1_clicked();
	void on_camerabtn2_clicked();
	void on_camerabtn3_clicked();
	void on_camerabtn4_clicked();
	void on_camerabtn5_clicked();
	void on_camerabtn6_clicked();
	void on_camerabtnClicked(Camera);
	void on_nightVisionToggle_clicked();
	void on_nightVisionbtnClicked(Camera*);
	// ******************************************

};
