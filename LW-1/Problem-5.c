#include "Problem-5.h"
#include <assert.h>
#include <math.h>

double trapeziodal_integration(double (*f)(double), double a, double b, int n) {
  assert(n > 0 && "Number of intervals must be positive");
  assert(a <= b && "Integration limits are reversed");

  double h = (b - a) / n;
  double sum = 0.5 * (fabs(f(a)) + fabs(f(b)));
  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    sum += fabs(f(x));
  }

  return sum * h;
}
