#include "matrixNN.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//default initialisation
matrixNN::matrixNN() {
    N = 0 ;
    A = vector<vector<double>>(); 
}

//special order2 and 3 null initialisation
matrixNN::matrixNN(int n) {
	N=n;
	A = vector<vector<double>>(n, vector<double>(n, 0.0));
 for(int i=0;i<n;i++){
 for (int j=0;j<n;j++){

    setAnn(i,j,0.0);
 }}
    
}

//special user defined 2 and 3 d values

matrixNN matrixNN::defmat2d(double A00, double A01, double A10, double A11){

	   matrixNN C;
	   C.N=2;
	   C.A={{A00,A01},{A10,A11}};
	   return C;
	   }
   
matrixNN matrixNN::defmat3d(double A00, double A01, double A02, double A10, double A11, double A12, double A20, double A21, double A22){
	   matrixNN C;
	   C.N=3;
	   C.A={{A00,A01,A02},{A10,A11,A12},{A20,A21,A22}};
	   return C;
   }

// User-defined initialization 
matrixNN::matrixNN(int size, vector<vector<double>> &B) {
    N = size; 
    A = B;     
}

//deconstructor
matrixNN::~matrixNN(){}







// Getter functions
vector<vector<double>> matrixNN::getA() {
    return A;  // Return the matrix A 
}
// Getter function to return the r-th row of matrix A
vector<double> matrixNN::getAn(int r) {
    return A[r]; 
}
// Getter function to return the element A[r][c]
double matrixNN::getAnn(int r, int c) {
    return A[r][c];
}





// Setter functions
void matrixNN::setA(vector<vector<double>> &B) {
    A = B;
}
// set the r-th row of matrix A to vector b
void matrixNN::setAn(int r, vector<double> &b) {
    A[r] = b;
}
//set the element at A[r][c]
void matrixNN::setAnn(int r, int c, double Ann) {
    A[r][c] = Ann;
}


// print the matrix A
void matrixNN::print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << A[i][j] << " "; 
        }
        cout << endl;
    }
}


int matrixNN::size(){
	return N;
}


// + add two matrices A and B
matrixNN matrixNN::operator+(matrixNN &B) {
    if (N != B.size()) {
        throw invalid_argument("Matrices must have the same size for addition.");
    }

    matrixNN C(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C.setAnn(i, j, A[i][j] + B.getAnn(i, j));
        }
    }

    return C;
}


// - subtract two matrices A and B
matrixNN matrixNN::operator-(matrixNN &B) {
    if (N != B.size()) {
        throw invalid_argument("Matrices must have the same size for subtraction.");
    }

    matrixNN C(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C.setAnn(i, j, A[i][j] - B.getAnn(i, j));
        }
    }

    return C;
}



// multiply two matrices A and B
matrixNN matrixNN::operator*(matrixNN &B) {
    if (N != B.size()) {
        throw invalid_argument("Matrix multiplication not possible");
    }

    matrixNN C(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double sum = 0.0;
            for (int k = 0; k < N; ++k) {
                sum += A[i][k] * B.getAnn(k, j);
            }
            C.setAnn(i, j, sum);
        }
    }

    return C;
}


//multiply matrix A with vector b
vecNd matrixNN::operator*(vecNd &b) {
    if (N != b.size()) {
        throw invalid_argument("Matrix-vector multiplication not possible: size mismatch.");
    }

    vecNd C;

    for (int i = 0; i < N; ++i) {
        double sum = 0.0;
        for (int j = 0; j < N; ++j) {
            sum += A[i][j] * b.getai(j);
        }
        C.setai(i, sum);
    }

    return C;
}


// transpose of matrix B
matrixNN matrixNN::Trans(matrixNN &B) {
    matrixNN C(N); 

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C.setAnn(i, j, B.getAnn(j, i));
        }
    }

    return C;
}


// det A = epsilon i j k l ..... A_0i A_1j A_2k....
// epsilon here is levi-civita symbol which is 1 for even permutaion and 0 for odd permutaions
// it will give terms with product of matrix element and levi-civita



//this following swap count and sort function is not a public function for the class
//to count the number of swaps to sort the Levi-Civita vector
int swapbysort(vector<int>& levi) {
    int n = levi.size();
    int swapCount = 0;

    // Bubble sort algorith
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (levi[j] > levi[j + 1]) {
                swap(levi[j], levi[j + 1]);
                swapCount++; // Count the swap
            }
        }
    }

    return swapCount;
}

// Determinant using Levi-Civita symbol 
double matrixNN::det(matrixNN &B) {
    int n = B.size();
    double determinant = 0.0;
// Initialize the Levi-Civita vector
    vector<int> levi(n);
    for (int i = 0; i < n; i++) {
        levi[i] = i;  
    }

    // Generate all permutations of levi and multiply with corresponding matrix elements and adding all terms
    do {

        vector<int> leviCopy = levi;
        int swapCount = swapbysort(leviCopy);//creating a additional copy since we need the orignal levi vector for permutaions
        // since sign will change , we need to redefine for each term so define inside loop
        int sign = (pow(-1, swapCount));

        // Calculate the term for this permutation
        double term = 1.0;
        for (int i = 0; i < n; i++) {
		int dummy =levi[i]  ;// actually this is my actual line{ term *= B[i][levi[i]];}  [][][] there brackets not working, so defining a dummy here
            term *= B.getAnn(i,dummy);     // // // A_:0i A_1j A_2k , the first index for the matrix is fixed by loop index , second index is given by the elements of levi vector
        }

        // Add sign*term
        determinant += sign * term;

    } while (next_permutation(levi.begin(), levi.end())); // do for all possible permutaions of levi vector

    return determinant;
}


//to find inverse
//invA = (1/ detA) (adj A)
//writing two function co factor and adjoint of A works within this class just to find inv
	



//vector minor to matrix minor(it will convert a N^2 vector into N X N matrix)
matrixNN vectortomatrix(vector<double> b){
	int n_minor=sqrt(b.size());   // the vector of minor N*N elemets
        matrixNN B(n_minor);  //(B is the all possible minor of A ) initialise null minor matrix for each element
        for(int i=0; i<n_minor; i++)
	{
	  for(int j=0; j<n_minor; j++)
	  {
	    B.setAnn(i,j,b[j + n_minor*i]);
          }
        }

     return B;
}

matrixNN matrixNN::cofactor(matrixNN &A)
{ 
   int n=A.size();
   matrixNN cofactorA(n);

	     
for(int i=0; i<n; i++)
  {
   for(int j=0;j<n; j++)
    {
     vector<double> b;  
   

     for(int k=0; k<n; k++)
         {
         for(int l=0; l<n; l++) 
	   {
         if(i !=k and j!=l) 
	     {
	   b.push_back(A.getAnn(k,l));
	     }    		       
           }
         }
     
     matrixNN B = vectortomatrix(b);
     cofactorA.setAnn(i,j,(pow((-1),i+j) * B.det(B))); 
     }
   }

    return cofactorA;
}

matrixNN matrixNN::inv(matrixNN &A){
        //initialising required matrices structure
	int n=A.size();
	matrixNN invA(n);
        matrixNN adjointA(n);
	matrixNN cofactorA(n);
	


	//finding cofactor and adjoint using defined functions
	cofactorA=cofactorA.cofactor(A);
	adjointA = cofactorA.Trans(cofactorA);
        double factor= (1/A.det(A));	
        
		for(int i=0; i<n; i++){
                      for(int j=0; j<n; j++){
                             invA.setAnn(i,j,(factor * adjointA.getAnn(i,j)));
		      }
		}

		return invA;

}

