#include "JurassicSCADA.h"

JurassicSCADA::JurassicSCADA(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.cameraScreen->hide();
	ui.popUpWindow->hide();


	//********************************* Initialization of camera objects *******************************************
	
	// for testing purposes
	Camera c1(2, true, "Cam 1 footage");
	c1.setCameraID(1);
	c1.setNightVision(false);
	c1.setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1.jpg\"/></p></body></html>");
	
	int expectedCamID = c1.getCameraID();
	bool expectedNightVision = c1.getNightVision();
	QString expectedFootage = c1.getFootage();


	
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

	// for testing purposes
	CameraSwitch.setFileName("CameraSwitch.txt");
	std::string expectedFileName = CameraSwitch.getFileName();



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
	if (ui.cameraLabel->text() == camera[0].getFootage())
	{
		if (camera[0].getNightVision() == false)
			camera[0].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1 NV.jpg\"/></p></body></html>");
		else
			camera[0].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 1.jpg\"/></p></body></html>");

		camera[0].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[1].getFootage())
	{
		if (camera[1].getNightVision() == false)
			camera[1].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2 NV.jpg\"/></p></body></html>");
		else
			camera[1].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 2.jpg\"/></p></body></html>");

		camera[1].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[2].getFootage())
	{
		if (camera[2].getNightVision() == false)
			camera[2].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3 NV.jpg\"/></p></body></html>");
		else
			camera[2].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 3.jpg\"/></p></body></html>");

		camera[2].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[3].getFootage())
	{
		if (camera[3].getNightVision() == false)
			camera[3].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4 NV.jpg\"/></p></body></html>");
		else
			camera[3].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 4.jpg\"/></p></body></html>");

		camera[3].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[4].getFootage())
	{
		if (camera[4].getNightVision() == false)
			camera[4].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5 NV.jpg\"/></p></body></html>");
		else
			camera[4].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 5.jpg\"/></p></body></html>");

		camera[4].displayNightVision(&ui);
	}



	else if (ui.cameraLabel->text() == camera[5].getFootage())
	{	
		if (camera[5].getNightVision() == false)
			camera[5].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6 NV.jpg\"/></p></body></html>");
		else
			camera[5].setFootage("<html><head/><body><p><img src=\":/JurassicSCADA/Dinosaur 6.png\"/></p></body></html>");

		camera[5].displayNightVision(&ui);
	}
	
}
// *********************************************************************************************************************************



