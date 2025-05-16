#include <iostream>
using namespace std;

void metersToKilometers() {
    double meters;
    cout << "Enter meters: ";
    cin >> meters;
    cout << meters << " meters = " << meters / 1000 << " kilometers\n";
}

void celsiusToFahrenheit() {
    double celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    cout << celsius << "°C = " << (celsius * 9/5) + 32 << "°F\n";
}

void gramsToKilograms() {
    double grams;
    cout << "Enter grams: ";
    cin >> grams;
    cout << grams << " grams = " << grams / 1000 << " kilograms\n";
}

void inchesToCentimeters() {
    double inches;
    cout << "Enter inches: ";
    cin >> inches;
    cout << inches << " inches = " << inches * 2.54 << " centimeters\n";
}

void litersToMilliliters() {
    double liters;
    cout << "Enter liters: ";
    cin >> liters;
    cout << liters << " liters = " << liters * 1000 << " milliliters\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Unit Converter Menu ---\n";
        cout << "1. Meters to Kilometers\n";
        cout << "2. Celsius to Fahrenheit\n";
        cout << "3. Grams to Kilograms\n";
        cout << "4. Inches to Centimeters\n";
        cout << "5. Liters to Milliliters\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: metersToKilometers(); break;
            case 2: celsiusToFahrenheit(); break;
            case 3: gramsToKilograms(); break;
            case 4: inchesToCentimeters(); break;
            case 5: litersToMilliliters(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 6);

    return 0;
}

