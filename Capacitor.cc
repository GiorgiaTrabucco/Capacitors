// Capacitor.cc
// Implementation of the Capacitor class

#include "Capacitor.h"

// constructors
Capacitor::Capacitor(double C){
  C_ = C;
}

Capacitor::Capacitor(double eps_r, double A, double s){
  // A is in m^2 and s in m
  double eps_0 =  8.854e-12;  // F/m
  C_ = eps_0 * eps_r * A / s;
}

// getter
double Capacitor::get_C(){
  return C_;
}

// setter
void Capacitor::set_C(double C){
  C_ = C;
}

void Capacitor::set_C(double eps_r, double A, double s){
  // A is in m^2 and s in m
  double eps_0 =  8.854e-12;  // F/m
  C_ = eps_0 * eps_r * A / s;
}

// overload of operators
Capacitor Capacitor::operator+(Capacitor& rhs){
  double inverse = (1/C_) + (1/rhs.C_);
  return Capacitor(1/inverse);
}

Capacitor Capacitor::operator||(Capacitor& rhs){
  double sum = C_ + rhs.C_;
  return Capacitor(sum);
}
