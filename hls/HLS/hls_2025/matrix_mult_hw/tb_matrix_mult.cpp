#include <iostream>
#include <iomanip> // Para formatação da saída
#include "matrix_mult_ip.h" // Inclui a declaração da sua função de HW e MATRIX_SIZE

// Função de referência em software para calcular o resultado esperado.
// É crucial que esta função esteja 100% correta.
void matrix_mult_sw_reference(int A[MATRIX_SIZE][MATRIX_SIZE], int B[MATRIX_SIZE][MATRIX_SIZE], int C[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Declaração das matrizes para o teste
    static int A[MATRIX_SIZE][MATRIX_SIZE];
    static int B[MATRIX_SIZE][MATRIX_SIZE];
    static int C_hw[MATRIX_SIZE][MATRIX_SIZE];      // Matriz de resultado do Hardware (Design Under Test)
    static int C_sw[MATRIX_SIZE][MATRIX_SIZE];      // Matriz de resultado do Software (Referência)

    int error_count = 0;

    // 1. Inicializa as matrizes de entrada com dados de exemplo
    std::cout << "INFO: Inicializando matrizes de entrada..." << std::endl;
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    // 2. Chama a função a ser sintetizada (seu design em hardware)
    std::cout << "INFO: Executando a função de hardware (DUT)..." << std::endl;
    matrix_mult_hw(A, B, C_hw);

    // 3. Chama a função de software de referência para obter o resultado esperado
    std::cout << "INFO: Executando a função de software de referência..." << std::endl;
    matrix_mult_sw_reference(A, B, C_sw);

    // 4. Compara o resultado do hardware com o resultado da referência
    std::cout << "INFO: Comparando o resultado do DUT com a referência..." << std::endl;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (C_hw[i][j] != C_sw[i][j]) {
                error_count++;
                // Imprime o primeiro erro encontrado para facilitar a depuração
                if (error_count == 1) {
                    std::cout << "ERROR: Discrepância encontrada em C[" << i << "][" << j << "]: "
                              << "Hardware=" << C_hw[i][j] << ", Software=" << C_sw[i][j] << std::endl;
                }
            }
        }
    }

    // 5. Imprime o status final do teste
    if (error_count == 0) {
        std::cout << "=====================================================================" << std::endl;
        // A mensagem "PASS" é frequentemente usada por scripts de automação
        std::cout << "INFO: Teste passou! (PASS)" << std::endl;
        std::cout << "=====================================================================" << std::endl;
        return 0; // Retorna 0 para indicar sucesso ao Vitis HLS
    } else {
        std::cout << "=====================================================================" << std::endl;
        // A mensagem "FAIL" é frequentemente usada por scripts de automação
        std::cout << "ERROR: Teste falhou! (FAIL)" << std::endl;
        std::cout << "Total de erros encontrados: " << error_count << std::endl;
        std::cout << "=====================================================================" << std::endl;
        return 1; // Retorna um valor diferente de 0 para indicar falha ao Vitis HLS
    }
}