#include <fstream>
#include <iostream>
#include <cstring>
#include "hello_world.h"

using namespace std;

int main() {
    char mensagem[100];

    // Teste com o valor correto
    hello_world(1, mensagem);

    // Grava o resultado em um arquivo
    ofstream FILE("result.dat");
    FILE << mensagem << endl;
    FILE.close();

    // Compara com o arquivo esperado
    int retval = system("diff --brief -w result.dat result.golden.dat");

    if (retval != 0) {
        printf("Test failed  !!!\n");
        retval = 1;
    } else {
        printf("Test passed !\n");
    }

    return retval;
}
