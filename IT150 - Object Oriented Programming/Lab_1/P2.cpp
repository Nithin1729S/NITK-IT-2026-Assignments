#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    float engine;

public:
    
    Car() : brand("Unknown"), model("Unknown"), engine(0.0) {}

    
    void setInfo(const string& newBrand, const string& newModel, float newEngine) {
        brand = newBrand;
        model = newModel;
        engine = newEngine;
    }

    
    void getInfoFromUser() {
        cout << "Enter brand: ";
        getline(cin, brand);

        cout << "Enter model: ";
        getline(cin, model);

        cout << "Enter engine size (in liters): ";
        cin >> engine;
        cin.ignore(); 
    }

    
    void displayInfo() const {
        cout << "Brand: " << brand << "\nModel: " << model << "\nEngine Size: " << engine << " liters" << endl;
    }
};

int main() {
    
    Car car;

    
    cout << "Enter information for the car:\n";
    car.getInfoFromUser();

    
    cout << "\nCar Information:\n";
    car.displayInfo();

    return 0;
}
