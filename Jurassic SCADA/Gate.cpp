// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Luke
// Gate class function definitions

#include "Gate.h"
#include "FileManagement.h"

//Contructors
Gate::Gate(QWidget* parent)
{
    this->gateID = new int;
    this->gateIsClosed = new bool;
    *this->gateID = 0;
    *this->gateIsClosed = true;
}
Gate::Gate(int ID, bool isClosed)
{
    this->gateID = new int;
    this->gateIsClosed = new bool;
    *this->gateID = ID;
    *this->gateIsClosed = isClosed;
}

//Getter and Setters
void Gate::openGate()
{
    *gateIsClosed = false;
}
void Gate::closeGate()
{
    *gateIsClosed = true;
}
bool Gate::getGateStatus()
{
    return *gateIsClosed;
}
void Gate::setGateStatus(bool status)
{
    *gateIsClosed = status;
}
void Gate::readGateData()
{
    
}

//Destructor
Gate::~Gate()
{
    delete gateID;
    delete gateIsClosed;
}