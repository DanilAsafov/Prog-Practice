#include "Problem-4.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int sign(double b) { return (b > 0) ? -1 : 1; }

QuadraticSolution solve_quadratic(double a, double b, double c) {
  QuadraticSolution result = {NULL, 0};
  if (a == 0) {
    return result;
  }

  double eps = 1e-7;
  double D = b * b - 4 * a * c;
  if (D < -eps) {
    return result;
  }
  if (!(D > eps)) {
    result.count = 1;
    result.roots = malloc(sizeof(double));
    result.roots[0] = -b / (2 * a);
    return result;
  }
  result.count = 2;
  result.roots = malloc(2 * sizeof(double));
  result.roots[0] = (-b + sign(b) * sqrt(D)) / (2 * a);
  result.roots[1] = c / (a * result.roots[0]);
  if (result.roots[0] > result.roots[1]) {
    double temp = result.roots[0];
    result.roots[0] = result.roots[1];
    result.roots[1] = temp;
  }
  return result;
}
