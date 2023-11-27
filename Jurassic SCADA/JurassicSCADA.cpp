#include "JurassicSCADA.h"

JurassicSCADA::JurassicSCADA(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.cameraScreen->hide();
	ui.gateScreen->hide();
	ui.popUpWindow->hide();


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

	//********************************* Initialization of Gate objects *******************************************
	Gate g1(1, true);
	Gate g2(1, true);
	Gate g3(1, true);
	Gate g4(1, true);
	Gate g5(1, true);
	Gate g6(1, true);
	Gate g7(1, true);
	Gate g8(1, true);
	this->gateArray = new Gate[8];
	this->gateArray[0] = g1;
	this->gateArray[1] = g2;
	this->gateArray[2] = g3;
	this->gateArray[3] = g4;
	this->gateArray[4] = g5;
	this->gateArray[5] = g6;
	this->gateArray[6] = g7;
	this->gateArray[7] = g8;
	this->gateArray[0] = g1;
	// *************************************************************************************************************

	//********************************* Initialization of File objects *******************************************
	// file pointer for camera text files
	FileManagement CameraSwitch("CameraSwitch.txt");
	FileManagement NightVisionToggle("NightVisionToggle.txt");
	this->FileArray = new FileManagement[10];
	this->FileArray[0] = CameraSwitch;
	this->FileArray[1] = NightVisionToggle;
	// *************************************************************************************************************

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

// *************** Main menu gate module buttons*****************
void JurassicSCADA::on_gatesbtn_clicked()
{
	ui.mainSCADA->hide();
	ui.gateScreen->show();
}

void JurassicSCADA::on_gatebackbtn_clicked()
{
	ui.gateScreen->hide();
	ui.mainSCADA->show();
}
//*****************************************************************

// ********** Gate button handlers ****************
void JurassicSCADA::on_gate1btn_clicked()
{
	//Switch the gate status
	gateArray[0].setGateStatus(!(gateArray[0].getGateStatus()));
	
	//Update the UI accordingly
	if (gateArray[0].getGateStatus() == true)
	{
		ui.Gate1Data->setText("Gate 1 Closed");
		ui.Gate1LED->setText("<html><head/><body><p>< img src=\":/JurassicSCADA/LEDgreen.jpg\"/></p></body></html>");
	}
	else
	{
		ui.Gate1Data->setText("Gate 1 Open");
		ui.Gate1LED->setText("<html><head/><body><p>< img src=\":/JurassicSCADA/LEDred.jpg\"/></p></body></html>");
	}
}
void JurassicSCADA::on_gate2btn_clicked()
{
	gateArray[1].setGateStatus(!(gateArray[1].getGateStatus()));
	if (gateArray[1].getGateStatus() == true)
		ui.Gate2Data->setText("Gate 2 Closed");
	else
		ui.Gate2Data->setText("Gate 2 Open");
}
void JurassicSCADA::on_gate3btn_clicked()
{
	//Switch the gate status
	gateArray[2].setGateStatus(!(gateArray[2].getGateStatus()));

	//Update the UI accordingly
	if (gateArray[2].getGateStatus() == true)
		ui.Gate3Data->setText("Gate 3 Closed");
	else
		ui.Gate3Data->setText("Gate 3 Open");
}
void JurassicSCADA::on_gate4btn_clicked()
{
	//Switch the gate status
	gateArray[3].setGateStatus(!(gateArray[3].getGateStatus()));

	//Update the UI accordingly
	if (gateArray[3].getGateStatus() == true)
		ui.Gate4Data->setText("Gate 4 Closed");
	else
		ui.Gate4Data->setText("Gate 4 Open");
}
void JurassicSCADA::on_gate5btn_clicked()
{
	//Switch the gate status
	gateArray[4].setGateStatus(!(gateArray[4].getGateStatus()));

	//Update the UI accordingly
	if (gateArray[4].getGateStatus() == true)
		ui.Gate5Data->setText("Gate 5 Closed");
	else
		ui.Gate5Data->setText("Gate 5 Open");
}
void JurassicSCADA::on_gate6btn_clicked()
{
	//Switch the gate status
	gateArray[5].setGateStatus(!(gateArray[5].getGateStatus()));

	//Update the UI accordingly
	if (gateArray[5].getGateStatus() == true)
		ui.Gate6Data->setText("Gate 6 Closed");
	else
		ui.Gate6Data->setText("Gate 6 Open");
}
void JurassicSCADA::on_gate7btn_clicked()
{
	//Switch the gate status
	gateArray[6].setGateStatus(!(gateArray[6].getGateStatus()));

	//Update the UI accordingly
	if (gateArray[6].getGateStatus() == true)
		ui.Gate7Data->setText("Gate 7 Closed");
	else
		ui.Gate7Data->setText("Gate 7 Open");
}
void JurassicSCADA::on_gate8btn_clicked()
{
	//Switch the gate status
	gateArray[7].setGateStatus(!(gateArray[7].getGateStatus()));

	//Update the UI accordingly
	if (gateArray[7].getGateStatus() == true)
		ui.Gate8Data->setText("Gate 8 Closed");
	else
		ui.Gate8Data->setText("Gate 8 Open");
}

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



