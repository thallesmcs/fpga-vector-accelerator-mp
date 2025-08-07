#include <stdio.h>
#include <xparameters.h>
#include "platform.h"
#include "xil_printf.h"
#include "xtmrctr.h"
#include "xmult_hw_1600.h" // Driver da IP

// ===================================================================================
// Constantes e Instâncias Globais
// ===================================================================================
#define MATRIX_SIZE 10

XMult_hw_1600 hw_ip;
XTmrCtr timer_dev;

static int A[MATRIX_SIZE];
static int B[MATRIX_SIZE];
static int C_sw[MATRIX_SIZE];
static int C_hw[MATRIX_SIZE];

// ===================================================================================
// Funções de Apoio (matrix_mult_sw e verify_results como antes)
// ===================================================================================
void mult_sw(int mat_a[MATRIX_SIZE], int mat_b[MATRIX_SIZE], int mat_c[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
                mat_c[i] = mat_a[i] * mat_b[i];
            }
        }
    

// void print_vector(const char* name, int vec[], int size) {
//     xil_printf("--- Conteudo do Vetor %s ---\r\n", name);
//     for (int i = 0; i < size; i++) {
//         xil_printf("%s[%d] = %d\r\n", name, i, vec[i]);
//     }
//     xil_printf("----------------------------------\r\n\n");
// }


// ===================================================================================
// Função Principal (main)
// ===================================================================================
int main() {
    init_platform();

    xil_printf("--- Inicio do Teste de Aceleração de Multiplicacao de Matriz ---\n\r");

    xil_printf("\n");

    xil_printf("Tamanho do array: %d \n", MATRIX_SIZE);

    xil_printf("\n");


    XMult_hw_1600_Initialize(&hw_ip, XPAR_MULT_HW_1600_0_BASEADDR);
    XTmrCtr_Initialize(&timer_dev, XPAR_XTMRCTR_0_BASEADDR);


    for(int i = 0; i < MATRIX_SIZE; i++) {

            A[i] = i + i;
            B[i] = i + i;
        
    }

    xil_printf("Executando multiplicacao em Software...\n\r");
    XTmrCtr_Start(&timer_dev, 0);
    u32 start_time_sw = XTmrCtr_GetValue(&timer_dev, 0);
    mult_sw(A, B, C_sw);
    u32 stop_time_sw = XTmrCtr_GetValue(&timer_dev, 0);
    u32 software_time = stop_time_sw - start_time_sw;
    XTmrCtr_Stop(&timer_dev, 0);
    XTmrCtr_Reset(&timer_dev, 0);


    xil_printf("Executando multiplicacao em Hardware...\n\r");

    XMult_hw_1600_Write_A_Words(&hw_ip, 0, (unsigned int*)A, MATRIX_SIZE);  
    XMult_hw_1600_Write_B_Words(&hw_ip, 0, (unsigned int*)B, MATRIX_SIZE);


    // 3.2 Inicia a IP e mede o tempo de execução do núcleo
    XTmrCtr_Start(&timer_dev, 0);
    u32 start_time_hw = XTmrCtr_GetValue(&timer_dev, 0);
    XMult_hw_1600_Start(&hw_ip);
    while (!XMult_hw_1600_IsDone(&hw_ip));
    u32 stop_time_hw = XTmrCtr_GetValue(&timer_dev, 0);
    u32 hardware_time = stop_time_hw - start_time_hw;
    XTmrCtr_Stop(&timer_dev, 0);

    XMult_hw_1600_Read_C_Words(&hw_ip, 0, (unsigned int*)C_hw, MATRIX_SIZE);

    xil_printf("\n");


    xil_printf("--- Analise de Performance ---\n\r");
    xil_printf("Tempo de execucao em Software: %d ciclos de clock\n\r", software_time);
    xil_printf("Tempo de execucao em Hardware: %d ciclos de clock\n\r", hardware_time);
    float speedup = (float)software_time / (float)hardware_time;
    printf("Speedup (Software / Hardware) = %.2fx\n\r", speedup);
    xil_printf("--------------------------------\n\r");

    xil_printf("\n");

    // #define PRINT_SAMPLE_SIZE 50

    // xil_printf("====================================================\r\n");
    // xil_printf("Amostra Final dos Vetores (primeiros %d elementos)\r\n", PRINT_SAMPLE_SIZE);
    // xil_printf("====================================================\r\n");

    // // Assumindo que a função print_vector já existe no seu código
    // // print_vector("Entrada A", A, PRINT_SAMPLE_SIZE);
    // // print_vector("Entrada B", B, PRINT_SAMPLE_SIZE);
    // print_vector("Saida SW ", C_sw, PRINT_SAMPLE_SIZE);
    // print_vector("Saida HW ", C_hw, PRINT_SAMPLE_SIZE);


    xil_printf("Teste concluido.\r\n");

    cleanup_platform();
    return 0;
}