#include <iostream>
#include "matrixNN.h"
//#include "vecNd.h"

using namespace std;


int main() {
        int n=3;
	
//matrix given in the canvas c


#include <vector>

 vector<vector<double>> B = {{1,2,7},{4,6,8},{5,6,1}};
    

	

        matrixNN C(n,B);    
        C.print();

     double deter=C.det(C);

        cout<< "determinat is "<<deter<<endl;
}
