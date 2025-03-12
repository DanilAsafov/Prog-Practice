#ifndef PROBLEM_4_H
#define PROBLEM_4_H

#include <stddef.h>

typedef struct {
  double *roots;
  size_t count;
} QuadraticSolution;

int sign(double b);
QuadraticSolution solve_quadratic(double a, double b, double c);

#endif // PROBLEM_4_H
