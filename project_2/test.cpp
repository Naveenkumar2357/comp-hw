#include <iostream>
#include "matrixNN.h"
#include <vector>
#include "vecNd.h"

using namespace std;

int main() {
   int n=3;
//matrix given in the canvas c
 vector<vector<double>> B = {{1,2,7},{4,6,8},{5,6,1}};
//taking the vector vector matrix to defined matrixNN object
    matrixNN C(n,B);  
    cout<<"matrix given in the canvas"<<endl;
    C.print();
    double deter=C.det(C);
     cout<< "determinant of the matrix is "<<deter<<endl;
     matrixNN invC = C.inv(C);
     cout<<"inverse of the matrix is "<<endl;
     invC.print();
     //matrixNN cofactorC= cofactorC.cofactor(C);
    // cofactorC.print();
}
