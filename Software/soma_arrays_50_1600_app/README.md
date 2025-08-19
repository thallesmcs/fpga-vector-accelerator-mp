### Aplicação: Teste do Acelerador de Vetores

#### Objetivo

Esta aplicação em C verifica o funcionamento do acelerador de hardware para multiplicação de vetores. Ela inicializa vetores, envia os ponteiros para o IP de HLS, inicia a aceleração e compara o resultado com uma multiplicação feita por software. 

Para alterar o IP utilizado na aplicação, é necessário modificar o driver do IP. Por exemplo, para um IP de 1600x1600, o driver é "xmult_hw_1600.h". Além disso, os ponteiros no código também devem ser ajustados para o IP selecionado.

#### Exemplo de Migração: Adaptando o Código do IP 1600x1600 para 800x800

Para utilizar a versão do IP com matrizes 800x800, é necessário atualizar as chamadas do driver, conforme mostrado abaixo.

**Código Anterior (para IP 1600x1600)**
```c
#include "xmult_hw_1600.h" // Driver para IP de 1600x1600

XMult_hw_1600 hw_ip; // Instância da IP

XMult_hw_1600_Initialize(&hw_ip, XPAR_MULT_HW_1600_0_BASEADDR); // Inicialização da IP

XMult_hw_1600_Write_A_Words(&hw_ip, 0, (unsigned int*)A, MATRIX_SIZE); // Escrita de dados
```

**Código Novo (para IP 800x800)**
```c
#include "xmult_hw_800.h" // Driver para IP de 800x800

XMult_hw_800 hw_ip; // Nova instância da IP

XMult_hw_800_Initialize(&hw_ip, XPAR_MULT_HW_800_0_BASEADDR); // Nova inicialização

XMult_hw_800_Write_A_Words(&hw_ip, 0, (unsigned int*)A, MATRIX_SIZE); // Nova escrita de dados
```

**Nota Importante:** A mudança não se resume apenas a estes trechos. Lembre-se de atualizar todas as funções relacionadas ao driver, bem como constantes de tamanho de matriz (`MATRIX_SIZE`) e configurações de alocação de memória em todo o projeto.

#### Dependências de Hardware

-   **Processador:** Esta aplicação foi desenvolvida para rodar em um processador **Microblaze**.
-   **Acelerador:** Requer que o design de hardware contenha o IP de multiplicação de vetores gerado pelo HLS.
-   **AXI Timer:** Esta aplicação utiliza IP aberta da xilinx para comparar o tempo de execução.

#### Plataforma Alvo

Esta aplicação foi testada com a definição de hardware localizada em:
`../../platforms/design_arrays_wrapper.xsa`

Abra no Vitis (2025.1 ou compatível), selecione a plataforma `.xsa` acima, compile e execute no MicroBlaze.