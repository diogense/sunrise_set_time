#include <iostream>
#include <cmath>


using namespace std;

int main ( )
{
// variable declaration
double PI = 3.1415926;
double latitude,longitude, timezone;
int day_of_year;
double eqtime, y, i,o, decl, ha ;
 int sunrise_hour, sunrise_min;
 int sunset_hour, sunset_min;
 int sunrise,sunset;

cout << "Daylight-Sensitive Zombie Protection System By Noble,Fatima, Muhsin And Yussuf."<< endl;
cout << "This proram will calculate surise and sunset time for any date and location." << endl;

 cout << "Enter Latitude" <<"," << "Logitude: " ;
 cin >> latitude ;
 cin >> longitude ;

 cout << "Enter Timezone: " ;
 cin >> timezone;

 cout << "Enter Day Of the Year: " ;
 cin >> day_of_year;

  // day of the year converted into angle in radians
  y = ((2 * PI) / 365) * (day_of_year - 1);
  // assignment of (2y)  and (3y)
  i = 2 * y; o = 3 * y;
  // equation of time in minutes
 eqtime = 229.18 *(0.000075 + cos(y)*0.001868  - sin(y)*0.032077 - cos(i)*0.014615  - sin(i)*0.040849);

  // declination of the sun
 decl = 0.006918 - 0.399912 *cos(y) + 0.070257* sin(y)
            -0.006758*cos (i) + 0.000907*sin (i)
            -0.002697*cos(o) + 0.0014*sin(o) ;

  // hour angle of the sun
  ha = acos((cos(1.5853) / (cos(latitude * PI/180)*cos(decl))) - tan(latitude * PI/180)*tan(decl)) * 180/PI ;

  sunrise = 720 + 4*(longitude - ha) - eqtime - 60 * timezone;
  sunset =  720 + 4*(longitude + ha) - eqtime - 60 * timezone;

  sunrise_hour = floor(sunrise/60 );
  sunrise_min = sunrise - ( sunrise_hour * 60 ) ;

  sunset_hour = floor(sunset/60) ;
  sunset_min = sunset - ( sunset_hour * 60 ) ;


  cout << "Sunrise: "<< sunrise_hour << ":"<< sunrise_min << endl;
  cout << "Sunset: "<< sunset_hour << ":"<< sunset_min <<  endl;
}
/*
Test values:
Enter latitude, longitude:40.75 -74
Enter Timezone:-5
Enter day of year:180
Sunrise: 4:34
Sunset: 19:39
Daylight-Sensitive Zombie Protection System
This program will calculate sunrise and sunset time for any date and location
Enter latitude, longitude:37.5 -88.0
Enter Timezone:-6
Enter day of the year:11
Sunrise: 7:22
Sunset: 17:07
*/
