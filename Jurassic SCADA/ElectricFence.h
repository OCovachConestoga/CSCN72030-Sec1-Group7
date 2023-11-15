// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Luke
// ElectricFence class declaration

#pragma once
#include <string>

class ElectricFence {
public:
    ElectricFence();
    ElectricFence(std::string dataFileName, float currentVoltage);
    ~ElectricFence();

    void activateFence();
    void deactivateFence();
    float getVoltage() const;
    void setVoltage(float voltage);
    void readElectricFenceData();

private:
    std::string dataFileName;
    float currentVoltage;
};
