#include "matrix_mult_ip.h"

// Definição dos endereços base para cada memória interna da IP.
// Deixa espaço para os registradores de controle (0x00 a 0xFFF).
// #define A_ADDR_OFFSET 0x1000
// #define B_ADDR_OFFSET 0x2000
#define C_ADDR_OFFSET 0x3000

// ===================================================================================
// Função Top-Level: matrix_mult_hw
// Esta função será convertida em hardware pela síntese de alto nível.
// ===================================================================================
void matrix_mult_hw(int A[MATRIX_SIZE][MATRIX_SIZE], int B[MATRIX_SIZE][MATRIX_SIZE], int C[MATRIX_SIZE][MATRIX_SIZE]) {

    // -------------------------------------------------------------------------------
    // DIRETIVAS DE INTERFACE
    // Define como a IP se comunica com o processador.
    // -------------------------------------------------------------------------------
    // Define uma interface AXI-Lite para controle e para acesso aos dados das matrizes.
    // Os 'offsets' fixam o mapa de memória.
    #pragma HLS INTERFACE s_axilite port=A 
    #pragma HLS INTERFACE s_axilite port=B 
    #pragma HLS INTERFACE s_axilite port=C offset=C_ADDR_OFFSET
    #pragma HLS INTERFACE s_axilite port=return

    // -------------------------------------------------------------------------------
    // DIRETIVAS DE OTIMIZAÇÃO DE MEMÓRIA
    // Resolvem o gargalo de acesso à memória para permitir paralelismo total.
    // -------------------------------------------------------------------------------
    // Particiona os arrays 'A' e 'B' em memórias menores e independentes para
    // permitir leituras paralelas e atender à demanda do loop com UNROLL.
    #pragma HLS ARRAY_PARTITION variable=A complete dim=2
    #pragma HLS ARRAY_PARTITION variable=B complete dim=1

    // -------------------------------------------------------------------------------
    // LÓGICA DA MULTIPLICAÇÃO COM OTIMIZAÇÃO DE PERFORMANCE
    // -------------------------------------------------------------------------------
    ROW_LOOP: for (int i = 0; i < MATRIX_SIZE; i++) {
        COL_LOOP: for (int j = 0; j < MATRIX_SIZE; j++) {
            // PIPELINE: Permite que as iterações deste loop sejam sobrepostas,
            // aumentando a vazão e permitindo que um novo cálculo comece a cada ciclo.
            #pragma HLS PIPELINE II=1

            int sum = 0;
            SUM_LOOP: for (int k = 0; k < MATRIX_SIZE; k++) {
                // UNROLL: Desdobra este loop, criando 16 unidades de cálculo que
                // operam em paralelo para calcular a soma em poucos ciclos.
                #pragma HLS UNROLL

                // BIND_OP: Garante que a operação de multiplicação seja implementada
                // nos blocos de hardware DSP, que são rápidos e eficientes.
                #pragma HLS BIND_OP variable=sum op=mul impl=dsp

                // Lógica de multiplicação de matriz padrão e corrigida.
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}