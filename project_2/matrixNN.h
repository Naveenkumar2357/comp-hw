#include <iostream>
#include <vector>
#include "vecNd.h"

//notation convention
//A=====>matrix
//A0, A1 , A2 ... =====> row1, row2
//A01, A12... =====> element of A with row index first and coloumn index next




using namespace std;

class matrixNN {

 private:
	 int N; // size of the square matricNN
         vector<vector<double>> A; //we may need to multiply with vector so , keeping matrix as double type

 public:

	 //default constructor
	 matrixNN();

	 //user defined initialisation for arbitrary dimension
	 matrixNN(int size, vector<vector<double>> &B); //{{}{}{}}  bracket initialisation



        //special order2 and 3 null initialisation
        matrixNN(2); 
        matrixNN(3);
        //special user defined 2 and 3 d values
        void defmat2d(double A00, double A01, double A10, double A11);
        void defmat3d(double A00, double A01, double A02, double A10, double A11, double A12, double A20, double A21, double A22);

         //deconstructor
	 ~matrixNN();

	 //Getter and setter

	 vector<<vector<double>> getA() ;  //getting matrix A as a whole object
         vector<double> getAn(int r);	   //getting a row in A
	 double getAnn(int r, int c );	   //getting any element of matrix A
			
	 void setA(vector<vector<double>> &B); setting //setting a new object A equal to defined matrixNN object B
         void setAn(int r, vector<double> &b);         // setting an array b in the n th row of A
	 void setAnn(int r, int c, double Ann);	   // setting an element Ann of A
					

	 //print function  for matrixNN class
	 void print();
	 int size(); //print out N size of the matrix 

	 //Arithmatic operation 
         matrixNN operator+(matrixNN &B);  //adding two matrices, check the two matrix is have samesize
	 matrixNN operator-(matrixNN &B);  //subrating two matrices, after checking the dimensions
         matrixNN operator*(matrixNN &B);  //matrix multiplication A*B, check coloumn of A is equal to row of B 
         vecNd operator*(vectorNd &b);  //matrix multiplied by vector  (A*a) //take a as column vector// check size of A is equalto size of a
         
	 
	 matrixNN Trans(matrixNN &B);  //Transpose of B
         matrixNN det(matrixNN &B);    //determinant of B
	 matrixNN inv(matrixNN &B);    //inverse of B // check first determinat is non zero
				       
};
	 
	
 







































}
