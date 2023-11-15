// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Luke
// Gate class declaration

#pragma once
#include <string>

class Gate {
public:
    Gate();
    Gate(std::string dataFileName, std::string gateStatus);
    ~Gate();

    void openGate();
    void closeGate();
    std::string getGateStatus() const;
    void setGateStatus(std::string status);
    void readGateData();

private:
    std::string dataFileName;
    std::string gateStatus;
};
