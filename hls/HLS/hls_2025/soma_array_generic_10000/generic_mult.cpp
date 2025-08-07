// Definição dos endereços base para cada memória interna da IP.
// Deixa espaço para os registradores de controle (0x00 a 0xFFF).
// #define A_ADDR_OFFSET 0x1000
// #define B_ADDR_OFFSET 0x2000
//#define C_ADDR_OFFSET 0x3000
#define data_max 10000

void generic_10000(int A[data_max], int B[data_max], int C[data_max]) {


    #pragma HLS INTERFACE s_axilite port=A 
    #pragma HLS INTERFACE s_axilite port=B 
    #pragma HLS INTERFACE s_axilite port=C
    #pragma HLS INTERFACE s_axilite port=return
    //#pragma HLS INTERFACE s_axilite port=size offset= 0x20

    #pragma HLS ARRAY_PARTITION variable=A complete dim=1
    #pragma HLS ARRAY_PARTITION variable=B complete dim=1


    ROW_LOOP: for (int i = 0; i < data_max; i++) {

        #pragma HLS PIPELINE II=1

            C[i] = A[i] * B[i];
            }

}