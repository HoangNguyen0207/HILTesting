#pragma once
#include <QObject>
#include <math.h>

const double SEMI_MAJOR_AXIS = 6378137;
const double SQUARE_EARTH_ECCENTRICITY = 0.0067;
const double D2R = (3.14159/180);
const double R2D = (180/3.14159);
const double PI = 3.14159;
const double EARTH_RADIUS = 6371000;

struct LatLongCoordinate_t
{
        double lat;
        double lon;
};

inline double getDistanceFromLatLon(double lat1, double lon1, double lat2, double lon2)
{
    lat1 = D2R * lat1;
    lon1 = D2R * lon1;
    lat2 = D2R * lat2;
    lon2 = D2R * lon2;
    double d = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2);
    d = acos(d);
    d *= EARTH_RADIUS;
    return d;
}

inline void calculateLatLong(double lat, double lon, double bearing, double distance, LatLongCoordinate_t& newLatLon)
{
    double lat1 = D2R * lat;
    double lon1 = D2R * lon;
    double Ad = (double)distance/EARTH_RADIUS;
    double angle = D2R * bearing;

    double tempLat = asin(sin(lat1) * cos(Ad) + cos(lat1) * sin(Ad) * cos(angle));
    newLatLon.lat = ((tempLat * R2D));
    newLatLon.lon = ((lon1 + atan2(sin(angle) * sin(Ad) * cos(lat1), cos(Ad) - sin(lat1) * sin(tempLat))) * R2D);
}


