//retirement calculator.
//takes current savings,current age, retirement age, interest % and % of amount saved monthly from the user and write the retirement plan in a text file.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void printarraysonfile(int array1[], double array2[],double yc[], double ci[], int size, ofstream& outstream) {
                outstream<<"year                    Total compounded amount              your contribution           compounded interest"<<endl;
        	for (int i = 0; i < size; i++){
                     outstream<<array1[i]<<"                          " <<array2[i]<<"                          "<<yc[i]<<"                         "<<ci[i]<<"            " <<endl;
	}

}


void printarrays(int array1[], double array2[],double yc[], double ci[], int size) {
                cout<<"year                    Total compounded amount              your contribution           compounded interest"<<endl;
        	for (int i = 0; i < size; i++){
                     cout<<array1[i]<<"                          " <<array2[i]<<"                          "<<yc[i]<<"                         "<<ci[i]<<"            " <<endl;
	}

}




void fillyear (int year[], int s){

 for (int i=0; i<s; i++ ){
   year[i]= 2026 + i;
 }
}

//here the program assumes the savings from the salary is added to the principle amount annually but the interst is calculated monthly
void compounded (double compound[], int s, double it, double cs, double asave){


	if (s>20){

	  for (int i=0; i < 20 ; i ++){	
	  compound [i]=cs * pow(1+ it /( 100 * 12), 12);
	  cs=compound[i]+asave;
	  }
  //increasing percentage of interst if someonen plan more than 20 years

	  it=it+2;
	  for (int i=20; i < s; i++){

          compound [i]=cs * pow(1+ it / (100 * 12), 12);
	  cs=compound[i]+asave;
	  }

	  }
	

        else {

          for (int i=0; i < s ; i ++){	
	  compound [i]=cs * pow(1+ it / (100 * 12), 12);
	  cs=compound[i]+asave;


	}

	}
}


//no need to use & for arrays
double compoundedtocontribution(double compound[], double yc[], double ci[], int s, double cs, double asave){


  yc[0]=cs;
  for(int i=1; i <s; i ++){
   yc[i] = yc[i-1] + asave;
  }


  for (int i=0; i<s; i ++){

	  ci[i]=compound[i]-yc[i];



  }

  return s;

}








int main(){
cout << fixed << setprecision(2);
ofstream outstream;

outstream<<fixed<<setprecision(2);

 //variable declarations
  //currentsavings:cs
  //currentage    :ca
  //retirement age:ra
  //interest%     :it
  //%of salary saved annually from salary ,  annual amount percentage:aap
  //monthly salary: ms
  //m             : monthly savings


//taking input from the user
        

	int ca , ra, s;
	double cs, it, as, aap, asave;

	cout<<"                      RETIREMENT CALCULATOR"<<endl<<"This program will give you a retirement plan"<<endl<<"Please give the following details and find your plan in the file named myretirementplan"<<endl;
	cout<<"your current savings in hand:"<<endl;
	cin>>cs; 
	cout<<"your current age:"<<endl;
	cin>>ca;
	cout<<"At what age you plan to retire:"<<endl;
	cin>>ra;
	cout<<"Annual interest percentage you would get for your savings"<<endl;
	cin>>it;
	cout<<"your annual salary:"<<endl;
	cin>>as;
	cout<<"percentage of amount you would like to save from your annual salary towards your retirement plan:"<<endl;
	cin>>aap;
	
	s= ra-ca;
        asave=as*aap/100;
//program variable declarations and allocations
//yc- your contribution , ci compunded interest
        int* year = new int[s];
	double* compound = new double[s];
	double* yc   = new double[s];
	double* ci   = new double[s];


        fillyear (year, s);
	compounded(compound , s, it, cs, asave);

	compoundedtocontribution(compound,yc,ci,s, cs,asave);
        printarrays(year, compound,yc,ci, s);




//writing on a file
//


        outstream.open("myretirementplan.txt");
        if (outstream.fail( )) {
        cout << "Input file opening failed.\n";
        exit(1);
	}
                                  
    	outstream<<"                      RETIREMENT PLAN"<<endl<<endl<<"you have given the following details and to estimate your plan"<<endl;
	outstream<<"your current savings in hand:"<<cs<<endl;
	outstream<<"your current age:"<<ca<<endl;
	outstream<<"At what age you plan to retire:"<<ra<<endl;
	outstream<<"Annual interest percentage you would get for your savings:"<<it<<endl;
	outstream<<"your annual salary:"<<as<<endl;
	outstream<<"percentage of amount you would like to save from your annual salary towards your retirement plan:"<<aap<<endl<<endl;


        printarraysonfile(year, compound,yc,ci, s, outstream);

	outstream.close();





	
	






 delete[] year;
 delete[] compound;
 delete[] yc;
 delete[] ci;

return 0;
}
