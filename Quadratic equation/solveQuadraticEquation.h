//
//  solveQuadraticEquation.h
//  Quadratic equation
//
//  Created by Egor Denisov on 14.09.2021.
//

#ifndef solveQuadraticEquation_h
#define solveQuadraticEquation_h

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "RootsNumber.h"

RootsNumber solveQuadraticEquation(double a, double b, double c,
                                   double * x1, double * x2);

void testSolverQuadraticEquation(void);

#endif /* solveQuadraticEquation_h */
