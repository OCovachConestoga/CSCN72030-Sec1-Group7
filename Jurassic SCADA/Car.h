// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Car class declaration

#pragma once
#include <string>

class Car {
public:
    Car();
    Car(std::string dataFileName, bool doorsLocked, bool headlights, float speed, float positionOnTrack, float tirePressure);
    ~Car();

    bool getDoorsLocked() const;
    void setDoorsLocked(bool locked);
    bool getHeadlights() const;
    void setHeadlights(bool on);
    float getSpeed() const;
    void setSpeed(float speed);
    float getPositionOnTrack() const;
    void setPositionOnTrack(float position);
    float getTirePressure() const;
    void setTirePressure(float pressure);

    void accelerate();
    void decelerate();
    void stop();
    void unlockDoors();
    void lockDoors();
    void turnHeadlightsOn();
    void turnHeadlightsOff();
    void readCarData();

private:
    std::string dataFileName;
    bool doorsLocked;
    bool headlights;
    float speed;
    float positionOnTrack;
    float tirePressure;
};
