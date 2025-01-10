#include <iostream>
using namespace std;

// Base class for all vehicles
class Vehicle
{
protected:
    string brand;
    double rentalRate;

public:
    Vehicle(const string &b, double rate) : brand(b), rentalRate(rate) {}
    virtual void displayInfo() = 0; // Pure virtual function
    virtual double calculateRentalCost(int days)
    {
        return rentalRate * days;
    }
};

// Virtual base class to avoid duplication in derived classes
class MotorVehicle : virtual public Vehicle
{
public:
    MotorVehicle(const string &b, double rate) : Vehicle(b, rate) {}
};

class NonMotorVehicle : virtual public Vehicle
{
public:
    NonMotorVehicle(const string &b, double rate) : Vehicle(b, rate) {}
};

// Derived classes for specific vehicle types
class Car : public MotorVehicle
{
    int seatingCapacity;

public:
    Car(const string &b, double rate, int seats)
        : MotorVehicle(b, rate), seatingCapacity(seats) {}

    void displayInfo()
    {
        cout << "🚗 Car - Brand: " << brand << " | Rate per day: $" << rentalRate
             << " | Seats: " << seatingCapacity << endl;
    }
};

class Bike : public MotorVehicle
{
public:
    Bike(const string &b, double rate) : MotorVehicle(b, rate) {}

    void displayInfo()
    {
        cout << "🏍️  Bike - Brand: " << brand << " | Rate per day: $" << rentalRate << endl;
    }
};

class Bicycle : public NonMotorVehicle
{
public:
    Bicycle(const string &b, double rate) : NonMotorVehicle(b, rate) {}

    void displayInfo()
    {
        cout << "🚲 Bicycle - Brand: " << brand << " | Rate per day: $" << rentalRate << endl;
    }
};

// Rental system to manage vehicles
class RentalSystem
{
    Vehicle *vehicles[50];
    int vehicleCount = 0;

public:
    void addVehicle(Vehicle *vehicle)
    {
        if (vehicleCount < 50)
        {
            vehicles[vehicleCount++] = vehicle;
        }
        else
        {
            cout << "⚠️  Vehicle limit reached.\n";
        }
    }

    void showAvailableVehicles()
    {
        cout << "\n===== Available Vehicles =====\n";
        for (int i = 0; i < vehicleCount; ++i)
        {
            cout << i + 1 << ". ";
            vehicles[i]->displayInfo();
        }
        cout << "============================\n";
    }

    void rentVehicle(int index, int days)
    {
        if (index < 0 || index >= vehicleCount)
        {
            cout << "❌ Invalid vehicle selection.\n";
            return;
        }
        double cost = vehicles[index]->calculateRentalCost(days);
        cout << "💰 Total Rental Cost for " << days << " day(s): $" << cost << "\n";
    }
};

void takeUserInput(RentalSystem &system)
{
    int choice, days;
    cout << "\n🔢 Select a vehicle to rent (enter number): ";
    cin >> choice;
    cout << "📅 Enter number of days to rent: ";
    cin >> days;
    system.rentVehicle(choice - 1, days);
}

void addNewVehicle(RentalSystem &system)
{
    int type, seats;
    string brand;
    double rate;

    cout << "\n🚘 Add a New Vehicle:\n";
    cout << "1. Car\n2. Bike\n3. Bicycle\nChoose vehicle type: ";
    cin >> type;
    cout << "Enter brand: ";
    cin >> brand;
    cout << "Enter rental rate per day: $";
    cin >> rate;

    if (type == 1)
    {
        cout << "Enter seating capacity: ";
        cin >> seats;
        system.addVehicle(new Car(brand, rate, seats));
    }
    else if (type == 2)
    {
        system.addVehicle(new Bike(brand, rate));
    }
    else if (type == 3)
    {
        system.addVehicle(new Bicycle(brand, rate));
    }
    else
    {
        cout << "❌ Invalid vehicle type.\n";
    }
}

int main()
{
    RentalSystem system;

    system.addVehicle(new Car("Toyota", 50.0, 5));
    system.addVehicle(new Bike("Harley", 30.0));
    system.addVehicle(new Bicycle("Giant", 10.0));

    cout << "🚗 Welcome to the Vehicle Rental System! 🚗\n";
    system.showAvailableVehicles();

    char choice;
    do
    {
        cout << "\n🛠️  Menu:\n1. Rent a Vehicle\n2. Add a New Vehicle\nChoose an option (1/2): ";
        cin >> choice;

        if (choice == '1')
        {
            takeUserInput(system);
        }
        else if (choice == '2')
        {
            addNewVehicle(system);
            system.showAvailableVehicles();
        }
        else
        {
            cout << "❌ Invalid option.\n";
        }

        cout << "\n🔄 Would you like to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\n🙏 Thank you for using the Vehicle Rental System! Have a safe ride! 🚙\n";
    return 0;
}
