#include "ap_int.h"

void soma(ap_int<7> A, ap_int<7> B, ap_int<8> &C) {
    C = A + B;
}