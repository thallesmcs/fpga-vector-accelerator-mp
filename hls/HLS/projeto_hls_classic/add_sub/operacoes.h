#ifndef OPERACOES_H
#define OPERACOES_H

// Declaração da função de adição
int adicao(int a, int b);

// Declaração da função de subtração
int subtracao(int a, int b);

// Declaração da função principal (top-level) para Vitis HLS
// Esta função chamará adicao e subtracao
// Usamos ponteiros para as saídas, como é comum em HLS
void top_function(int input_a_soma,   int input_b_soma,
                  int input_a_sub,    int input_b_sub,
                  int* output_soma,   int* output_subtracao);

#endif // OPERACOES_H