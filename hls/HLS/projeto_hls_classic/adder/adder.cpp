#include "adder.h"

void adder(C &c, A a, B b) {
    
    // Diretivas para criar a interface AXI-Lite.
    // O processador irá escrever em 'a' e 'b', e ler de 'c'.
    // O 'return' cria os sinais de controle (start, done, idle).
    // 'bundle=control' agrupa tudo em uma única interface.
    #pragma HLS INTERFACE s_axilite port=a bundle=control
    #pragma HLS INTERFACE s_axilite port=b bundle=control
    #pragma HLS INTERFACE s_axilite port=c bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control

    c = a + b;
}