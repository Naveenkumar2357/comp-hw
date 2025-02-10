#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// variable and constant definition 

    const double pi= 3.141592653;
    double theta = 0;
    double h;
    double radians;
    double cosinerad;
    double sinerad;
    double diffsine;



    cout<<"PLEASE ENTER THE ANGLE THETA, WHERE YOU WANT THE DERIVATIVE OF SINE (THETA)";
    cin>>theta;
// since sine and cosine function change their slope at every 90 degree, having step size, h more than this will give meaning less resuls, so lets restrict the user
// to give only h value greater than 0 and less than pi/2. pi over 2 in radians is 1.5708
    cout<<"Enter the increment h  you want to find the numerical differentiation." << endl;
    cin>>h;
    while (0 > h || h >1.5708){
	    cout<<"plese enter a valid incremet h= ";
	    cin>>h;
    }

    


    radians= theta * pi / 180;

    cosinerad = cos(radians);
    
    diffsine = (sin(radians + h )  - sin(radians))/ h;


    cout<<" Comparision of differential of sine for the entered angle theta"<<endl;
    cout<<" Analytical sin("<<theta<<") = "<<cosinerad<<endl;
    cout<<" Numerical sine("<<theta<<") = "<<diffsine<<endl;

    return 0;

 }
