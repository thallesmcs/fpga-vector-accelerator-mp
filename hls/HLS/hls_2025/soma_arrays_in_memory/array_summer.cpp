#include "ap_int.h"

// A função principal do nosso hardware
void array_summer(int *input_array, int *sum_result, int size) {
    // Diretivas para o Vitis HLS saber como criar as interfaces
    #pragma HLS INTERFACE m_axi     port=input_array offset=slave bundle=gmem0
    #pragma HLS INTERFACE s_axilite port=input_array bundle=control offset = 0x10
    #pragma HLS INTERFACE s_axilite port=sum_result bundle=control offset = 0x28
    #pragma HLS INTERFACE s_axilite port=size       bundle=control offset = 0x20
    #pragma HLS INTERFACE s_axilite port=return     bundle=control offset = 0x00

    int accumulator = 0;

    // O hardware vai executar este loop de forma ultra-otimizada
    SUM_LOOP: for (int i = 0; i < size; i++) {
        #pragma HLS PIPELINE
        accumulator += input_array[i];
    }

    // Escreve o resultado final no registrador de saída
    *sum_result = accumulator;
}