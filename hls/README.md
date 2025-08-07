# Projetos de Sistemas Embarcados com Vitis e HLS

## Descrição

Este repositório contém uma coleção de projetos de Sistemas em Chip (SoC) para FPGAs da Xilinx. Cada projeto integra um processador soft-core Microblaze com aceleradores de hardware customizados, desenvolvidos utilizando High-Level Synthesis (HLS).

## Estrutura do Repositório

O projeto é organizado da seguinte forma para manter uma clara separação entre hardware, software e IPs de HLS:

- **/hardware**: Contém os projetos de hardware do Vivado. Cada subpasta é um projeto completo. Acompanhe os Readme dentro de cada hardware com uma breve explicação dentro do funcionamento.
  - `acel_matrizes/`: Projeto que integra um acelerador de multiplicação de matrizes com IP fixa de 16x16.
  - `soma_arrays_50_1600/`: Projeto que integra um acelerador de soma de vetores, com IPs fixas do tamanho dos vetores.

- **/hls**: Contém os projetos HLS que geram os IPs de aceleração utilizados nos projetos de hardware.

- **/software**: Contém o código embarcado e as plataformas de hardware.
  - `platforms/`: Definições de hardware exportadas do Vivado (`.xsa`), uma para cada projeto de hardware.
  - `apps/`: Aplicações em C/C++ para rodar no Microblaze. Cada subpasta é um projeto de aplicação testado.
  - `lib_c/`: Biblioteca de código C comum e funções reutilizáveis.

## Ferramentas Utilizadas

* **Vivado/Vitis:** 2025.1, 2024.1 e Classic
* **Target FPGA:** Xilinx Spartan-7 XC7S50-CSGA324 FPGA

<!-- ## Como Começar

1.  Clone o repositório.
2.  Escolha um projeto de hardware em `/hardware`.
3.  Exporte o hardware (`.xsa`) para a pasta correspondente em `/software/platforms`.
4.  No Vitis, crie um novo workspace e uma aplicação usando a plataforma exportada e o código fonte de `/software/apps`. -->