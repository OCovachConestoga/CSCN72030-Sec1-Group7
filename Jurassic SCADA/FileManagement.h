#pragma once

#include "JurassicSCADA.h"
#include <iostream>
#include <fstream>
#include <string.h>

class FileManagement
{
	std::string fileName;

public:
	// Constructors
	FileManagement();
	FileManagement(std::string);

	// Getters and Setters
	void setFileName(std::string);
	std::string getFileName();

	// Destructor
	~FileManagement();

	// File Management functions
	std::string* readFileData();

	void saveDataToFile(JurassicSCADA*);
};