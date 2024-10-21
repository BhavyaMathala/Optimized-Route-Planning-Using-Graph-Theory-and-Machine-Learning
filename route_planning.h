// cpp/route_planning.h

#ifndef ROUTE_PLANNING_H
#define ROUTE_PLANNING_H

#include <vector>
#include <string>

struct Location {
    std::string name;
    double latitude;
    double longitude;

    // Constructor for Location
    Location(const std::string& name, double lat, double lon) 
        : name(name), latitude(lat), longitude(lon) {}
};

class RoutePlanner {
private:
    std::vector<Location> locations;

public:
    void addLocation(const Location& loc);
    std::vector<Location> findOptimalRoute(const Location& start, const Location& end);
};

#endif // ROUTE_PLANNING_H
