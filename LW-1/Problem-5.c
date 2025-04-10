#include "Problem-5.h"
#include <assert.h>
#include <math.h>

#define UNPOSITIVE_NUMBER -1;
#define REVERSED_LIMITS -2;

double trapeziodal_integration(double (*f)(double), double a, double b, int n) {
  if (n < 0) {
    return UNPOSITIVE_NUMBER;
  }
  if (a > b) {
    return REVERSED_LIMITS;
  }
  double h = (b - a) / n;
  double sum = 0.5 * (fabs(f(a)) + fabs(f(b)));
  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    sum += fabs(f(x));
  }

  return sum * h;
}
