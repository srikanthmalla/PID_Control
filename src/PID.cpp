#include "PID.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  window_size=50;
}
PID::~PID() {
  free(window);
}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp=Kp;
  this->Ki=Ki;
  this->Kd=Kd;
  p_error=0;
  i_error=0;
  d_error=0;
  sum=0;
  pos=0;
  window= (double *)calloc(window_size,sizeof(double));
}

void PID::UpdateError(double cte, double dt) {
  double cte_old=p_error;
  d_error=(cte-cte_old)/dt;;
  p_error=cte;
  i_error=sum-window[pos]+(cte*dt);
  window[pos]=cte;
  pos=(pos+1)%window_size;
}

double PID::TotalError(double speed) {
  return (Kp - 0.0032 * speed) * p_error + Ki * i_error + (Kd + 0.0002 * speed) * d_error;
  // return Kp*p_error+Kd*d_error+Ki*i_error;
}

