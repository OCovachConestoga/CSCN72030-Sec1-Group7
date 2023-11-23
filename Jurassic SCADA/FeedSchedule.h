// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Jon
// FeedSchedule class declaration

#pragma once
#include <string>

const enum INTERVAL {
    NEVER           = 0,
    THREE_HOURS     = 1,
    SIX_HOURS       = 2,
    TWELVE_HOURS    = 3,
    DAILY           = 4,
    TWO_DAYS        = 5,
    THREE_DAYS      = 6,
};

class FeedSchedule {
public:
    FeedSchedule();
    FeedSchedule(std::string dataFileName, std::string mealType, INTERVAL feedingInterval, 
        int timeSinceLastFed);
    ~FeedSchedule();

    void addFood(std::string foodType);
    void dismissFeedAlarm();
    int getTimeSinceLastFed() const;
    void setTimeSinceLastFed(int time);
    std::string getMealType() const;
    void setMealType(std::string type);
    int getFeedingInterval() const;
    void setFeedingInterval(INTERVAL feedingInterval);
    void readFeedScheduleData();

    bool isHungry();

private:
    std::string dataFileName;
    std::string mealType;
    INTERVAL feedingInterval;
    int timeSinceLastFed;
};
