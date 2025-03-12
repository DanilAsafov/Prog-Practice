#include "Problem-4.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int equal(double a, double b, int precision) {
  return fabs(a - b) < pow(10, -precision);
}

int check_roots(QuadraticSolution result, QuadraticSolution expected,
                int precision) {
  if (result.count != expected.count) {
    printf("Expected %zu roots, got %zu\n", expected.count, result.count);
    return 0;
  }
  for (int i = 0; i < expected.count; i++) {
    if (!equal(result.roots[i], expected.roots[i], precision)) {
      printf("Root %d: expected %.10f, got %.10f\n", i, expected.roots[i],
             result.roots[i]);
      return 0;
    }
  }
  return 1;
}

void test_1() {
  QuadraticSolution result = solve_quadratic(0, 1, 1);
  assert(result.count == 0);
  free(result.roots);
}

void test_2() {
  QuadraticSolution result = solve_quadratic(1, 0, -1);
  assert(result.count == 2);
  QuadraticSolution expected = {(double[]){-1, 1}, 2};
  assert(check_roots(result, expected, 4));
  free(result.roots);
}

void test_3() {
  QuadraticSolution result = solve_quadratic(1, 0, 0);
  assert(result.count == 1);
  QuadraticSolution expected = {(double[]){0}, 1};
  assert(check_roots(result, expected, 7));
  free(result.roots);
}

void test_4() {
  QuadraticSolution result = solve_quadratic(1, 0, 1);
  assert(result.count == 0);
  free(result.roots);
}

void test_5() {
  QuadraticSolution result = solve_quadratic(1, 0, -1e-7);
  assert(result.count == 2);
  QuadraticSolution expected = {(double[]){-3e-4, 3e-4}, 2};
  assert(check_roots(result, expected, 4));
  free(result.roots);
}

void test_6() {
  QuadraticSolution result = solve_quadratic(1, -1e10, -1);
  assert(result.count == 2);
  QuadraticSolution expected = {(double[]){-1e-10, 1e10}, 2};
  assert(check_roots(result, expected, 11));
  free(result.roots);
}

void test_7() {
  QuadraticSolution result = solve_quadratic(1, 0, -1e-8);
  assert(result.count == 1);
  QuadraticSolution expected = {(double[]){0}, 1};
  assert(check_roots(result, expected, 7));
  free(result.roots);
}

int main() {
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  test_7();

  return 0;
}
