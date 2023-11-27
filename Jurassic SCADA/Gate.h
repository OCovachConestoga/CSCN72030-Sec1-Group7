// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Luke
// Gate class declaration

#pragma once
#include "Ui_JurassicSCADA.h"
#include <string>
using namespace std;

class Gate
{
    int* gateID;
    bool* gateIsClosed;

public:
    //Contructors
    Gate(QWidget* parent = nullptr);
    Gate(int, bool);

    //Getters and Setters
    void openGate();
    void closeGate();
    bool getGateStatus();
    void setGateStatus(bool status);
    void readGateData();

    //Destructor
    ~Gate();
};
