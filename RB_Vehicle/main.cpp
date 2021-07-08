#include <iostream>
#include <string>

using namespace std;

struct Other_Features
{
    string m_Transmission;
    int m_SittingCapacity;
    Other_Features(string Transmission = "Manual", int SittingCapacity = 5)
    {
        if (Transmission != "Automatic" && Transmission != "Manual")
        {
            cout << "Transmission allowed are Manual & Automatic.Setting Manual" << endl;
            m_Transmission = "Manual";
        }
        else
            m_Transmission = Transmission;
        
        m_SittingCapacity = SittingCapacity;
    }
};

class Vehicle
{

    int m_Mileage;
    string m_FuelType;
    Other_Features *m_otherFeatures;

public:
    Vehicle(string Transmission, int SittingCapacity, int Mileage, string FuelType)
    {
        m_Mileage = Mileage;
        if(FuelType !="Diesel" && FuelType !="Petrol")
        {
            cout << "Allowed Fuel Types are Petrol and Diesel" << endl;
            m_FuelType = "Petrol";
        }
        else
        {
            m_FuelType = FuelType;
        }
        m_otherFeatures = new Other_Features(Transmission, SittingCapacity);
    }

    int getMileage() const
    {
        return m_Mileage;
    }

    string getFuelType() const
    {
        return m_FuelType;
    }

    Other_Features *get_Other_Features() const
    {
        return m_otherFeatures;
    }

    void display();

    virtual ~Vehicle()
    {
        delete m_otherFeatures;
        cout << "delete ~" << endl;
    }

    virtual void start() = 0;
    virtual void stop() = 0;

};

void Vehicle::display()
{
    cout << "Mileage: " << getMileage() << endl;
    cout << "FuelTypes: " << getFuelType() << endl;
}

class VW: public Vehicle
{
public:
    VW(string Transmission = "Manual", int SittingCapacity = 5, int Mileage = 10, string FuelType = "Petrol"):Vehicle(Transmission, SittingCapacity, Mileage, FuelType)
    {

    }

    void start()
    {
        cout << "Starting VW" << endl;
    }

    void stop()
    {
        cout << "stoping VW" << endl;
    }

};

class Honda: public Vehicle
{
public:
    Honda(string Transmission ="Manual", int SittingCapacity = 5, int Mileage = 10, string FuelType = "Petrol"): Vehicle(Transmission, SittingCapacity, Mileage, FuelType)
    {}

    void start()
    {
        cout << "starting honda" << endl;
    }

    void stop()
    {
        cout << "Stopping Honda" << endl;
    }
};

void StartEngine(Vehicle *vh)
{
    vh->start();
}

void StopEngine(Vehicle *vh)
{
    vh->stop();
}

int main()
{
    Vehicle *vh;
    string car;

    do
    {
        cout << "please Enter the make of the car(Honda/VW)" << endl;
        /* code */
        cin >> car;

    } while (car!="VW" && car!="Honda");
    
    if(car == "VW")
    {
        vh = new VW();
    }
    else
        {
            vh = new Honda();
        }
    

    StartEngine(vh);
    cout << "Mileage : " << vh->getMileage() << endl;
    cout << "FuelType : " << vh->getFuelType() << endl;
    cout << "Transmission : " << (vh->get_Other_Features())->m_Transmission << endl;
    cout << "SittingCapacity : " << (vh->get_Other_Features())->m_SittingCapacity << endl;
    StopEngine(vh);
    delete vh;

    return 0;
}