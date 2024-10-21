// cpp/route_planning.cpp

#include "route_planning.h"
#include <algorithm> // For std::sort

void RoutePlanner::addLocation(const Location& loc) {
    locations.push_back(loc);
}

std::vector<Location> RoutePlanner::findOptimalRoute(const Location& start, const Location& end) {
    std::vector<Location> optimalRoute; // Placeholder for the optimal route

    // Sample logic (replace with a real algorithm)
    optimalRoute.push_back(start);
    optimalRoute.push_back(end);

    return optimalRoute;
}
