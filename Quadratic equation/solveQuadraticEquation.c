//
//  solveQuadraticEquation.c
//  Quadratic equation
//
//  Created by Egor Denisov on 14.09.2021.
//

#include "solveQuadraticEquation.h"

RootsNumber solveQuadraticEquation(double a, double b, double c,
                                   double * x1, double * x2) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                *x1 = 0;
                *x2 = 0;
                return INF;
            } else {
                return ZERO;
            }
        } else {
            *x1 = - c / b;
            *x2 = *x1;
            return ONE;
        }
    }
    
    double d = b * b - 4 * a * c;
    
    if (d < 0) {
        return ZERO;
    }
    
    double dSqrt = sqrt(d);
    *x1 = (-b + dSqrt) / (2 * a);
    *x2 = (-b - dSqrt) / (2 * a);
    
    return *x1 == *x2 ? ONE : TWO;
}


void testSolverQuadraticEquation() {
    double x1 = 0, x2 = 0;
    RootsNumber rootsNumber = ZERO;
    
    double a[][3] = {
        {1, 0, 0},
        {0, 0, 0},
        {1, 2, 1},
        {1, -2, 1},
        {1, 1, 1},
        {1, -5, 6},
        {1, -5, 6},
    };
    double x[][2] = {
        {0, 0},
        {0, 0},
        {-1, -1},
        {1, 1},
        {0, 0},
        {2, 3},
        {3, 2}
    };
    RootsNumber rootsNumbers[] = {ONE, INF, ONE, ONE, ZERO, TWO, TWO};
    
    const int n = sizeof(a) / (sizeof(double) * 3);
    {
        const int xLength = sizeof(x) / (sizeof(double) * 2);
        const int rootsNumbersLength = sizeof(rootsNumbers) / sizeof(RootsNumber);
        assert(n == xLength);
        assert(n == rootsNumbersLength);
    }
    
    for (int i = 0; i < n; i++) {
        x1 = 0;
        x2 = 0;
        rootsNumber = solveQuadraticEquation(a[i][0], a[i][1], a[i][2], &x1, &x2);
        
        assert(rootsNumber == rootsNumbers[i]);
        assert((x1 == x[i][0] && x2 == x[i][1]) ||
               (x2 == x[i][0] && x1 == x[i][1]));
    }
}
