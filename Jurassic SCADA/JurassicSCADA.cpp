#include "JurassicSCADA.h"
#include <QObject>
#include "Incubator.h"
#include "monorail.h"


JurassicSCADA::JurassicSCADA(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.cameraScreen->hide();
	ui.popUpWindow->hide();
	ui.IncubatorScreen->hide();
	ui.monorailScreen->hide();

	//********************************* Initialization of camera objects *******************************************
	Camera c1(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1.jpg\"/></p></body></html>");
	Camera c2(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2.jpg\"/></p></body></html>");
	Camera c3(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3.jpg\"/></p></body></html>");
	Camera c4(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4.jpg\"/></p></body></html>");
	Camera c5(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5.jpg\"/></p></body></html>");
	Camera c6(1, false, "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6.png\"/></p></body></html>");
	this->cameraArray = new Camera[6];
	this->cameraArray[0] = c1;
	this->cameraArray[1] = c2;
	this->cameraArray[2] = c3;
	this->cameraArray[3] = c4;
	this->cameraArray[4] = c5;
	this->cameraArray[5] = c6;
	// *************************************************************************************************************


	//********************************* Initialization of File objects *******************************************
	// file pointer for camera text files

	FileManagement CameraSwitch("NightVisionToggle.txt");
	FileManagement NightVisionToggle("NightVisionToggle.txt");

	FileManagement GateClosing("GateClosing.txt");
	FileManagement GateOpening("GateOpening.txt");
	FileManagement FenceActivating("FenceActivating.txt");
	FileManagement FenceDeactivating("FenceDeactivating.txt");
	FileManagement TemperatureChanging("TemperatureChanging.txt");
	FileManagement RefillingFuel("RefillingFuel.txt");
	FileManagement MonorailActivating("MonorailActivating.txt");
	FileManagement MonorailDeactivating("MonorailDeactivating.txt");

	// for testing purposes
	FileManagement test;
	CameraSwitch.setFileName("CameraSwitch.txt");
	std::string expectedFileName = CameraSwitch.getFileName();


	this->FileArray = new FileManagement[10];
	this->FileArray[0] = CameraSwitch;
	this->FileArray[1] = NightVisionToggle;
	this->FileArray[2] = GateClosing;
	this->FileArray[3] = GateOpening;
	this->FileArray[4] = FenceActivating;
	this->FileArray[5] = FenceDeactivating;
	this->FileArray[6] = TemperatureChanging;
	this->FileArray[7] = RefillingFuel;
	this->FileArray[8] = MonorailActivating;
	this->FileArray[9] = MonorailDeactivating;
	// *************************************************************************************************************


	//********************************* Initialization of incubator object ***************************************
	this->incubator = new Incubator(25.0, "TemperatureChanging.txt");
	ui.lblTemp->setText(QString::number(incubator->getTemperature()));
	//************************************************************************************************************

	//********************************* Initialization of monorail-car object(s) ****************************************
	Monorail monorail(true);
	updatelblPowerStatus(monorail.getPowerStatus());
	Car car1(45);
	Car car2(57);
	Car car3(75);
	monorail.addCar(car1);
	monorail.addCar(car2);
	monorail.addCar(car3);
	ui.lblFuelReserve1->setText(QString::number(car1.getFuelReserve()));
	ui.lblFuelReserve2->setText(QString::number(car2.getFuelReserve()));
	ui.lblFuelReserve3->setText(QString::number(car3.getFuelReserve()));
	//********************************************************************************************************************

	//********************************* Timers to help emulate realtime changes in data *********************************
	fuelUpdateTimer = new QTimer(this);
	connect(fuelUpdateTimer, &QTimer::timeout, this, &JurassicSCADA::updateFuelReserves);
	fuelUpdateTimer->start(1500);
	temperatureChangeTimer = new QTimer(this);
	temperatureChangeTimer->setSingleShot(true);
	connect(temperatureChangeTimer, &QTimer::timeout, this, &JurassicSCADA::handleTemperatureChange);
	//*******************************************************************************************************************
}

JurassicSCADA::~JurassicSCADA()
{}

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
void JurassicSCADA::on_camerabtn1_clicked() 
{
	on_camerabtnClicked(this->cameraArray[0], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn2_clicked()
{
	on_camerabtnClicked(this->cameraArray[1], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn3_clicked()
{
	on_camerabtnClicked(this->cameraArray[2], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn4_clicked()
{
	on_camerabtnClicked(this->cameraArray[3], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn5_clicked()
{
	on_camerabtnClicked(this->cameraArray[4], this->FileArray[0]);
}
void JurassicSCADA::on_camerabtn6_clicked()
{
	on_camerabtnClicked(this->cameraArray[5], this->FileArray[0]);
	
}
void JurassicSCADA::on_nightVisionToggle_clicked()
{
	
	on_nightVisionbtnClicked(this->cameraArray, this->FileArray[1]);
}

void JurassicSCADA::on_camerabtnClicked(Camera camera, FileManagement fileptr)
{
	
	fileptr.readFileData(&ui);
	camera.displayCameraFootage(&ui);
}

// *********************** night vision logic to switch the image to a night vision filtered image before displaying ******************************
void JurassicSCADA::on_nightVisionbtnClicked(Camera* camera, FileManagement fileptr)
{
	fileptr.readFileData(&ui);
	if (ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1.jpg\"/></p></body></html>" ||
		ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1 NV.jpg\"/></p></body></html>")
	{
		if (camera[0].getNightVision() == false)
			camera[0].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1 NV.jpg\"/></p></body></html>");
		else
			camera[0].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1.jpg\"/></p></body></html>");

		camera[0].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2.jpg\"/></p></body></html>" ||
		ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2 NV.jpg\"/></p></body></html>")
	{
		if (camera[1].getNightVision() == false)
			camera[1].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2 NV.jpg\"/></p></body></html>");
		else
			camera[1].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2.jpg\"/></p></body></html>");

		camera[1].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3.jpg\"/></p></body></html>" ||
		ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3 NV.jpg\"/></p></body></html>")
	{
		if (camera[2].getNightVision() == false)
			camera[2].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3 NV.jpg\"/></p></body></html>");
		else
			camera[2].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3.jpg\"/></p></body></html>");

		camera[2].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4.jpg\"/></p></body></html>" ||
		ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4 NV.jpg\"/></p></body></html>")
	{
		if (camera[3].getNightVision() == false)
			camera[3].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4 NV.jpg\"/></p></body></html>");
		else
			camera[3].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4.jpg\"/></p></body></html>");

		camera[3].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5.jpg\"/></p></body></html>" ||
		ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5 NV.jpg\"/></p></body></html>")
	{
		if (camera[4].getNightVision() == false)
			camera[4].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5 NV.jpg\"/></p></body></html>");
		else
			camera[4].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5.jpg\"/></p></body></html>");

		camera[4].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6.png\"/></p></body></html>" ||
		ui.cameraLabel->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6 NV.jpg\"/></p></body></html>")
	{	
		if (camera[5].getNightVision() == false)
			camera[5].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6 NV.jpg\"/></p></body></html>");
		else
			camera[5].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6.png\"/></p></body></html>");

		camera[5].displayNightVision(&ui);
	}
	
}
// *********************************************************************************************************************************

//**********************************************  Incubator Button Logic  ******************************************
void JurassicSCADA::on_btnIncrease_clicked()
{
    float currentTemperature = incubator->getTemperature();
    incubator->setTemperature(currentTemperature + 0.1);
	ui.lblTemp->setText(QString::number(incubator->getTemperature()));
	temperatureChangeTimer->start(1000);
}

void JurassicSCADA::on_btnDecrease_clicked()
{
	float currentTemperature = incubator->getTemperature();
    incubator->setTemperature(currentTemperature - 0.1);
	ui.lblTemp->setText(QString::number(incubator->getTemperature()));
	temperatureChangeTimer->start(1000);
}

void JurassicSCADA::updateTemperature(float newTemperature) {
	// Update the UI element displaying the temperature
	ui.lblTemp->setText(QString::number(newTemperature));
	FileArray[6].readFileData(&ui);
}

void JurassicSCADA::on_incubatorbtn_clicked()
{
	ui.mainSCADA->hide();
	ui.IncubatorScreen->show();
}

void JurassicSCADA::on_incubatorBackbtn_clicked()
{
	ui.IncubatorScreen->hide();
	ui.mainSCADA->show();
}

void JurassicSCADA::handleTemperatureChange()
{

	FileArray[6].readFileData(&ui);
}
//******************************************************************************************************************


//*********************************************  Monorail Button Logic  ********************************************
void JurassicSCADA::on_monorailbtn_clicked()
{
	ui.mainSCADA->hide();
	ui.monorailScreen->show();
	
}

void JurassicSCADA::on_monorailBackbtn_clicked()
{
	ui.monorailScreen->hide();
	ui.mainSCADA->show();
}

void JurassicSCADA::updatelblPowerStatus(bool powerStatus)
{
	if (powerStatus == true)
	{
		ui.lblPowerStatus->setText("<html><head/><body><p><img src=\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.lblPowerText->setText("Monorail Power: ON");
	}
	else
	{
		ui.lblPowerStatus->setText("<html><head/><body><p><img src=\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.lblPowerText->setText("Monorail Power: OFF");
	}
}

void JurassicSCADA::on_monorailPowerbtn_clicked()
{
	if (ui.lblPowerStatus->text() == "<html><head/><body><p><img src=\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>")
	{
		FileArray[9].readFileData(&ui);
		ui.lblPowerStatus->setText("<html><head/><body><p><img src=\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.lblPowerText->setText("Monorail Power: OFF");
	}
	else
	{
		FileArray[8].readFileData(&ui);
		ui.lblPowerStatus->setText("<html><head/><body><p><img src=\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.lblPowerText->setText("Monorail Power: ON");
	}
}

void JurassicSCADA::on_refuel1btn_clicked() 
{
	FileArray[7].readFileData(&ui);
	ui.lblFuelReserve1->setText(QString::number(100));
}

void JurassicSCADA::on_refuel2btn_clicked()
{
	FileArray[7].readFileData(&ui);
	ui.lblFuelReserve2->setText(QString::number(100));
}

void JurassicSCADA::on_refuel3btn_clicked()
{
	FileArray[7].readFileData(&ui);
	ui.lblFuelReserve3->setText(QString::number(100));
}

void JurassicSCADA::updateFuelReserves() {
	float currentFuelReserve1 = ui.lblFuelReserve1->text().toFloat();
	float currentFuelReserve2 = ui.lblFuelReserve2->text().toFloat();
	float currentFuelReserve3 = ui.lblFuelReserve3->text().toFloat();

	currentFuelReserve1 -= 0.01;
	currentFuelReserve2 -= 0.01;
	currentFuelReserve3 -= 0.01;

	ui.lblFuelReserve1->setText(QString::number(currentFuelReserve1));
	ui.lblFuelReserve2->setText(QString::number(currentFuelReserve2));
	ui.lblFuelReserve3->setText(QString::number(currentFuelReserve3));

	if (currentFuelReserve1 <= 0.01 || currentFuelReserve2 <= 0.01 || currentFuelReserve3 <= 0.01) {

	}
}

//******************************************************************************************************************