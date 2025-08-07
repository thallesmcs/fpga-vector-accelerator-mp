// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        bit 9  - interrupt (Read)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (Read/TOW)
//        bit 1 - ap_ready (Read/TOW)
//        others - reserved
// 0x10 : Data signal of input_array
//        bit 31~0 - input_array[31:0] (Read/Write)
// 0x14 : Data signal of input_array
//        bit 31~0 - input_array[63:32] (Read/Write)
// 0x18 : reserved
// 0x20 : Data signal of size
//        bit 31~0 - size[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of sum_result
//        bit 31~0 - sum_result[31:0] (Read)
// 0x2c : Control signal of sum_result
//        bit 0  - sum_result_ap_vld (Read/COR)
//        others - reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XARRAY_SUMMER_CONTROL_ADDR_AP_CTRL          0x00
#define XARRAY_SUMMER_CONTROL_ADDR_GIE              0x04
#define XARRAY_SUMMER_CONTROL_ADDR_IER              0x08
#define XARRAY_SUMMER_CONTROL_ADDR_ISR              0x0c
#define XARRAY_SUMMER_CONTROL_ADDR_INPUT_ARRAY_DATA 0x10
#define XARRAY_SUMMER_CONTROL_BITS_INPUT_ARRAY_DATA 64
#define XARRAY_SUMMER_CONTROL_ADDR_SIZE_DATA        0x20
#define XARRAY_SUMMER_CONTROL_BITS_SIZE_DATA        32
#define XARRAY_SUMMER_CONTROL_ADDR_SUM_RESULT_DATA  0x28
#define XARRAY_SUMMER_CONTROL_BITS_SUM_RESULT_DATA  32
#define XARRAY_SUMMER_CONTROL_ADDR_SUM_RESULT_CTRL  0x2c

