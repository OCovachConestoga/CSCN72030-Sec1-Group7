// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Aleks
// Car class function definitions

#include "Car.h"
#include "FileManagement.h"

Car::Car()
{

}

Car::Car(std::string dataFileName, bool doorsLocked, bool headlights, 
    float speed, float positionOnTrack, float tirePressure)
{

}

Car::~Car()
{

}

bool Car::getDoorsLocked() const
{
    return this->doorsLocked;
}

void Car::setDoorsLocked(bool locked)
{

}

bool Car::getHeadlights() const
{
    return this->headlights;
}

void Car::setHeadlights(bool on)
{

}

float Car::getSpeed() const
{
    return this->speed;
}

void Car::setSpeed(float speed)
{

}

float Car::getPositionOnTrack() const
{
    return this->positionOnTrack;
}

void Car::setPositionOnTrack(float position)
{

}

float Car::getTirePressure() const
{
    return this->tirePressure;
}

void Car::setTirePressure(float pressure)
{

}


void Car::accelerate()
{

}

void Car::decelerate()
{

}

void Car::stop()
{

}

void Car::unlockDoors()
{

}

void Car::lockDoors()
{

}

void Car::turnHeadlightsOn()
{

}

void Car::turnHeadlightsOff()
{

}

void Car::readCarData()
{

}

