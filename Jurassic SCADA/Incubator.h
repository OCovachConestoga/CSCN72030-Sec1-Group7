// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Incubator class declaration

#pragma once
#include <string>

/* abstract */ class Incubator {
public:
    Incubator();
    Incubator(std::string dataFileName, float temperature);
    /* virtual */ ~Incubator();

    float getTemperature() const;
    /* virtual */ void readIncubatorData();

private:
    std::string dataFileName;
    float temperature;
    float realtemperature;
};
