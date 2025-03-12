#include "Problem-5.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

double parabola(double x) { return x * x; }
double hyperbole(double x) { return 1 / x; }

bool equal(double a, double b, double precision) {
  return (fabs(a - b) < pow(10, -precision)) ? 1 : 0;
}

void test_parabola() {
  double result = trapeziodal_integration(parabola, 3, 6, 10000);
  double expected = 63;
  assert(equal(result, expected, 6));
}

void test_hyperbole() {
  double result = trapeziodal_integration(hyperbole, 1, 3, 10000);
  double expected = log(3);
  assert(equal(result, expected, 6));
}

void test_sin() {
  double result = trapeziodal_integration(sin, 0, 4, 10000);
  double expected = 3 + cos(4);
  assert(equal(result, expected, 6));
}

void test_sqrt() {
  double result = trapeziodal_integration(sqrt, 6, 13, 1000);
  double expected = (2 * sqrt(pow(13, 3)) - 12 * sqrt(6)) / 3;
  assert(equal(result, expected, 6));
}

int main() {
  test_parabola();
  test_hyperbole();
  test_sin();
  test_sqrt();
  return 0;
}
