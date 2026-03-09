//
// 
//

#include "sigmoid.h"

// Your code goes here
double sigmoid::eval(double x ){
    return 1/(1+exp(-x));
}