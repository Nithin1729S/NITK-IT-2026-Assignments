#include <iostream>
#include <stdexcept>
#include <string>

class DuplicateMobileNumberException : public std::exception {
public:
    const char* what() const noexcept override {
        return "DuplicateMobileNumberException";
    }
};

class ContactDetail {
private:
    std::string mobilenumber;
    std::string alternateMobilenumber;
    std::string email;

public:
    ContactDetail(const std::string& mobile, const std::string& alternate, const std::string& mail) : mobilenumber(mobile), alternateMobilenumber(alternate), email(mail) {}

    void display() {
        std::cout << "Mobile Number: " << mobilenumber << std::endl;
        std::cout << "Alternate Mobile Number: " << alternateMobilenumber << std::endl;
        std::cout << "Email: " << email << std::endl;
    }

    friend class ContactDetailBO;
};

class ContactDetailBO {
public:
    bool validate(const ContactDetail& cd) {
        if (cd.mobilenumber == cd.alternateMobilenumber)
            throw DuplicateMobileNumberException();
        return true;
    }
};

int main() {
    std::string mobile = "1234567890";
    std::string alternate = "0987654321";
    std::string email = "example@example.com";

    ContactDetail contact(mobile, alternate, email);
    ContactDetailBO bo;

    try {
        if (bo.validate(contact)) {
            std::cout << "Contact details are valid." << std::endl;
            contact.display();
        }
    } catch (const DuplicateMobileNumberException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
