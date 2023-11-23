// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Jon
// WeatherForecast class declaration

#pragma once
#include <string>

enum DIRECTION {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
};

enum PRECIPITATION {
    NONE            = 0,
    DRIZZLE         = 1,
    RAIN            = 2,
    FREEZING_RAIN   = 3,
    SLUSH           = 4,
    HAIL            = 5,
    SNOW            = 6,
};

enum WEATHER_STATUS {
    NORMAL          = 0,
    POOR            = 1,
    SEVERE          = 2,
    EXTREME         = 3,
};

class WeatherForecast {
public:
    WeatherForecast();
    WeatherForecast(std::string file, float temp, float hum, float pres, float speed, DIRECTION dir, PRECIPITATION prec, WEATHER_STATUS sta);
    ~WeatherForecast();

    float getTemperature() const;
    void setTemperature(float temp);
    float getHumidity() const;
    void setHumidity(float humidity);
    float getAirPressure() const;
    void setAirPressure(float pressure);
    float getWindSpeed() const;
    void setWindSpeed(float speed);
    DIRECTION getWindDirection() const;
    void setWindDirection(DIRECTION direction);
    PRECIPITATION getPrecipitation() const;
    void setPrecipitation(PRECIPITATION precipitation);
    WEATHER_STATUS getWeatherStatus() const;
    void setWeatherStatus(WEATHER_STATUS status);

    void readWeatherData();

private:
    std::string dataFileName;
    float temperature;
    float humidity;
    float airPressure;
    float windSpeed;
    DIRECTION windDirection;
    PRECIPITATION precipitation;
    WEATHER_STATUS status;
};
