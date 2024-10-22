// main.cpp

#include "route_planning.h"
#include "crow_all.h" // Include the Crow library
#include <json/json.h> // Include a JSON library for response formatting

// Function to convert a location to JSON
Json::Value locationToJson(const Location& loc) {
    Json::Value jsonLoc;
    jsonLoc["name"] = loc.name;
    jsonLoc["latitude"] = loc.latitude;
    jsonLoc["longitude"] = loc.longitude;
    return jsonLoc;
}

int main() {
    RoutePlanner planner;

    // Add example locations
    planner.addLocation(Location("Beach Street", 40.1234, -74.5678));
    planner.addLocation(Location("Union Place", 40.4321, -74.8765));
    planner.addLocation(Location("Market Square", 40.5432, -74.6789));

    crow::SimpleApp app; // Create a Crow application

    // Define the API endpoint for finding an optimal route
    CROW_ROUTE(app, "/find_route") // Endpoint for finding the route
    .methods("POST"_method)([&planner](const crow::request& req) {
        auto json = Json::Value();
        std::string startName = req.body; // Extract start location name from request body
        std::string endName = "Union Place"; // Set end location for this example

        Location start(startName, 40.1234, -74.5678); // Sample coordinates
        Location end(endName, 40.4321, -74.8765);

        std::vector<Location> route = planner.findOptimalRoute(start, end);

        Json::Value responseJson;
        for (const auto& loc : route) {
            responseJson.append(locationToJson(loc));
        }

        return crow::response{responseJson.toStyledString()}; // Return JSON response
    });

    app.port(8080).multithreaded().run(); // Run the app on port 8080
}
