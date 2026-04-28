// app2.cpp
// application to showcase the methods of the class Capacitor

#include "Capacitor.h"
#include <iostream>

using namespace std;

int main(){
  // capacitor with capacitance 10 pF
  Capacitor C1 = Capacitor(10e-12);
  // capacitor with capacitance 8.854 pF
  Capacitor C00 = Capacitor(1, 10e-9, 10e-9);

  // test for the getters
  cout << "C1: " << C1.get_C() << " F \n";
  cout << "C00: " << C00.get_C() << " F \n";

  // test for the setter
  C00.set_C(200e-12);
  cout << "C00: " << C00.get_C() << " F \n";

  C00.set_C(1, 10e-9, 10e-9);
  cout << "C00: " << C00.get_C() << " F \n";

  // series of two capacitors
  Capacitor C_s = C1 + C00;
  cout << "C_s: " << C_s.get_C() << " F \n";

  // parallel of two capacitors
  Capacitor C_p = C1 || C00;
  cout << "C_p: " << C_p.get_C() << " F \n";




  return 0;
}
