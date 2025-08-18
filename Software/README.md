<!-- <a id="topo"></a> -->
# Software (MicroBlaze + Vitis 2025.1)

- `platforms/`: coloque aqui o `.xsa` exportado do Vivado.
- `soma_arrays_50_1600_app/`: aplicação de teste para MicroBlaze (logs via UART).
	- Veja `soma_arrays_50_1600_app/README.md` para detalhes.

## No Vitis
- Crie uma plataforma a partir do `.xsa` em `platforms/`.
- Crie ou importe a aplicação em `soma_arrays_50_1600_app/`.
- Compile e execute na placa; monitore a UART.
<!-- 
[Voltar ao topo](#topo) -->
