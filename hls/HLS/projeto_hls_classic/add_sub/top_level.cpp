#include "operacoes.h"

// Implementação da função principal (top-level)
void top_function(int input_a_soma,   int input_b_soma,
                  int input_a_sub,    int input_b_sub,
                  int* output_soma,   int* output_subtracao) {

    // Chama a função de adição
    *output_soma = adicao(input_a_soma, input_b_soma);

    // Chama a função de subtração
    *output_subtracao = subtracao(input_a_sub, input_b_sub);
}