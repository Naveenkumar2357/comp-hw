//header file complex numbers
//real part is x , imaginary part is y 

#include <iostream>
#include <cmath>

class complexn {

	private:
		double x;
		double y;

	public:
		//default constructor
		complexn(); 
		complexn(double xx , double yy);
		//default destructor
		~complexn();



		//setter
		void setX(double xx){x=xx;}
		void setY(double yy){y=yy;}
                //getter
	        double getX(){return x;}
	        double getY(){return y;}

		

		//member functions
	        //	void print();
		double absolute();
		//operators

		complexn operator+(complexn &z);
		complexn operator-(complexn &z);
		complexn operator+=(complexn &z);
		complexn operator-=(complexn &z);
                complexn operator*(complexn &z);
		complexn operator/(complexn &z);




}; // only for header files
