<!-- <a id="topo"></a> -->
# Hardware (Vivado)

- Projeto: `soma_arrays_50_1600.xpr`
- BD: `Hardware/soma_arrays_50_1600.srcs/sources_1/bd/design_arrays/`
- Constraints: `Hardware/soma_arrays_50_1600.srcs/constrs_1/new/netlist.xdc`

## Arquitetura
![Arquitetura do sistema](../docs/images/arq_viv.png)

SoC baseado em MicroBlaze com um IP HLS de multiplicação de vetores, conectado por AXI a periféricos padrão (ex.: UART, Timer). A integração é feita no BD `design_arrays`.

### Variantes de IP (HLS)
- IPs gerados para tamanhos: 50×50, 100×100, 200×200, 400×400, 800×800, 1600×1600 e uma variante adicional 1000×1000.
- As variantes residem no submódulo `hls/` (não editar aqui). Verifique no Software/README.md para funcionamento dentro da aplicação.
 <!-- O projeto atual utiliza a variante 1600×1600 (drivers e nomes como `xmult_hw_1600` no Software, verifique Software/README.md). -->

## Passos
- Abra o projeto no Vivado (`Hardware/soma_arrays_50_1600.xpr`).
- Execute Synthesis e Implementation.
- Gere o Bitstream.
- Exporte o hardware com bitstream (XSA) para `../Software/platforms/`.

## Observações
- IPs de aceleração vêm do submódulo `hls/`. Ao atualizar um IP, reintegre-o no Vivado e regenere o bitstream.

<!-- [Voltar ao topo](#topo) -->
