#include <iostream>
#include <json/json.h>
#include <httplib.h>

// Function to handle the HTTP request and return the red signal status
void handle_request(const httplib::Request& req, httplib::Response& res) {
    // Create a JSON response
    Json::Value response;
    response["signal"] = "red";

    // Set the content type of the response to application/json
    res.set_header("Content-Type", "application/json");

    // Convert the JSON response to a string and send it as the HTTP response
    res.set_content(response.toStyledString(), "application/json");
}

int main() {
    // Create an HTTP server on port 8080
    httplib::Server svr;

    // Define the endpoint for the red signal status
    svr.Get("/traffic/signal", handle_request);

    // Start the server
    svr.listen("localhost", 8080);

    return 0;
}
