#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  
  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;

  if (estimations.size() == 0 || estimations.size() != ground_truth.size()) {
    return rmse;
  }

  for (int i = 0; i < estimations.size(); i++) {
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array() * residual.array();
    rmse += residual;
  }

  rmse = rmse / estimations.size();

  return rmse.array().sqrt();

}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  /**
  TODO:
    * Calculate a Jacobian here.
  */

   MatrixXd Hj(3, 4);

   float px = x_state(0);
   float py = x_state(1);
   float vx = x_state(2);
   float vy = x_state(3);

   // division by zero check
   float px_py_2 = pow(px, 2.0) + pow(py, 2.0);

   if (px_py_2 == 0) {
     fprintf(stderr, "Division by zero\n");
     return Hj;
   }

   float sqrt_pxpy2 = sqrt(px_py_2);
   float pxpy_32 = pow(px_py_2, 3.0/2.0);

   Hj << px/sqrt_pxpy2, py/sqrt_pxpy2, 0, 0,
         -1.0 * py/px_py_2, px/px_py_2, 0, 0,
         (py*(vx*py-vy*px))/pxpy_32, (px*(vy*px - vx*py))/pxpy_32, px/sqrt_pxpy2, py/sqrt_pxpy2;

   return Hj;

}
