// CSCN72030-23F Project III
// Group 7: Owen Covach, Aleks Grujicic, Luke Bolhous, Jonathan Ward
// Jurassic Park SCADA

// Jon
// WeatherForecast class function definitions

#include "WeatherForecast.h"
#include "FileManagement.h"

WeatherForecast::WeatherForecast()
{
    this->dataFileName      = "";
    this->temperature       = 0;
    this->humidity          = 0;
    this->airPressure       = 0;
    this->windSpeed         = 0;
    this->windDirection     = NORTH;
    this->precipitation     = NONE;
    this->status            = NORMAL;
}

WeatherForecast::WeatherForecast(std::string file, float temp, float hum, float pres, float speed, DIRECTION dir, PRECIPITATION prec, WEATHER_STATUS sta)
{
    dataFileName      = file;
    temperature       = temp;
    humidity          = hum;
    airPressure       = pres;
    windSpeed         = speed;
    windDirection     = dir;
    precipitation     = prec;
    status            = sta;
}

WeatherForecast::~WeatherForecast()
{
    
}

float WeatherForecast::getTemperature() const
{
    return this->temperature;
}

void WeatherForecast::setTemperature(float temp)
{
    this->temperature = temp;
}

float WeatherForecast::getAirPressure() const
{
    return this->airPressure;
}

void WeatherForecast::setAirPressure(float pressure)
{
    this->airPressure = pressure;
}

float WeatherForecast::getWindSpeed() const
{
    return this->windSpeed;
}

void WeatherForecast::setWindSpeed(float speed)
{
    this->windSpeed = speed;
}

DIRECTION WeatherForecast::getWindDirection() const
{
    return this->windDirection;
}

void WeatherForecast::setWindDirection(DIRECTION direction)
{
    this->windDirection = direction;
}

float WeatherForecast::getHumidity() const
{
    return this->humidity;
}

void WeatherForecast::setHumidity(float humidity)
{
    this->humidity = humidity;
}

PRECIPITATION WeatherForecast::getPrecipitation() const
{
    return this->precipitation;
}

void WeatherForecast::setPrecipitation(PRECIPITATION precipitation)
{
    this->precipitation = precipitation;
}

WEATHER_STATUS WeatherForecast::getWeatherStatus() const
{
    return this->status;
}

void WeatherForecast::setWeatherStatus(WEATHER_STATUS weatherStatus)
{
    this->status = weatherStatus;
}

void WeatherForecast::readWeatherData()
{
    
}
