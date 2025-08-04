#include <iostream>
#include <iomanip>
using namespace std;

// Define a namespace
namespace Math {
    const double PI = 3.14159;

    double circleArea(double radius) {
        return PI * radius * radius;
    }

    double circleCircumference(double radius) {
        return 2 * PI * radius;
    }
}

// Another namespace with potentially conflicting names
namespace Physics {
    const double PI = 3.14159265359;

    double kinectEnergy(double mass, double velocity) {
        return 0.5 * mass * velocity * velocity;
    }
}

int main() {
    // Use namespace wiht scope resolution operator::
    cout << "Circle area: " << Math::circleArea(5.0) << endl;
    cout << "Kinetic Energy: " << Physics::kinectEnergy(10, 5) << endl;

    // Access constants from different namespaces 
    cout << "Math PI: " << Math::PI << endl;
    cout << setprecision(9) << "Physics PI: " << Physics:: PI << endl;

    return 0;
}