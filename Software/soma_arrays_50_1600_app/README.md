### Aplicação: Teste do Acelerador de Vetores

#### Objetivo

Esta aplicação em C verifica o funcionamento do acelerador de hardware para multiplicação de vetores. Ela inicializa vetores, envia os ponteiros para o IP de HLS, inicia a aceleração e compara o resultado com uma multiplicação feita por software. 

#### Dependências de Hardware

-   **Processador:** Esta aplicação foi desenvolvida para rodar em um processador **Microblaze**.
-   **Acelerador:** Requer que o design de hardware contenha o IP de multiplicação de vetores gerado pelo HLS.

#### Plataforma Alvo

Esta aplicação foi testada com a definição de hardware localizada em:
`../../platforms/soma_arrays_50_1600/design_arrays_wrapper.xsa`

## Obs:

O código da aplicação utiliza um endereçamento exclusivo para cada IP. Portanto, para utilizar outro IP, é necessário modificar os endereços correspondentes no código.