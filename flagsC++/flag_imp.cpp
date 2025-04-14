#include "flag.h"

// Constructor initializes member variables
Flag::Flag() {
    country = ""; // Initialize country name to an empty string
    colors = nullptr; // Initialize colors pointer to nullptr
    numColors = 0; // Initialize the number of colors to 0
}

// Destructor deallocates memory for the colors array
Flag::~Flag() {
    delete[] colors; // Deallocate memory for the colors array
}

// Method to set the country name
void Flag::setCountry(std::string c) {
    country = c; // Set the country name
}

// Method to set the number of colors and allocate memory for the colors array
void Flag::setColors(int n) {
    numColors = n; // Set the number of colors
    colors = new Color[n]; // Allocate memory for the colors array
}

// Method to set color information for a specific index
void Flag::setColor(int index, std::string colorName, int r, int g, int b) {
    colors[index].colorName = colorName; // Set the color name
    colors[index].r = r; // Set the red component
    colors[index].g = g; // Set the green component
    colors[index].b = b; // Set the blue component
}

// Method to get the country name
std::string Flag::getCountry() const {
    return country; // Return the country name
}

// Method to get a string representation of the colors
std::string Flag::getColors() const {
    std::string colorsStr = ""; // Initialize string to store colors information
    for (int i = 0; i < numColors; i++) {
        // Append color information to the string
        colorsStr += colors[i].colorName + " (" + std::to_string(colors[i].r) + ", ";
        colorsStr += std::to_string(colors[i].g) + ", ";
        colorsStr += std::to_string(colors[i].b) + ")";
        if (i < numColors - 1) {
            colorsStr += "\n"; // Add newline if it's not the last color
        }
    }
    return colorsStr; // Return the string representation of colors
}
