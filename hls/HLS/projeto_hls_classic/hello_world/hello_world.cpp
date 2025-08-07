#include "hello_world.h"

void hello_world(int valor, char mensagem[100]) {
    if (valor == 1) {
        const char texto[] = "Hello, World!";
        int i = 0;
        while (texto[i] != '\0') {
            mensagem[i] = texto[i];
            i++;
        }
        mensagem[i] = '\0';  
    } else {
        mensagem[0] = '\0';  
    }
}
