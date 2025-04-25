#include <iostream>
#include "complexn.h"
#include <cmath>
using namespace std;

//default constructor , user defined constructor and default destructor
complexn::complexn(){x=0; y=0;}
complexn::complexn(double xx, double yy){x=xx; y=yy;}
complexn::~complexn(){};


//complexn{return type of the function} complexn{this following operator is a member function of this object}::operator+(complexn{the following arguement that the function gonna take is also the same type of the object } &z{value which the pointer z point})
//complexn& (now the returned object of this function points to somenthing) complexn::operator+(complexn &z)


complexn complexn::operator+(complexn &z)
     {return complexn (getX()+z.getX(), getY()+z.getY());}

complexn complexn::operator+=(complexn &z)
{	
	x+=z.getX();
	y+=z.getY();
	return *this; 
        }
complexn complexn::operator-(complexn &z)
		{return complexn (getX()- z.getX(), getY() - z.getY());}
complexn complexn::operator-=(complexn &z)
{
      x-=z.getX(); 
      y-=z.getY();	
      return *this;
      }
complexn complexn::operator*(complexn &z)

{ return complexn (getX()*z.getX() - getY()*z.getY() , z.getY()*getX() + z.getX()*getY());}



complexn complexn::operator/(complexn &z){
	double denominator = z.getX() * z.getX() + z.getY() * z.getY();
        return complexn((getX() * z.getX() + getY() * z.getY()) / denominator,
                        (getY() * z.getX() - getX() * z.getY()) / denominator);
    }

    
    double complexn::absolute() {
        return sqrt(getX() * getX() + getY() * getY());
    }

