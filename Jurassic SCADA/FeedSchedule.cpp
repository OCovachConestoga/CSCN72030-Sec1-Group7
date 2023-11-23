// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Jon
// FeedSchedule class function definitions

#include "FeedSchedule.h"
#include "FileManagement.h"

FeedSchedule::FeedSchedule()
{
    this->dataFileName      = "";
    this->mealType          = "None";
    this->feedingInterval   = NEVER;
    this->timeSinceLastFed  = 0;
}

FeedSchedule::FeedSchedule(std::string dataFileName, std::string mealType, 
    INTERVAL feedingInterval, int timeSinceLastFed)
{
    this->dataFileName      = dataFileName;
    this->mealType          = mealType;
    this->feedingInterval   = feedingInterval;
    this->timeSinceLastFed  = timeSinceLastFed;
}

FeedSchedule::~FeedSchedule()
{
    
}

void FeedSchedule::addFood(std::string foodType)
{
    
}

void FeedSchedule::dismissFeedAlarm()
{
    
}

int FeedSchedule::getTimeSinceLastFed() const
{
    return this->timeSinceLastFed;
}

void FeedSchedule::setTimeSinceLastFed(int time)
{
    this->timeSinceLastFed = time;
}

std::string FeedSchedule::getMealType() const
{
    return this->mealType;
}

void FeedSchedule::setMealType(std::string type)
{
    this->mealType = mealType;
}

int FeedSchedule::getFeedingInterval() const
{
    return this->feedingInterval;
}

void FeedSchedule::setFeedingInterval(INTERVAL feedingInterval)
{
    this->feedingInterval = feedingInterval;
}

void FeedSchedule::readFeedScheduleData()
{
    
}

