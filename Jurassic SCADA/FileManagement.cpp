#include "FileManagement.h"

#define READ		1
#define WRITE		2
#define SEEK		3
#define APPEND		4
#define TRUNC		5
#define MAX_LINES	50

// Constructors
FileManagement::FileManagement()
{
	this->fileName = "";
}

FileManagement::FileManagement(std::string fileName)
{

	this->fileName = fileName;
}

// Getters and Setters
void FileManagement::setFileName(std::string fileName)
{
	this->fileName = fileName;
}
std::string FileManagement::getFileName()
{
	return this->fileName;
}

// Destructor
FileManagement::~FileManagement()
{
	delete this;
}

// File Management functions
std::string* FileManagement::readFileData()
{
	// initializing empty data variable
	std::string fileData[MAX_LINES]{};


	// opening a read file
	std::ifstream fin;
	fin.open(this->fileName, READ);


	// checking if file is located
	if (!fin)
	{
		std::cout << "ERROR: file \""<< this->fileName <<"\" not found..." << std::endl;
		fileData[0] = "";
	}
	else
	{
		// read data inside file
		int i = 0;
		while (fin.good())
		{
			fin >> fileData[i];
			i++;
		}
	}
	
	// close file to prevent corruption
	fin.close();

	return fileData;
}

// USE THE HIGHEST SUPER CLASS TO ALLOW AN ARRAY OF EACH SEPARATE MODULE
void FileManagement::saveDataToFile(JurassicSCADA* arrayOfModules)
{
	//switch statement to save each important module data

	for (int i = 0; i < 7; i++)
	{
		switch (i)
		{
		case 0:
			// save Gates closed
			break;
		case 1:
			// save electric fences on, and voltage
			break;
		case 2:
			// save feed schedule important data
			break;
		case 3:
			// save camera stuff, probably nothing
			break;
		case 4:
			// save incubator eggs flipped
			break;
		case 5:
			// save weather info, probably nothing
			break;
		case 6: 
			// save Monorail cars active? or any other important data
			break;
		default:
			break;
		}
	}
}