#include "JurassicSCADA.h"
#include <QMessageBox> //Just for testing. Remove this line later, as well as the Qmessagebox call in gate1btn

JurassicSCADA::JurassicSCADA(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.cameraScreen->hide();
	ui.gateScreen->hide();
	ui.fenceScreen->hide();
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
	Gate g2(2, true);
	Gate g3(3, true);
	Gate g4(4, true);
	Gate g5(5, true);
	Gate g6(6, true);
	Gate g7(7, true);
	Gate g8(8, true);
	this->gateArray = new Gate[NUMBER_OF_GATES];
	this->gateArray[0] = g1;
	this->gateArray[1] = g2;
	this->gateArray[2] = g3;
	this->gateArray[3] = g4;
	this->gateArray[4] = g5;
	this->gateArray[5] = g6;
	this->gateArray[6] = g7;
	this->gateArray[7] = g8;
	// *************************************************************************************************************

	//********************************* Initialization of Fence objects *******************************************
	ElectricFence f1(1, true, 500.0);
	ElectricFence f2(2, true, 500.0);
	ElectricFence f3(3, true, 500.0);
	ElectricFence f4(4, true, 500.0);
	ElectricFence f5(5, true, 500.0);
	ElectricFence f6(6, true, 500.0);
	ElectricFence f7(7, true, 500.0);
	ElectricFence f8(8, true, 500.0);
	this->fenceArray = new ElectricFence[NUMBER_OF_GATES];
	this->fenceArray[0] = f1;
	this->fenceArray[1] = f2;
	this->fenceArray[2] = f3;
	this->fenceArray[3] = f4;
	this->fenceArray[4] = f5;
	this->fenceArray[5] = f6;
	this->fenceArray[6] = f7;
	this->fenceArray[7] = f8;
	ui.Fence1Data2->setText(QString("Voltage: %1V").arg(fenceArray[0].getElectricFenceVoltage()));
	ui.Fence2Data2->setText(QString("Voltage: %1V").arg(fenceArray[1].getElectricFenceVoltage()));
	ui.Fence3Data2->setText(QString("Voltage: %1V").arg(fenceArray[2].getElectricFenceVoltage()));
	ui.Fence4Data2->setText(QString("Voltage: %1V").arg(fenceArray[3].getElectricFenceVoltage()));
	ui.Fence5Data2->setText(QString("Voltage: %1V").arg(fenceArray[4].getElectricFenceVoltage()));
	ui.Fence6Data2->setText(QString("Voltage: %1V").arg(fenceArray[5].getElectricFenceVoltage()));
	ui.Fence7Data2->setText(QString("Voltage: %1V").arg(fenceArray[6].getElectricFenceVoltage()));
	ui.Fence8Data2->setText(QString("Voltage: %1V").arg(fenceArray[7].getElectricFenceVoltage()));
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

// *************** Main menu fence module buttons*****************
void JurassicSCADA::on_fencebtn_clicked()
{
	ui.mainSCADA->hide();
	ui.fenceScreen->show();
}

void JurassicSCADA::on_fencebackbtn_clicked()
{
	ui.fenceScreen->hide();
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
		ui.Gate1LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		ui.Gate1Data->setText("Gate 1 Open");
		ui.Gate1LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate2btn_clicked()
{
	gateArray[1].setGateStatus(!(gateArray[1].getGateStatus()));
	if (gateArray[1].getGateStatus() == true)
	{
		ui.Gate2Data->setText("Gate 2 Closed");
		ui.Gate2LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		ui.Gate2Data->setText("Gate 2 Open");
		ui.Gate2LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate3btn_clicked()
{
	gateArray[2].setGateStatus(!(gateArray[2].getGateStatus()));
	if (gateArray[2].getGateStatus() == true)
	{
		ui.Gate3Data->setText("Gate 3 Closed");
		ui.Gate3LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		ui.Gate3Data->setText("Gate 3 Open");
		ui.Gate3LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate4btn_clicked()
{
	gateArray[3].setGateStatus(!(gateArray[3].getGateStatus()));
	if (gateArray[3].getGateStatus() == true)
	{
		ui.Gate4Data->setText("Gate 4 Closed");
		ui.Gate4LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		ui.Gate4Data->setText("Gate 4 Open");
		ui.Gate4LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate5btn_clicked()
{
	gateArray[4].setGateStatus(!(gateArray[4].getGateStatus()));
	if (gateArray[4].getGateStatus() == true)
	{
		ui.Gate5Data->setText("Gate 5 Closed");
		ui.Gate5LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		ui.Gate5Data->setText("Gate 5 Open");
		ui.Gate5LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate6btn_clicked()
{
	gateArray[5].setGateStatus(!(gateArray[5].getGateStatus()));
	if (gateArray[5].getGateStatus() == true)
	{
		ui.Gate6Data->setText("Gate 6 Closed");
		ui.Gate6LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		ui.Gate6Data->setText("Gate 6 Open");
		ui.Gate6LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate7btn_clicked()
{
	gateArray[6].setGateStatus(!(gateArray[6].getGateStatus()));
	if (gateArray[6].getGateStatus() == true)
	{
		ui.Gate7Data->setText("Gate 7 Closed");
		ui.Gate7LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		ui.Gate7Data->setText("Gate 7 Open");
		ui.Gate7LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_gate8btn_clicked()
{
	gateArray[7].setGateStatus(!(gateArray[7].getGateStatus()));
	if (gateArray[7].getGateStatus() == true)
	{
		ui.Gate8Data->setText("Gate 8 Closed");
		ui.Gate8LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
	}
	else
	{
		ui.Gate8Data->setText("Gate 8 Open");
		ui.Gate8LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
	}
	changeGateCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::changeGateCountDisplay(Gate g[], int arraySize)
{
	int closedCount = getClosedGateCount(g, arraySize);
	ui.GateMenuData1->setText(QString("Gates Closed: %1/8").arg(closedCount));
	ui.GateData1->setText(QString("Gates Closed: %1/8").arg(closedCount));
	if (closedCount >=7)
	{
		ui.GateIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/Gate_Icon.png\"/></p></body></html>");
		ui.GateMenuData2->setText("Threat Level: Low");
		ui.GateData2->setText("Threat Level: Low");
	}
	else if (closedCount >= 5)
	{
		ui.GateIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/Gate_Icon.png\"/></p></body></html>");
		ui.GateMenuData2->setText("Threat Level: Medium"); 
		ui.GateData2->setText("Threat Level: Medium");
	}
	else
	{
		ui.GateIcon->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.GateMenuData2->setText("Threat Level: High");
		ui.GateData2->setText("Threat Level: High");
	}
}

// ********** Fence button handlers ****************
void JurassicSCADA::on_fence1btn_clicked()
{
	//Switch the fence status
	fenceArray[0].setElectricFenceStatus(!(fenceArray[0].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[0].getElectricFenceStatus() == true)
	{
		ui.Fence1Data->setText("Fence 1 Active");
		ui.Fence1LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence1Data2->setText(QString("Voltage: %1V").arg(fenceArray[0].getElectricFenceVoltage()));
	}
	else
	{
		ui.Fence1Data->setText("Fence 1 Inactive");
		ui.Fence1LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence1Data2->setText("Voltage: 0.0V");
	}
	//changeFenceCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_fence2btn_clicked()
{
	//Switch the fence status
	fenceArray[1].setElectricFenceStatus(!(fenceArray[1].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[1].getElectricFenceStatus() == true)
	{
		ui.Fence2Data->setText("Fence 2 Active");
		ui.Fence2LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence2Data2->setText(QString("Voltage: %1V").arg(fenceArray[1].getElectricFenceVoltage()));
	}
	else
	{
		ui.Fence2Data->setText("Fence 2 Inactive");
		ui.Fence2LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence2Data2->setText("Voltage: 0.0V");
	}
	//changeFenceCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_fence3btn_clicked()
{
	//Switch the fence status
	fenceArray[2].setElectricFenceStatus(!(fenceArray[2].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[2].getElectricFenceStatus() == true)
	{
		ui.Fence3Data->setText("Fence 3 Active");
		ui.Fence3LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence3Data2->setText(QString("Voltage: %1V").arg(fenceArray[2].getElectricFenceVoltage()));
	}
	else
	{
		ui.Fence3Data->setText("Fence 3 Inactive");
		ui.Fence3LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence3Data2->setText("Voltage: 0.0V");
	}
	//changeFenceCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_fence4btn_clicked()
{
	//Switch the fence status
	fenceArray[3].setElectricFenceStatus(!(fenceArray[3].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[3].getElectricFenceStatus() == true)
	{
		ui.Fence4Data->setText("Fence 4 Active");
		ui.Fence4LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence4Data2->setText(QString("Voltage: %1V").arg(fenceArray[3].getElectricFenceVoltage()));
	}
	else
	{
		ui.Fence4Data->setText("Fence 4 Inactive");
		ui.Fence4LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence4Data2->setText("Voltage: 0.0V");
	}
	//changeFenceCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_fence5btn_clicked()
{
	//Switch the fence status
	fenceArray[4].setElectricFenceStatus(!(fenceArray[4].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[4].getElectricFenceStatus() == true)
	{
		ui.Fence5Data->setText("Fence 5 Active");
		ui.Fence5LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence5Data2->setText(QString("Voltage: %1V").arg(fenceArray[4].getElectricFenceVoltage()));
	}
	else
	{
		ui.Fence5Data->setText("Fence 5 Inactive");
		ui.Fence5LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence5Data2->setText("Voltage: 0.0V");
	}
	//changeFenceCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_fence6btn_clicked()
{
	//Switch the fence status
	fenceArray[5].setElectricFenceStatus(!(fenceArray[5].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[5].getElectricFenceStatus() == true)
	{
		ui.Fence6Data->setText("Fence 6 Active");
		ui.Fence6LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence6Data2->setText(QString("Voltage: %1V").arg(fenceArray[5].getElectricFenceVoltage()));
	}
	else
	{
		ui.Fence6Data->setText("Fence 6 Inactive");
		ui.Fence6LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence6Data2->setText("Voltage: 0.0V");
	}
	//changeFenceCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_fence7btn_clicked()
{
	//Switch the fence status
	fenceArray[6].setElectricFenceStatus(!(fenceArray[6].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[6].getElectricFenceStatus() == true)
	{
		ui.Fence7Data->setText("Fence 7 Active");
		ui.Fence7LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence7Data2->setText(QString("Voltage: %1V").arg(fenceArray[6].getElectricFenceVoltage()));
	}
	else
	{
		ui.Fence7Data->setText("Fence 7 Inactive");
		ui.Fence7LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence7Data2->setText("Voltage: 0.0V");
	}
	//changeFenceCountDisplay(gateArray, NUMBER_OF_GATES);
}
void JurassicSCADA::on_fence8btn_clicked()
{
	//Switch the fence status
	fenceArray[7].setElectricFenceStatus(!(fenceArray[7].getElectricFenceStatus()));

	//Update the UI accordingly
	if (fenceArray[7].getElectricFenceStatus() == true)
	{
		ui.Fence8Data->setText("Fence 8 Active");
		ui.Fence8LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDgreen.png\"/></p></body></html>");
		ui.Fence8Data2->setText(QString("Voltage: %1V").arg(fenceArray[7].getElectricFenceVoltage()));
	}
	else
	{
		ui.Fence8Data->setText("Fence 8 Inactive");
		ui.Fence8LED->setText("<html><head/><body><p><img src =\":/JurassicSCADA/LEDred.png\"/></p></body></html>");
		ui.Fence8Data2->setText("Voltage: 0.0V");
	}
	//changeFenceCountDisplay(gateArray, NUMBER_OF_GATES);
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



