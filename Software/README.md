# Software (MicroBlaze + Vitis 2025.1)

Este diretório contém os componentes de software necessários para compilar e executar um teste de validação no acelerador de hardware.

## Estrutura do Diretório

- `platforms/`: Contém a definição da plataforma de hardware (`.xsa`) exportada do projeto Vivado.
- `soma_arrays_50_1600_app/`: Contém a aplicação de teste em C desenvolvida para rodar no processador MicroBlaze.

## Guia Rápido de Execução

Para compilar e executar a aplicação de teste no Vitis IDE, siga estes passos:

1.  **Pré-requisito:** Certifique-se de que o arquivo `.xsa` gerado pelo Vivado (com bitstream incluso) está localizado no diretório `platforms/`.

2.  **Criar Plataforma:** No Vitis, crie um novo **Projeto de Plataforma (Platform Project)** utilizando o arquivo `.xsa` como base.

3.  **Criar Aplicação:** Crie ou importe um **Projeto de Aplicação (Application Project)** a partir do código-fonte localizado em `soma_arrays_50_1600_app/`. Associe esta aplicação à plataforma criada no passo anterior.

4.  **Compilar e Executar:** Compile (Build) o projeto e execute-o no hardware alvo (Run as -> Launch Hardware). Monitore a saída na console serial (UART).

## Detalhes da Aplicação

Para informações detalhadas sobre a lógica da aplicação, configurações de compilação e análise dos resultados, consulte o README específico:

**Consulte o arquivo `soma_arrays_50_1600_app/README.md`**