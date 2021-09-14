//
//  main.c
//  Quadratic equation
//
//  Created by Egor Denisov on 11.09.2021.
//
//  Solve quadratic equation with respect to x
//  a * x^2 + b * x + c = 0
//  where a, b, c, x are real (double).
//  Uses discriminant except for exceptions.

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solveQuadraticEquation.h"
#include "RootsNumber.h"


int main() {
    testSolverQuadraticEquation();
    
    printf("Solver of quadratic equation \nax^2 + bx + c = 0\nwith respect to real x\n\n");
    
    double a = 0, b = 0, c = 0;
    printf("Enter real parametrs a, b, c:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    double x1 = 0, x2 = 0;
    RootsNumber rootsNumber = solveQuadraticEquation(a, b, c, &x1, &x2);
    
    printf("\n");
    switch (rootsNumber) {
        case ZERO:
            printf("No roots");
            break;
            
        case ONE:
            printf("Root: %g", x1);
            break;
            
        case TWO:
            printf("Roots: %g, %g", x1, x2);
            break;
            
        case INF:
            printf("Roots: any number");
            break;
            
        default:
            printf("%s ERROR: rootsNumber = %d", __func__, rootsNumber);
    }
    printf("\n\n");
    
    return 0;
}
