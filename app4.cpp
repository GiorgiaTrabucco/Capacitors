// app4.cpp
// you set C2 = 10 pF, C3 = 5 pF, and C4 = 15 pF
// draw 10^3 random values for C1 from a uniform distribution between [1,100]pF
// and determine the set of corresponding 10^3 equivalent capacities
// our system: Ceq = (C1 || C2) + (C3 || C4)

// library
#include "Capacitor.h"
#include <iostream>
#include <random>
#include <vector>
#include <fstream>

using namespace std;

int main(){
  // useful constants
  const int N = 1e3;
  const double min = 1;
  const double max = 100;

  // create object for output file
  ofstream outfile;
  // output file
  outfile.open ("true.dat");

  // capacitors
  Capacitor C2 = Capacitor(10e-12);
  Capacitor C3 = Capacitor(5e-12);
  Capacitor C4 = Capacitor(15e-12);
  vector<Capacitor> C1;

  // Total capacities
  vector<Capacitor> Ceq;

  //parallel between C3 and C4
  Capacitor C_p34 = C3 || C4;
  // cout << C_p34.get_C() << endl;

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(min, max); // uniform distribution between [1,100]pF

  //outfile << "C1 \t Ceq"<< endl;

  // We generate the N values of C1 and we calculate the correstonding Ctot
  for (int n=0; n<N; n++){
    // filling the vector of the capacitance C1
    C1.push_back(distrib(gen)*1e-12);
    // filling the vector of the total capacitance
    Ceq.push_back((C1[n] || C2) + C_p34);
    // cout << Ceq[n].get_C() << endl;
    // now we write them on the file
    outfile << C1[n].get_C() << "\t" << Ceq[n].get_C() << endl;
  }




  return 0;
}
