#ifndef _adder_H_
#define _adder_H_

#include <fstream>
#include <iostream>
// using namespace std;

#include "ap_int.h"
#define N 8

typedef ap_int<N> A;
typedef ap_int<N> B;
typedef ap_int<N> C;

void adder(C &c, A a, B b);

// void adder(ap_int<7> A, ap_int<7> B, ap_int<8> &C);

#endif
