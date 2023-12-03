#pragma once

#include "ui_JurassicSCADA.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QObject>
#include <stdbool.h>
#include "Camera.h"
#include "FileManagement.h"
#include "Incubator.h"
#include "Car.h"
#include "Monorail.h"
#include <Qtimer.h>

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
	FileManagement* FileArray;
	Incubator* incubator;
	Monorail* monorail;
	Car* car;
	QTimer* fuelUpdateTimer;
	QTimer* temperatureChangeTimer;


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

	// ********* Incubator Button Handlers ******
	void on_incubatorbtn_clicked();
	void on_incubatorBackbtn_clicked();
	void on_btnIncrease_clicked();
	void on_btnDecrease_clicked();
	void updateTemperature(float newTemperature);
	void handleTemperatureChange();
	// ******************************************

	// ********* Monorail Button Handlers *******
	void on_monorailbtn_clicked();
	void on_monorailBackbtn_clicked();
	void updatelblPowerStatus(bool);
	void on_monorailPowerbtn_clicked();
	void on_refuel1btn_clicked();
	void on_refuel2btn_clicked();
	void on_refuel3btn_clicked();
	void updateFuelReserves();
	// ******************************************

};
