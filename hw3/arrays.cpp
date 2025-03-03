//learning outcomes...
//arrays, dynamic memory allocation, function with multiple returns , call by reference.
//


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//to swap
void swap(int &a , int &b) 
    {
       int t= a;
       a=b;
       b=t;

    }


//to sort any array
void bubblesort(int array[] , int size) {
       
	for (int i =0; i < size -1; i++)
	{
		for (int j=0; j < size - i - 1; j ++)
		{
                    if (array[j] > array[j+1])
		    {
                       swap(array[j], array[j+1]);
		    }
	}
}

}

//TO print arrays
void printarrays(int array[], int size) {

        	for (int i = 0; i < size; i++){
                     cout<<array[i]<<"  ";
	}

}

//to fill array of size s with random number with some range- 1- maximum number
void fillarray(int array[], int size, int range) {
     
       for (int i = 0 ; i<size ; i++){
           array[i]= rand() % range + 1;
       }
}


double mean (int array[], int size){
        
	int sum=0;
	double mean1;
	for(int i =0; i<size; i++){
        sum += array[i];
	}

	//casting here
        mean1= (double) sum / size;

	return mean1;

}


double stdev (int array[], int size, double meanda1){
        double summ=0.0;
	double sd;
       for(int i = 0; i< size; i++){
	       summ += pow (array[i]-meanda1, 2);
	 }
       sd= sqrt((double)summ /size);

       return sd;


}



// pass by reference

void meanandsd( int array[], int size, double &passmeanda1, double &passsdda){
        int sum=0;
        double summ=0.0;
	

	for(int i=0; i<size; i++){
        sum += array[i];
	}

	passmeanda1 = (double) sum / size; 

        for(int i = 0; i< size; i++){
	       summ += pow (array[i]-passmeanda1, 2);
	}
	passsdda = sqrt((double) summ/size);
    

}



int main(){
       srand(time(0));
//declarations
     
       int array1[20];
       int s;
       //size is allacatable, will be get from interactive user input
       cout<<"Enter the size of the dynamic array"<<endl;
       cin>>s;
       int *dynamicarray1 = new int[s];
       
// mean of dynamically allocated array
       double meanda1;
       double passmeanda1=0;
       double passsdda=0;
// standard deviation of dynamically allocated array
       double sdda;
//task1 array of fixed size 20//  sort and print
           
      fillarray(array1, 20, 100);
      cout<<"random array of size 20"<<endl;
      cout<< "[ ";
      printarrays(array1, 20);
      cout<< " ]"<<endl;
      bubblesort(array1, 20);
      cout<<"sorted array of size 20"<<endl;
      cout<<"[ ";
      printarrays(array1,20);
      cout<<" ]"<<endl<<endl;
    
//task2 dynamic array- mean and standard deviation
        

       fillarray(dynamicarray1, s , 50);
       

      cout<<"dynamic array of size "<< s <<endl;
      cout<< "[ ";
      printarrays(dynamicarray1, s);
      cout<< " ]"<<endl;

      meanda1 = mean(dynamicarray1 , s);
      cout<<"The mean of the dynamicarray of entered size is"<<endl;
      cout<<meanda1<<endl;

      sdda= stdev(dynamicarray1, s, meanda1);
      cout<<"Standard deviation of dynamic array single function"<<endl;
       cout<<sdda<<endl;
//results from pass by reference


       meanandsd(dynamicarray1, s, passmeanda1, passsdda);
       cout<<"mean and standard deviation for dynamic array using same function pass by reference"<<endl;
       cout<<"mean :"<<passmeanda1<<endl;
       cout<<"standard deviation: "<<passsdda<<endl;



      







  delete [] dynamicarray1;

    return 0;

}
        

