//horizontal range of a projectile
//variables
//angle initial projectile angle , in degree
//initial , initial velocity for the projectile
//range , horizontal range
//atr , angle to radian


# include <iostream>
using namespace std;
# include <cmath>


int main()


{  

	double angle;
	double initial;
	double range;
	double atr;
	//user interaction
        //getrting input from the user, limiting the angle from 0 to 180
	cout<<"This program takes initial velocity and angle of the projectile and find the horizontal range of the projectile"<<endl;
	cout<<"Enter the angle of the projectle in degree"<<endl;
	cin>>angle;
	if (angle > 180 || angle < 0)
	   {cout<<"Not a valid angle"<<endl;
	   exit(1);
	   }
	cout<<"Enter the initial velocity of the projectile in m/s "<<endl;
	cin>>initial;
	atr=angle* M_PI / 180;
      //  cout<<atr<<endl;
      //cout<<"trhe sin"<< sin(atr);
	range = (initial * initial * sin(2 * atr)) / 9.8;
	cout << "The horizontal range of the projectile is: " << range << " m"<<endl;

 return 0;
}
