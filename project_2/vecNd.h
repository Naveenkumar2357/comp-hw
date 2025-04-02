#include <iostream>
#include <vector>
using namespace std;

//a --> array, dynamical size
//A --> matrix, dynamical size

class vecNd{

	private:

		vector<double> a;

        public:
		vecNd();//default
		vecNd(double a0, double a1); //initialise 2 d vector object with user defined entries
		vecNd(double a0, double a1, double a2); //initialise 3 d vector object with user defined entries
		~vecNd();
		

                // Getter
                vector<double> geta() ;  //getting vector a
                double getai(int ith) ; // getai  -- getting ith element of a

               // Setter
               void seta( vector<double> &b ); //setting a vector object b as a
               void setai(int ith, double value);// setting value for element ai of a



	       int size();
               // Print function
               void print() ;

              // Arithmetic operators
              vecNd operator+(vecNd &b) ;  //addition of two vectors // note that b is an another object , to access the vector in the b {use b.a} 
              vecNd operator-(vecNd &b) ;  //subtraction of two vectors
              vecNd operator*(double k) ;//multiplication by a scalar
	      double operator|(vecNd &b) ;     //vector dot product
              vecNd operator*(vecNd &b) ;      //vector cross product    don't use X as a variable in this program
};
 	        

