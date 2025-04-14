#include <iostream> // Including input-output stream library for standard I/O operations.
#include <string> // Including string library for string operations.

// Base class representing a generic phone.
class Phone {
protected:
    std::string areaCode; // Area code of the phone number.
    std::string phone; // Phone number.
    std::string phoneType; // Type of the phone.

public:
    // Constructor initializing phone properties.
    Phone(const std::string& areaCode, const std::string& phone, const std::string& phoneType)
        : areaCode(areaCode), phone(phone), phoneType(phoneType) {}

    // Pure virtual function to display phone details.
    virtual void dispPhone() const = 0;
};

// Derived class representing a US phone number.
class USPhone : public Phone {
public:
    // Constructor calling base class constructor.
    USPhone(const std::string& areaCode, const std::string& phone, const std::string& phoneType)
        : Phone(areaCode, phone, phoneType) {}

    // Overridden function to display US phone details.
    void dispPhone() const override {
        std::cout << "\tUS " << phoneType << " Phone: +" << areaCode << " (" << phone.substr(0, 3) << ") "
                  << phone.substr(3, 3) << "-" << phone.substr(6) << std::endl;
    }
};

// Derived class representing an international phone number.
class InterPhone : public Phone {
private:
    std::string countryCode; // Country code of the phone number.
    std::string countryName; // Name of the country.

public:
    // Constructor calling base class constructor and initializing additional properties.
    InterPhone(const std::string& countryCode, const std::string& countryName,
               const std::string& areaCode, const std::string& phone, const std::string& phoneType)
        : Phone(areaCode, phone, phoneType), countryCode(countryCode), countryName(countryName) {}

    // Overridden function to display international phone details.
    void dispPhone() const override {
        std::cout << countryName << " " << phoneType << " Phone: +" << countryCode << " (" << areaCode << ") "
                  << phone << std::endl;
    }
};

int main() {
    Phone* phoneBook[5]; // Array to store pointers to Phone objects.

    // Dynamically allocate USPhone and InterPhone objects and store their pointers in phoneBook.
    phoneBook[0] = new USPhone("1", "3054635675", "Home");
    phoneBook[1] = new InterPhone("34", "\tSpain", "981", "1225478", "Home");
    phoneBook[2] = new USPhone("1", "9542017743", "Work");
    phoneBook[3] = new USPhone("1", "3038287965", "Mobile");
    phoneBook[4] = new InterPhone("58", "\tVenezuela", "414", "7308523", "Mobile");

    // Output My Mini Phone Book message.
    std::cout << "My Mini Phone Book ..." << std::endl;

    // Loop through phoneBook array and call dispPhone() for each object.
    for (int i = 0; i < 5; ++i) {
        phoneBook[i]->dispPhone();
    }

    // Free allocated memory by deleting objects.
    for (int i = 0; i < 5; ++i) {
        delete phoneBook[i];
    }

    return 0;
}
