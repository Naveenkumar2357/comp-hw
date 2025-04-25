#include "complexn.h"
#include <iostream>
#include <cmath>
using namespace std;


int main() {
	
    complexn c1(4.0, 3.0);  
    complexn c2(1.0, 2.0);  
    
    cout<<"entered numbers \n";
    cout<<"c1 = (4.0 , 3.0 i ) "<<endl;
    cout<< "c2 = (1.0 , 2.0 i ) "<<endl;
                

    complexn sum = c1 + c2;  
    cout << "Sum of c1 and c2: (" << sum.getX() << ", " << sum.getY()<<"i" << ")\n";
 
    complexn diff = c1 - c2; 
    cout << "Difference c1 - c2: (" << diff.getX() << ", " << diff.getY()<<"i" << ")\n";

    complexn product = c1 * c2; 
    cout << "c1*c2 (" << product.getX() << ", " << product.getY()<<"i" << ")\n";

    complexn divi = c1 / c2;  
    cout << "c1/c2 (" << divi.getX() << ", " << divi.getY()<<"i" << ")\n";

    double absolutevalue = c1.absolute(); 
    cout << " |c1|: " << absolutevalue << endl;

    return 0;
}
