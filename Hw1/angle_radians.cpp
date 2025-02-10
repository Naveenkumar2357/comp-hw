//This program takes angles(in theta) as integer and convert it to radians//
//variables (name,definition, in or out, type) 
//angle,angles in degree, input, integer
//a_i_r, angle in randian, output, double


# include <iostream>
# include <cmath>
using namespace std;

int main ()
{
 int angle = 9;
 double a_i_r= 9.99;
	 cout<<" This program takes angles in degree and convert it into radians (NOTE: THE PROGRAM ONLY TAKES INTEGER INPUTS)" <<endl;
	cout<<"Enter angle in degree"<<endl;
	 cin>>angle;
	   if(cin.fail()){
	    	cout << "Input is not an integer!";
		exit(1);}
	   else if(angle >= -360 && angle<= 360)
	   {
                a_i_r=angle*M_PI/180 ;
                cout<<"your angle in radians is " << a_i_r<<endl;
                           }
	   else{
	       cout<<" Enter a valid angle";
	   }
	return 0;

}
