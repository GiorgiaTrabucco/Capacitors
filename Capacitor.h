// Capacitor.h
// header file of the Class Complex

#include <iostream>
using namespace std;

class Capacitor {

private:
  //data members
  double C_; // F

public:
  // constructors
  Capacitor(double C);
  Capacitor(double eps_r, double A, double s);

  // getter
  double get_C();

  // setter
  void set_C(double C);
  void set_C(double eps_r, double A, double s);

  // Overload the operators
  // series of 2 capacitors
  Capacitor operator+(Capacitor& rhs);
  // parallel of 2 capacitors
  Capacitor operator||(Capacitor& rhs);
};
