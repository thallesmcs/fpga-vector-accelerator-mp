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
// 0x0040 ~
// 0x007f : Memory 'A_0' (16 * 32b)
//          Word n : bit [31:0] - A_0[n]
// 0x0080 ~
// 0x00bf : Memory 'A_1' (16 * 32b)
//          Word n : bit [31:0] - A_1[n]
// 0x00c0 ~
// 0x00ff : Memory 'A_2' (16 * 32b)
//          Word n : bit [31:0] - A_2[n]
// 0x0100 ~
// 0x013f : Memory 'A_3' (16 * 32b)
//          Word n : bit [31:0] - A_3[n]
// 0x0140 ~
// 0x017f : Memory 'A_4' (16 * 32b)
//          Word n : bit [31:0] - A_4[n]
// 0x0180 ~
// 0x01bf : Memory 'A_5' (16 * 32b)
//          Word n : bit [31:0] - A_5[n]
// 0x01c0 ~
// 0x01ff : Memory 'A_6' (16 * 32b)
//          Word n : bit [31:0] - A_6[n]
// 0x0200 ~
// 0x023f : Memory 'A_7' (16 * 32b)
//          Word n : bit [31:0] - A_7[n]
// 0x0240 ~
// 0x027f : Memory 'A_8' (16 * 32b)
//          Word n : bit [31:0] - A_8[n]
// 0x0280 ~
// 0x02bf : Memory 'A_9' (16 * 32b)
//          Word n : bit [31:0] - A_9[n]
// 0x02c0 ~
// 0x02ff : Memory 'A_10' (16 * 32b)
//          Word n : bit [31:0] - A_10[n]
// 0x0300 ~
// 0x033f : Memory 'A_11' (16 * 32b)
//          Word n : bit [31:0] - A_11[n]
// 0x0340 ~
// 0x037f : Memory 'A_12' (16 * 32b)
//          Word n : bit [31:0] - A_12[n]
// 0x0380 ~
// 0x03bf : Memory 'A_13' (16 * 32b)
//          Word n : bit [31:0] - A_13[n]
// 0x03c0 ~
// 0x03ff : Memory 'A_14' (16 * 32b)
//          Word n : bit [31:0] - A_14[n]
// 0x0400 ~
// 0x043f : Memory 'A_15' (16 * 32b)
//          Word n : bit [31:0] - A_15[n]
// 0x0440 ~
// 0x047f : Memory 'B_0' (16 * 32b)
//          Word n : bit [31:0] - B_0[n]
// 0x0480 ~
// 0x04bf : Memory 'B_1' (16 * 32b)
//          Word n : bit [31:0] - B_1[n]
// 0x04c0 ~
// 0x04ff : Memory 'B_2' (16 * 32b)
//          Word n : bit [31:0] - B_2[n]
// 0x0500 ~
// 0x053f : Memory 'B_3' (16 * 32b)
//          Word n : bit [31:0] - B_3[n]
// 0x0540 ~
// 0x057f : Memory 'B_4' (16 * 32b)
//          Word n : bit [31:0] - B_4[n]
// 0x0580 ~
// 0x05bf : Memory 'B_5' (16 * 32b)
//          Word n : bit [31:0] - B_5[n]
// 0x05c0 ~
// 0x05ff : Memory 'B_6' (16 * 32b)
//          Word n : bit [31:0] - B_6[n]
// 0x0600 ~
// 0x063f : Memory 'B_7' (16 * 32b)
//          Word n : bit [31:0] - B_7[n]
// 0x0640 ~
// 0x067f : Memory 'B_8' (16 * 32b)
//          Word n : bit [31:0] - B_8[n]
// 0x0680 ~
// 0x06bf : Memory 'B_9' (16 * 32b)
//          Word n : bit [31:0] - B_9[n]
// 0x06c0 ~
// 0x06ff : Memory 'B_10' (16 * 32b)
//          Word n : bit [31:0] - B_10[n]
// 0x0700 ~
// 0x073f : Memory 'B_11' (16 * 32b)
//          Word n : bit [31:0] - B_11[n]
// 0x0740 ~
// 0x077f : Memory 'B_12' (16 * 32b)
//          Word n : bit [31:0] - B_12[n]
// 0x0780 ~
// 0x07bf : Memory 'B_13' (16 * 32b)
//          Word n : bit [31:0] - B_13[n]
// 0x07c0 ~
// 0x07ff : Memory 'B_14' (16 * 32b)
//          Word n : bit [31:0] - B_14[n]
// 0x0800 ~
// 0x083f : Memory 'B_15' (16 * 32b)
//          Word n : bit [31:0] - B_15[n]
// 0x3000 ~
// 0x33ff : Memory 'C' (256 * 32b)
//          Word n : bit [31:0] - C[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XMATRIX_MULT_HW_CONTROL_ADDR_AP_CTRL   0x0000
#define XMATRIX_MULT_HW_CONTROL_ADDR_GIE       0x0004
#define XMATRIX_MULT_HW_CONTROL_ADDR_IER       0x0008
#define XMATRIX_MULT_HW_CONTROL_ADDR_ISR       0x000c
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE  0x0040
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_0_HIGH  0x007f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_0      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_0      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE  0x0080
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_1_HIGH  0x00bf
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_1      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_1      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE  0x00c0
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_2_HIGH  0x00ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_2      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_2      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE  0x0100
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_3_HIGH  0x013f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_3      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_3      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE  0x0140
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_4_HIGH  0x017f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_4      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_4      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE  0x0180
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_5_HIGH  0x01bf
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_5      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_5      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE  0x01c0
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_6_HIGH  0x01ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_6      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_6      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE  0x0200
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_7_HIGH  0x023f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_7      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_7      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE  0x0240
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_8_HIGH  0x027f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_8      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_8      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE  0x0280
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_9_HIGH  0x02bf
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_9      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_9      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE 0x02c0
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_10_HIGH 0x02ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_10     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_10     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE 0x0300
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_11_HIGH 0x033f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_11     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_11     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE 0x0340
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_12_HIGH 0x037f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_12     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_12     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE 0x0380
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_13_HIGH 0x03bf
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_13     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_13     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE 0x03c0
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_14_HIGH 0x03ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_14     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_14     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE 0x0400
#define XMATRIX_MULT_HW_CONTROL_ADDR_A_15_HIGH 0x043f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_A_15     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_A_15     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE  0x0440
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_0_HIGH  0x047f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_0      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_0      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE  0x0480
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_1_HIGH  0x04bf
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_1      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_1      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE  0x04c0
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_2_HIGH  0x04ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_2      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_2      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE  0x0500
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_3_HIGH  0x053f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_3      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_3      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE  0x0540
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_4_HIGH  0x057f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_4      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_4      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE  0x0580
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_5_HIGH  0x05bf
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_5      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_5      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE  0x05c0
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_6_HIGH  0x05ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_6      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_6      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE  0x0600
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_7_HIGH  0x063f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_7      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_7      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE  0x0640
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_8_HIGH  0x067f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_8      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_8      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE  0x0680
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_9_HIGH  0x06bf
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_9      32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_9      16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE 0x06c0
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_10_HIGH 0x06ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_10     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_10     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE 0x0700
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_11_HIGH 0x073f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_11     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_11     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE 0x0740
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_12_HIGH 0x077f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_12     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_12     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE 0x0780
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_13_HIGH 0x07bf
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_13     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_13     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE 0x07c0
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_14_HIGH 0x07ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_14     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_14     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE 0x0800
#define XMATRIX_MULT_HW_CONTROL_ADDR_B_15_HIGH 0x083f
#define XMATRIX_MULT_HW_CONTROL_WIDTH_B_15     32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_B_15     16
#define XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE    0x3000
#define XMATRIX_MULT_HW_CONTROL_ADDR_C_HIGH    0x33ff
#define XMATRIX_MULT_HW_CONTROL_WIDTH_C        32
#define XMATRIX_MULT_HW_CONTROL_DEPTH_C        256

