#include <iostream>
using namespace std;

#include <fstream>

#include <vector>
#include <cmath>
#include <numeric> 
#include <cstdlib>

#include "mpreal.h"
using namespace mpfr;

#include "Brutus.h"

int main(int argc, char* argv[]) {
    // using mpfr::mpreal;    
  int n;
  mpreal t_end;
  mpreal eta = "0.24";
  mpreal t = "0";
  mpreal epsilon; // = "1e-6"; // Bulirsch-Stoer tolerance
  int numBits;	
  double dt;
  int pmax;

  cin >> n >> t_end >> dt >> epsilon >> numBits >> pmax;
  cout << "# n=" << n << " tend=" << t_end <<  " dt=" << dt << " eps=" << epsilon  <<  " lw=" << numBits << " pmax=" << pmax <<endl;
  //store data in vector
  vector<double> data(7*n);
  vector<mpreal> datmp(7*n);
  double temp;
  for (int i = 0; i < data.size(); ++i){
      cin >> data[i];
      datmp[i] = (mpreal)data[i];
      //cout << datmp[i] << " " <<  i << endl;
   }
 
   //Brutus brutus = Brutus(datmp);
  Brutus brutus = Brutus(t, datmp, epsilon, numBits, pmax);

   vector<string> v = brutus.get_data_string();
 
   vector<mpreal> e3;
   mpreal e30 = brutus.get_energies()[0];

   cout << t << " " << 0.0 << " ";
   for (int i = 0; i < v.size(); ++i){
     cout << v[i] << " ";
   }
   cout << endl;

   while(t<t_end) {
	t+=dt;
   	brutus.evolve((mpreal)t);
   	v = brutus.get_data_string();
	e3 = brutus.get_energies();
	
	cout << t << " " << (e3[0]/e30-1.0) << " "; 
   	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	   }
	   cout << endl;
   }
  //Brutus intB = Brutus();
		
  return 0;
}



    

