#ifndef FLAG_H
#define FLAG_H

#include <string>

class Flag {
private:
    std::string country; // Variable to store the country name
    struct Color {
        std::string colorName; // Variable to store the color name
        int r, g, b; // Variables to store the RGB components of the color
    };
    Color* colors; // Array to store colors
    int numColors; // Variable to store the number of colors

public:
    Flag(); // Constructor
    ~Flag(); // Destructor
    void setCountry(std::string c); // Method to set the country name
    void setColors(int n); // Method to set the number of colors
    void setColor(int index, std::string colorName, int r, int g, int b); // Method to set color information for a specific index
    std::string getCountry() const; // Method to get the country name
    std::string getColors() const; // Method to get a string representation of the number of colors
};

#endif // FLAG_H
