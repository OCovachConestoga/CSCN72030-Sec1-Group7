// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Monorail class declaration

#pragma once
#include <string>

class Monorail {
public:
    Monorail();
    Monorail(std::string dataFileName, bool poweredStatus);
    ~Monorail();

    bool getPoweredStatus() const;
    void setPoweredStatus(bool status);

    void readMonorailData();

private:
    std::string dataFileName;
    bool poweredStatus;
};

