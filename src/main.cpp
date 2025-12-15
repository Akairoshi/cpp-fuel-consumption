#include <iostream>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::vector;

struct Trip
{
    double tripDistance{};
    double tripFuel{};
};

template <typename T>
T inputNum(const std::string &prompt)
{
    T value{};
    while (true)
    {
        cout << prompt;
        if (!(cin >> value))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter number!" << "\n";
            continue;
        }
        if (value > 0)
        {
            break;
        }
        else
        {
            cout << "Zero impossible!" << "\n";
        }
    }
    return value;
    
}

vector<Trip> inputTrips(int count)
{
    vector<Trip> trips;
    trips.reserve(count);

    for (int i{}; i < count; i++)
    {
        Trip t{};
        cout << "---- Trip " << i + 1 << " ----\n";
        t.tripDistance = inputNum<double>("Distance (km): ");
        t.tripFuel = inputNum<double>("Fuel (l): ");
        trips.push_back(t);
    }

    return trips;

}

void calcTotal(const vector<Trip>& trips, double &totalDistance, double &totalFuel){
    for (const Trip &t : trips)
    {
        totalDistance += t.tripDistance;
        totalFuel += t.tripFuel;
    }
}

double calcConsumption(double totalDistance, double totalFuel){

    if (totalDistance <= 0){
        throw std::runtime_error("Error: total distance equals zero! Imposible to calculate fuel consumption!");
    }
    return (totalFuel / totalDistance) * 100;

}
void printResult(double consumption, double totalDistance, double totalFuel, double NORMAL_CONSUMPTION){
    
    cout << "Total distance: " << totalDistance << " km" << "\n";
    cout << "Total fuel used: " << totalFuel << " l" << "\n";
    cout << "Average consumption: " << consumption << " l/100 km" << "\n";

    if (consumption > NORMAL_CONSUMPTION) cout << "Fuel consumption is above normal" << "\n";
    else cout << "Fuel consumption is normal" << "\n";

}

int main()
{

    constexpr double NORMAL_CONSUMPTION {10.0};

    int tripsCount = inputNum<int>("Enter trips count: ");
    vector<Trip> trips = inputTrips(tripsCount);

    double totalDistance{};
    double totalFuel{};
    calcTotal(trips, totalDistance, totalFuel);

    try
    {
        double consumption = calcConsumption(totalDistance, totalFuel);
        printResult(consumption, totalDistance, totalFuel, NORMAL_CONSUMPTION);
    }
    catch(const std::exception& e)
    {
        cout << e.what() << "\n";
    }
    

    return 0;
}