


#include <iostream>
#include <vector>
#include "vecNd.h"
using namespace std;

// Constructor and destructor functions
vecNd::vecNd() {}

vecNd::vecNd(double a0, double a1) : a({a0, a1}) {}  // : initialising the elemenmts in the definition intself.. not as a function in the {}

vecNd::vecNd(double a0, double a1, double a2) : a({a0, a1, a2}) {}

vecNd::~vecNd() {}

// Getter 
vector<double> vecNd::geta() {
    return a;
}

//getting i'th element ai of a
double vecNd::getai(int ith) {
    return a[ith];
}

// Setter 
void vecNd::seta(vector<double> &b) {
    a = b;
}

void vecNd::setai(int ith, double value) {
    a[ith] = value;
}



int vecNd::size(){

  return a.size();

}




// Print function
void vecNd::print() {
    cout << "(";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1) cout << ", ";
    }
    cout << ")" << endl;
}

// Arithmetic operators
//
// // Addition of two vectors
vecNd vecNd::operator+(vecNd& b) {
    if (a.size() != b.a.size()) {
        cout << "Vectors must have the same dimension for addition" << endl;
        exit(1); 
    }

    vecNd c; // Result vector
    int n = a.size(); // Size of vector a
    for (int i = 0; i < n; i++) {
        c.a.push_back(a[i] + b.a[i]); // Perform addition
    }
    return c;
}

// Subtraction of two vectors
vecNd vecNd::operator-(vecNd& b) {
    if (a.size() != b.a.size()) {
        cout << "Vectors must have the same dimension for subtraction" << endl;
        exit(1); 
    }

    vecNd c; 
    int n = a.size(); 
    for (int i = 0; i < n; i++) {
        c.a.push_back(a[i] - b.a[i]);
    }
    return c;
}

//multiplication by a scalar
vecNd vecNd::operator*(double k) {
    vecNd c; 
    int n = a.size(); 
    for (int i = 0; i < n; i++) {
        c.a.push_back(a[i] * k); 
    }
    return c;
}

// Dot product (using '|' operator) since . is used for accessing member treat the symbol | representing dot prduct as projection
double vecNd::operator|(vecNd& b) {
    if (a.size() != b.a.size()) {
        cout << "Vectors must have the same size for dot product!" << endl;
        exit(1);
    }

    double c = 0; 
    int n = a.size(); 
    for (int i = 0; i < n; i++) {
        c += a[i] * b.a[i]; 
    }
    return c;
}

// Cross product (only valid for 3d vectors)
vecNd vecNd::operator*(vecNd& b) {
    if (a.size() != 3 || b.a.size() != 3) {
        cout << "In this program Cross product is only defined for 3D vectors." << endl;
        exit(1);
    }

    vecNd c; // Result vector
    c.a.push_back(a[1] * b.a[2] - a[2] * b.a[1]);
    c.a.push_back(a[2] * b.a[0] - a[0] * b.a[2]);
    c.a.push_back(a[0] * b.a[1] - a[1] * b.a[0]);

    return c;
}


