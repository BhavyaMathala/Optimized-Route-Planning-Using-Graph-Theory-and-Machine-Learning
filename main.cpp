// cpp/main.cpp

#include <iostream>
#include "route_planning.h"

int main() {
    RoutePlanner planner;

    // Add some locations
    planner.addLocation(Location("A", 10.0, 20.0));
    planner.addLocation(Location("B", 30.0, 40.0));
    planner.addLocation(Location("C", 50.0, 60.0));

    // Find optimal route from A to C
    std::vector<Location> optimalRoute = planner.findOptimalRoute(Location("A", 10.0, 20.0), Location("C", 50.0, 60.0));

    // Print the optimal route
    std::cout << "Optimal Route:" << std::endl;
    for (const Location& loc : optimalRoute) {
        std::cout << loc.name << " (" << loc.latitude << ", " << loc.longitude << ")" << std::endl;
    }

    return 0;
}
