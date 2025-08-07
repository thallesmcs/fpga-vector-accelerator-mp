// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
// control
// 0x0000 : Control signals
//          bit 0  - ap_start (Read/Write/COH)
//          bit 1  - ap_done (Read/COR)
//          bit 2  - ap_idle (Read)
//          bit 3  - ap_ready (Read/COR)
//          bit 7  - auto_restart (Read/Write)
//          bit 9  - interrupt (Read)
//          others - reserved
// 0x0004 : Global Interrupt Enable Register
//          bit 0  - Global Interrupt Enable (Read/Write)
//          others - reserved
// 0x0008 : IP Interrupt Enable Register (Read/Write)
//          bit 0 - enable ap_done interrupt (Read/Write)
//          bit 1 - enable ap_ready interrupt (Read/Write)
//          others - reserved
// 0x000c : IP Interrupt Status Register (Read/TOW)
//          bit 0 - ap_done (Read/TOW)
//          bit 1 - ap_ready (Read/TOW)
//          others - reserved
// 0x1000 ~
// 0x17ff : Memory 'A' (400 * 32b)
//          Word n : bit [31:0] - A[n]
// 0x2000 ~
// 0x27ff : Memory 'B' (400 * 32b)
//          Word n : bit [31:0] - B[n]
// 0x3000 ~
// 0x37ff : Memory 'C' (400 * 32b)
//          Word n : bit [31:0] - C[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XMULT_HW_400_CONTROL_ADDR_AP_CTRL 0x0000
#define XMULT_HW_400_CONTROL_ADDR_GIE     0x0004
#define XMULT_HW_400_CONTROL_ADDR_IER     0x0008
#define XMULT_HW_400_CONTROL_ADDR_ISR     0x000c
#define XMULT_HW_400_CONTROL_ADDR_A_BASE  0x1000
#define XMULT_HW_400_CONTROL_ADDR_A_HIGH  0x17ff
#define XMULT_HW_400_CONTROL_WIDTH_A      32
#define XMULT_HW_400_CONTROL_DEPTH_A      400
#define XMULT_HW_400_CONTROL_ADDR_B_BASE  0x2000
#define XMULT_HW_400_CONTROL_ADDR_B_HIGH  0x27ff
#define XMULT_HW_400_CONTROL_WIDTH_B      32
#define XMULT_HW_400_CONTROL_DEPTH_B      400
#define XMULT_HW_400_CONTROL_ADDR_C_BASE  0x3000
#define XMULT_HW_400_CONTROL_ADDR_C_HIGH  0x37ff
#define XMULT_HW_400_CONTROL_WIDTH_C      32
#define XMULT_HW_400_CONTROL_DEPTH_C      400

