#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

double pi = 3.1415926;
double RadToDeg (double tmp)
{
    return (tmp * pi/ 180);
}
double DegToRads (double tmp)
{
    return (tmp * 180 / pi);
}
// Function to calculate the angle of the day
double dayAngle (int DayOfYear)
{
    double DayAngle;
// calculate angle of day in radians
    DayAngle = ((2*pi) / 365)*(DayOfYear - 1);

    return DayAngle;
}

// Function to calculate Equation of time
double EqOfTime (double DayAngle)
{
    double eqTime;
// Equation of time (in radian)
    eqTime =229.18 *(0.000075
                     +(0.001868*(cos(DayAngle)))
                     - (0.032077*(sin(DayAngle)))
                     - (0.014615*(cos(2*DayAngle)))
                     - (0.040849*(sin(2*DayAngle))));
    return eqTime;
}
double Declination (double DayAngle)
{
    double decl;
    decl = 0.006918-(0.399912*cos(DayAngle))
           +(0.070257*sin(DayAngle))-(0.006758*cos(2*DayAngle))
           +(0.000907*sin(2*DayAngle))-(0.002697*cos(3*DayAngle))
           +(0.00148 * sin (3*DayAngle));
    return decl;
}

int main( )
{
    double lat;
    double lon;
    int timezone;
    int DayOfYear;
    double pi = 3.1415926;
    double rlat = lat *(pi/180);

    cout << "enter your latitude" << '\n';
    cin >> lat;
    cout << "enter your longitude" << '\n';
    cin >> lon;
    cout << "enter your timezone" << '\n';
    cin >> timezone;
    cout << "enter your day of year" << '\n';
    cin >> DayOfYear ;


//solutins
    double _AngleOfDay = dayAngle (DayOfYear );
    double _Declinaison = Declination (_AngleOfDay);
    double _EqOfTime = EqOfTime (_AngleOfDay);

    cout << _AngleOfDay << '\n';
    cout << _Declinaison << '\n';
    cout << _EqOfTime << '\n';
//hour Angle
    double hAngle =acos(floor((cos(1.5853)) / ((cos(rlat))*(cos (_Declinaison))) - ((tan(rlat))))
                        *(tan( _Declinaison)));

    hAngle = DegToRads(hAngle);
//sunrise in local min and sunset in UTC
    double sunrise, sunset;
    sunrise = floor(720 +(4*(lon - hAngle)) -_EqOfTime - (60 * timezone));
    sunset = floor(720 +(4*(lon + hAngle)) -_EqOfTime - (60 * timezone));

//sunrise
    double sunriseH = floor(sunrise / 60);
    double sunriseM = sunrise - (sunriseH * 60);
// sunset
    double sunsetH = floor(sunset / 60);
    double sunsetM = sunset - (sunsetH * 60);

    cout << "The sunrise time will approx. be: "<< sunriseH << ":" << sunriseM<< endl;
    cout << "the sunset time will approx. be: "<< sunsetH << ":" << sunsetM<< endl;
    return 0;
}
